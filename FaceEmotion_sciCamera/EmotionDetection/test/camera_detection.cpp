#include <opencv2/opencv.hpp>
#include "libcam2opencv.h"
#include <string>
#include <libcamera2opencv/libcamera2opencv.h>
#include "/home/mood/libcamera2opencv/libcam2opencv.h"


// object-detection-tnn-sdk 头文件
#include "object_detection.h"
#include "file_utils.h"
#include "image_utils.h"
int frameCount = 0;

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

// 设置检测阈值
const float scoreThresh = 0.5; // 置信度阈值
const float iouThresh = 0.3;   // NMS阈值

// 人脸检测对象
ObjectDetection *detector = nullptr;

// 控制检测频率
int processEveryNFrames = 5;
int frameCount = 0;

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

// 计算并绘制人脸中心点
void drawFaceCenters(cv::Mat &frame, const FrameInfo &resultInfo) {
    for (size_t i = 0; i < resultInfo.info.size(); i++) {
        const ObjectInfo &info = resultInfo.info[i];


        // 计算中心点坐标（使用x1,y1,x2,y2）
        int centerX = static_cast<int>((info.x1 + info.x2) / 2);

        // 在图像上绘制中心点
        cv::circle(frame, cv::Point(centerX, centerY), 3, cv::Scalar(0, 255, 0), -1);

        // 显示中心点坐标
        std::string centerText = "(" + std::to_string(centerX) + "," + std::to_string(centerY) + ")";
        cv::putText(frame, centerText, cv::Point(centerX + 5, centerY - 5),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1);

        // 输出到控制台
        std::cout << "人脸 #" << i + 1 << " 中心坐标: (" << centerX << ", " << centerY << ")" << std::endl;
    }
}

        // 根据README示例创建相机和回调实例
        Libcam2OpenCV camera;
        MyCallback callback;

        // 注册回调
        std::cout << "注册回调..." << std::endl;
        camera.registerCallback(&callback);

        // 启动相机
        std::cout << "启动相机..." << std::endl;
        camera.start();
         std::cout << "初始化程序..." << std::endl;

        // 检查模型文件是否存在
        if (!file_exists(det_model_file) || !file_exists(det_proto_file)) {
            std::cerr << "错误: 模型文件不存在!" << std::endl;
            std::cerr << "模型文件: " << det_model_file << std::endl;
            std::cerr << "配置文件: " << det_proto_file << std::endl;
            return -1;
        }

        // 初始化人脸检测器
        std::cout << "初始化人脸检测器..." << std::endl;
        detector = new ObjectDetection(det_model_file,
                                       det_proto_file,
                                       model_param,
                                       num_thread,
                                       device);


        // 创建窗口
        cv::namedWindow("Camera", cv::WINDOW_NORMAL);
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

                // 检测结果结构
                FrameInfo resultInfo;

                // 每N帧执行一次人脸检测
                if (frameCount % processEveryNFrames == 0) {
                    // 调整图像大小以加快处理速度
                    cv::Mat resizedFrame = image_resize(processFrame, 320);

                    // 执行人脸检测
                    detector->detect(resizedFrame, &resultInfo, scoreThresh, iouThresh);

                    // 可视化检测结果
                    detector->visualizeResult(resizedFrame, &resultInfo, 1);

                    // 计算并显示人脸中心点
                    drawFaceCenters(resizedFrame, resultInfo);

                    // 打印检测结果
                    std::cout << "帧 #" << frameCount << ", 检测到 "
                              << resultInfo.info.size() << " 个人脸" << std::endl;


                    // 使用处理后的帧进行显示
                    processFrame = resizedFrame;
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
        std::cout << "停止相机..." << std::endl;
        camera.stop();

        // 释放资源
        if (detector) {
            delete detector;
            detector = nullptr;
        }

        cv::destroyAllWindows();

    } catch (const std::exception& e) {
        std::cerr << "错误: " << e.what() << std::endl;

        // 清理资源
        if (detector) {
            delete detector;
            detector = nullptr;
        }

        return -1;
    }