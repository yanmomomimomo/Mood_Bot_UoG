#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include "libcam2opencv.h"
// 使用正确的头文件路径
#include "/home/mood/libcamera2opencv/libcam2opencv.h"

// object-detection-tnn-sdk 头文件
#include "object_detection.h"
#include "classification.h"
#include "file_utils.h"
#include "image_utils.h"

using namespace dl;
using namespace vision;
using namespace std;

// 用于显示图像的全局变量
cv::Mat currentFrame;
bool hasNewFrame = false;

// TNN模型相关参数
const int num_thread = 1; // 线程数
DeviceType device = CPU;  // 使用CPU推理
// 人脸检测模型
const char *det_model_file = (char *) "/home/mood/object-detection-tnn-sdk/data/tnn/face/rfb-face-mask-320-320_sim.opt.tnnmodel";
const char *det_proto_file = (char *) "/home/mood/object-detection-tnn-sdk/data/tnn/face/rfb-face-mask-320-320_sim.opt.tnnproto";
ObjectDetectionParam model_param = FACE_MODEL; // 使用人脸检测模型参数

// 表情识别模型
const char *emo_model_file = (char *) "/home/mood/object-detection-tnn-sdk/data/tnn/emotion/mobilenet_v2_112_112.tnnmodel";
const char *emo_proto_file = (char *) "/home/mood/object-detection-tnn-sdk/data/tnn/emotion/mobilenet_v2_112_112.tnnproto";
ClassificationParam emotion_param = EMOTION_MODEL; // 使用表情识别模型参数

// 设置检测阈值
const float scoreThresh = 0.5; // 置信度阈值
const float iouThresh = 0.3;   // NMS阈值

// 人脸检测对象
ObjectDetection *detector = nullptr;
// 表情识别对象
Classification *emotionClassifier = nullptr;

// 控制检测频率
int processEveryNFrames = 5;
int frameCount = 0;

// 存储最近一次检测结果
FrameInfo lastResultInfo;
bool hasDetectionResult = false;

// 回调结构体
struct MyCallback : public Libcam2OpenCV::Callback {
    void hasFrame(const cv::Mat &frame, const libcamera::ControlList &metadata) override {
        if (!frame.empty()) {
            std::lock_guard<std::mutex> lock(frameMutex);
            frame.copyTo(currentFrame);
            hasNewFrame = true;
        }
    }
    std::mutex frameMutex;
};

// 计算并绘制人脸中心点和表情
void drawFaceCenters(cv::Mat &frame, const FrameInfo &resultInfo) {
    for (size_t i = 0; i < resultInfo.info.size(); i++) {
        const ObjectInfo &info = resultInfo.info[i];
        
        // 计算中心点坐标（使用x1,y1,x2,y2）
        int centerX = static_cast<int>((info.x1 + info.x2) / 2);
        int centerY = static_cast<int>((info.y1 + info.y2) / 2);
        
        // 在图像上绘制中心点
        cv::circle(frame, cv::Point(centerX, centerY), 3, cv::Scalar(0, 255, 0), -1);
        
        // 显示中心点坐标在人脸框的下方
        std::string centerText = "Center: (" + std::to_string(centerX) + "," + std::to_string(centerY) + ")";
        
        // 在人脸框下方显示坐标
        int textX = static_cast<int>(info.x1);
        int textY = static_cast<int>(info.y2) + 20; // 放在框的下方20像素处
        
        // 绘制背景矩形使文字更清晰
        cv::Size textSize = cv::getTextSize(centerText, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, nullptr);
        cv::rectangle(frame, 
                     cv::Point(textX - 2, textY - textSize.height - 2),
                     cv::Point(textX + textSize.width + 2, textY + 2),
                     cv::Scalar(0, 0, 0), -1);
        
        // 绘制文字
        cv::putText(frame, centerText, cv::Point(textX, textY),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1);
        
        // 如果有表情识别结果，显示表情
        if (info.category.label >= 0 && 
            info.category.label < static_cast<int>(emotion_param.class_names.size())) {
            
            std::string emotionText = "Emotion: " + emotion_param.class_names[info.category.label] + 
                                     " (" + std::to_string(static_cast<int>(info.category.score * 100)) + "%)";
            
            // 在坐标下方显示表情
            int emoTextY = textY + 20; // 在坐标下方再加20像素
            
            // 绘制背景矩形
            cv::Size emoTextSize = cv::getTextSize(emotionText, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, nullptr);
            cv::rectangle(frame, 
                         cv::Point(textX - 2, emoTextY - emoTextSize.height - 2),
                         cv::Point(textX + emoTextSize.width + 2, emoTextY + 2),
                         cv::Scalar(0, 0, 0), -1);
            
            // 绘制表情文字，使用不同颜色
            cv::putText(frame, emotionText, cv::Point(textX, emoTextY),
                        cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 255), 1);
        }
    }
}

// 对检测到的人脸进行表情识别
void processEmotions(cv::Mat &frame, FrameInfo *frameInfo) {
    if (frameInfo->info.empty() || !emotionClassifier) {
        std::cout << "无法进行表情识别：没有人脸或分类器未初始化" << std::endl;
        return; // 没有检测到人脸或表情分类器未初始化
    }
    
    std::cout << "直接对整个FrameInfo进行表情分类..." << std::endl;
    
    // 重要的变化：直接将frameInfo传递给分类器，而不是创建新的临时结构
    // 参考main.cpp中的方法：classifier->detect(frame, &resultInfo);
    emotionClassifier->detect(frame, frameInfo);
    
    // 输出分类结果
    for (size_t i = 0; i < frameInfo->info.size(); i++) {
        ObjectInfo &faceInfo = frameInfo->info[i];
        if (faceInfo.category.label >= 0 && 
            faceInfo.category.label < static_cast<int>(emotion_param.class_names.size())) {
            
            std::cout << "人脸 #" << i + 1 << " 识别到表情: " 
                      << emotion_param.class_names[faceInfo.category.label]
                      << " (索引:" << faceInfo.category.label << ")"
                      << " 置信度: " << faceInfo.category.score << std::endl;
        } else {
            std::cout << "人脸 #" << i + 1 << " 表情识别失败，标签: " 
                      << faceInfo.category.label << " 置信度: " 
                      << faceInfo.category.score << std::endl;
        }
    }
}

// 自定义可视化方法，将人脸标签替换为检测到的表情
void customVisualizeResult(cv::Mat &imgBRG, FrameInfo *frameInfo) {
    // 使用COLOR_TABLE数组来提供不同的颜色 - 更鲜艳的颜色
    static const std::vector<cv::Scalar> COLOR_TABLE = {
        cv::Scalar(0, 0, 255),     // 红色 - angry
        cv::Scalar(128, 0, 128),   // 紫色 - disgust
        cv::Scalar(0, 69, 255),    // 橙色 - fear
        cv::Scalar(0, 255, 0),     // 绿色 - happy
        cv::Scalar(255, 255, 0),   // 青色 - neutral
        cv::Scalar(255, 0, 0),     // 蓝色 - sad
        cv::Scalar(255, 0, 255),   // 品红色 - surprise
        cv::Scalar(0, 255, 255),   // 黄色 - 其他
        cv::Scalar(255, 255, 255)  // 白色 - 其他
    };
    
    // 遍历所有检测到的对象
    for (int i = 0; i < frameInfo->info.size(); i++) {
        auto &obj = frameInfo->info.at(i);
        cv::Rect rect(obj.x1, obj.y1, obj.x2 - obj.x1, obj.y2 - obj.y1);
        
        // 根据表情分类结果选择标签文本
        std::string labelText;
        cv::Scalar color;
        cv::Scalar textColor = cv::Scalar(255, 255, 255); // 默认白色文字
        
        // 检查category字段是否有效
        if (obj.category.label >= 0 && 
            obj.category.label < static_cast<int>(emotion_param.class_names.size())) {
            
            // 使用检测到的表情作为标签
            labelText = emotion_param.class_names[obj.category.label]; // 只显示表情名称，不显示分数
            
            // 根据表情选择颜色
            color = COLOR_TABLE[obj.category.label % COLOR_TABLE.size()];
            
            // 如果背景色较浅，使用黑色文字
            if (obj.category.label == 3 || obj.category.label == 4) { // happy或neutral
                textColor = cv::Scalar(0, 0, 0); // 黑色文字
            }
            
            std::cout << "绘制表情: " << emotion_param.class_names[obj.category.label] 
                      << " 索引: " << obj.category.label << std::endl;
        } else {
            // 如果没有表情识别结果，则使用默认的人脸标签
            labelText = "face";
            color = COLOR_TABLE[7]; // 默认颜色
            
            std::cout << "未检测到有效表情，使用默认标签。Category label: " 
                      << obj.category.label << " 得分: " << obj.category.score << std::endl;
        }
        
        // 绘制矩形和标签文本 - 使用更大更清晰的标签
        int baseline = 0;
        double fontSize = 1.2; // 增大字体
        int thickness = 2; // 增加字体粗细
        
        cv::Size textSize = cv::getTextSize(labelText, cv::FONT_HERSHEY_SIMPLEX, fontSize, thickness, &baseline);
        
        // 绘制人脸框
        cv::rectangle(imgBRG, rect, color, 3); // 加粗边框
        
        // 绘制标签背景，稍微扩大以容纳更大的文字
        cv::rectangle(imgBRG, 
                    cv::Point(rect.x, rect.y - textSize.height - 15),
                    cv::Point(rect.x + textSize.width + 15, rect.y),
                    color, -1);
        
        // 绘制标签文字，增大字体，调整位置使其居中
        cv::putText(imgBRG, labelText, 
                   cv::Point(rect.x + 7, rect.y - 7),
                   cv::FONT_HERSHEY_SIMPLEX, fontSize, textColor, thickness);
        
        // 如果有人脸关键点，绘制它们
        for (const auto &pt : obj.landmarks) {
            cv::circle(imgBRG, pt, 3, cv::Scalar(0, 255, 0), -1);
        }
    }
}

int main() {
    try {
        std::cout << "初始化程序..." << std::endl;
        
        // 检查模型文件是否存在
        if (!file_exists(det_model_file) || !file_exists(det_proto_file)) {
            std::cerr << "错误: 人脸检测模型文件不存在!" << std::endl;
            std::cerr << "模型文件: " << det_model_file << std::endl;
            std::cerr << "配置文件: " << det_proto_file << std::endl;
            return -1;
        }
        
        if (!file_exists(emo_model_file) || !file_exists(emo_proto_file)) {
            std::cerr << "错误: 表情识别模型文件不存在!" << std::endl;
            std::cerr << "模型文件: " << emo_model_file << std::endl;
            std::cerr << "配置文件: " << emo_proto_file << std::endl;
            return -1;
        }
        
        // 初始化人脸检测器
        std::cout << "初始化人脸检测器..." << std::endl;
        detector = new ObjectDetection(det_model_file,
                                       det_proto_file,
                                       model_param,
                                       num_thread,
                                       device);
        
        // 初始化表情识别器
        std::cout << "初始化表情识别器..." << std::endl;
        emotionClassifier = new Classification(emo_model_file,
                                              emo_proto_file,
                                              emotion_param,
                                              num_thread,
                                              device);
        
        // 创建窗口
        cv::namedWindow("Camera", cv::WINDOW_NORMAL);
        
        // 创建相机和回调实例
        Libcam2OpenCV camera;
        MyCallback callback;
        
        // 注册回调
        std::cout << "注册回调..." << std::endl;
        camera.registerCallback(&callback);
        
        // 启动相机
        std::cout << "启动相机..." << std::endl;
        camera.start();
        
        std::cout << "按下 'q' 退出, 's' 保存当前帧" << std::endl;
        
        // 主循环
        while (true) {
            // 如果有新帧，则显示和处理
            if (hasNewFrame) {
                // 创建工作副本
                cv::Mat processFrame = currentFrame.clone();
                hasNewFrame = false;
                
                // 帧计数增加
                frameCount++;
                
                // 每N帧执行一次人脸检测
                if (frameCount % processEveryNFrames == 0) {
                    // 调整图像大小以加快处理速度
                    cv::Mat resizedFrame = image_resize(processFrame, 320);
                    
                    // 清空上一次结果
                    lastResultInfo.info.clear();
                    
                    // 执行人脸检测
                    detector->detect(resizedFrame, &lastResultInfo, scoreThresh, iouThresh);
                    
                    // 如果检测到人脸，执行表情识别
                    if (!lastResultInfo.info.empty()) {
                        processEmotions(resizedFrame, &lastResultInfo);
                    }
                    
                    // 设置标志
                    hasDetectionResult = lastResultInfo.info.size() > 0;
                    
                    // 打印检测结果
                    std::cout << "帧 #" << frameCount << ", 检测到 " 
                              << lastResultInfo.info.size() << " 个人脸" << std::endl;
                    
                    // 更新处理帧
                    processFrame = resizedFrame;
                } else {
                    // 调整当前帧大小以匹配检测结果尺寸
                    processFrame = image_resize(processFrame, 320);
                }
                
                // 无论是否为检测帧，都根据最新检测结果显示
                if (hasDetectionResult) {
                    // 可视化检测结果
                    customVisualizeResult(processFrame, &lastResultInfo);
                    
                    // 计算并显示人脸中心点和表情
                    drawFaceCenters(processFrame, lastResultInfo);
                }
                
                // 显示处理后的帧
                cv::imshow("Camera", processFrame);
            }
            
            // 检查按键
            char key = cv::waitKey(10);
            if (key == 'q' || key == 'Q') {
                break; // 退出
            } else if (key == 's' || key == 'S') {
                // 保存当前帧
                if (!currentFrame.empty()) {
                    std::string filename = "camera_frame_" + std::to_string(frameCount) + ".jpg";
                    cv::imwrite(filename, currentFrame);
                    std::cout << "已保存图像: " << filename << std::endl;
                }
            }
        }
        
        // 停止相机
        std::cout << "停止相机..." << std::endl;
        camera.stop();
        
        // 释放资源
        if (detector) {
            delete detector;
            detector = nullptr;
        }
        
        if (emotionClassifier) {
            delete emotionClassifier;
            emotionClassifier = nullptr;
        }
        
        cv::destroyAllWindows();
        
    } catch (const std::exception& e) {
        std::cerr << "错误: " << e.what() << std::endl;
        
        // 清理资源
        if (detector) {
            delete detector;
            detector = nullptr;
        }
        
        if (emotionClassifier) {
            delete emotionClassifier;
            emotionClassifier = nullptr;
        }
        
        return -1;
    }
    
    return 0;
} 
