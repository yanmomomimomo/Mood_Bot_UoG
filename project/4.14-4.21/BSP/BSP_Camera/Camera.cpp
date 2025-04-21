#include "Camera_class.hpp"
#include "Camera.hpp"
#include <iostream>
#include <thread>
#include <chrono>

extern struct gpiod_chip *chip0;

// 全局实例
static Camera_class *g_cameraInstance = nullptr;

// 实现外调函数
bool Camera_Init()
{
    // 如果已经初始化，直接返回成功
    if (g_cameraInstance != nullptr) {
        std::cout << "摄像头已经初始化" << std::endl;
        return true;
    }
    
    try {
        // 创建摄像头实例
        g_cameraInstance = new Camera_class();
        std::cout << "摄像头初始化成功" << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "摄像头初始化失败: " << e.what() << std::endl;
        return false;
    }
}

void Camera_DeInit()
{
    // 释放资源
    if (g_cameraInstance != nullptr) {
        // 确保摄像头已停止
        if (g_cameraInstance->isRunning()) {
            g_cameraInstance->stop();
        }
        
        delete g_cameraInstance;
        g_cameraInstance = nullptr;
        std::cout << "摄像头资源已释放" << std::endl;
    }
}

bool Camera_Start()
{
    if (g_cameraInstance == nullptr) {
        std::cerr << "摄像头未初始化" << std::endl;
        return false;
    }
    
    return g_cameraInstance->start();
}

void Camera_Stop()
{
    if (g_cameraInstance != nullptr) {
        g_cameraInstance->stop();
    }
}

int Camera_GetFaceCount()
{
    if (g_cameraInstance == nullptr) {
        std::cerr << "摄像头未初始化" << std::endl;
        return CAMERA_NOT_INITIALIZED;
    }
    
    return g_cameraInstance->getFaceCount();
}

int Camera_GetEmotion(int faceIndex)
{
    if (g_cameraInstance == nullptr) {
        std::cerr << "摄像头未初始化" << std::endl;
        return CAMERA_NOT_INITIALIZED;
    }
    
    std::string emotion = g_cameraInstance->getEmotion(faceIndex);
    
    // 将emotion字符串映射到宏定义
    if (emotion == "angry") return EMOTION_ANGRY;
    if (emotion == "disgust") return EMOTION_DISGUST;
    if (emotion == "fear") return EMOTION_FEAR;
    if (emotion == "happy") return EMOTION_HAPPY;
    if (emotion == "neutral") return EMOTION_NEUTRAL;
    if (emotion == "sad") return EMOTION_SAD;
    if (emotion == "surprise") return EMOTION_SURPRISE;
    
    return CAMERA_ERROR; // 未识别的情绪
}

float Camera_GetEmotionConfidence(int faceIndex)
{
    if (g_cameraInstance == nullptr) {
        std::cerr << "摄像头未初始化" << std::endl;
        return CAMERA_NOT_INITIALIZED;
    }
    
    return g_cameraInstance->getEmotionConfidence(faceIndex);
}

bool Camera_GetFaceCenter(int faceIndex, int *centerX, int *centerY)
{
    if (g_cameraInstance == nullptr) {
        std::cerr << "摄像头未初始化" << std::endl;
        return false;
    }
    
    return g_cameraInstance->getFaceCenter(faceIndex, *centerX, *centerY);
}

bool Camera_SaveFrame(const char *filename)
{
    if (g_cameraInstance == nullptr) {
        std::cerr << "摄像头未初始化" << std::endl;
        return false;
    }
    
    return g_cameraInstance->saveCurrentFrame(filename);
}

Camera_class::Camera_class()
{
    // 初始化成员变量
    m_hasNewFrame = false;
    m_hasDetectionResult = false;
    m_detector = nullptr;
    m_emotionClassifier = nullptr;
    m_processEveryNFrames = 5;
    m_frameCount = 0;
    m_scoreThresh = 0.5f;
    m_iouThresh = 0.3f;
    m_running = false;
    m_stopProcessing = false;
    
    // TNN模型参数初始化
    m_numThread = 1;
    m_device = dl::CPU;
    
    // 设置模型文件路径
    m_detModelFile = "../../lib/tnn/face/rfb-face-mask-320-320_sim.opt.tnnmodel";
    m_detProtoFile = "../../lib/tnn/face/rfb-face-mask-320-320_sim.opt.tnnproto";
    m_emoModelFile = "../../lib/tnn/emotion/mobilenet_v2_112_112.tnnmodel";
    m_emoProtoFile = "../../lib/tnn/emotion/mobilenet_v2_112_112.tnnproto";
    
    // 设置模型参数
    m_modelParam = dl::vision::FACE_MODEL;
    m_emotionParam = dl::vision::EMOTION_MODEL;
    
    // 检查模型文件是否存在
    if (!dl::vision::file_exists(m_detModelFile.c_str()) || !dl::vision::file_exists(m_detProtoFile.c_str())) {
        throw std::runtime_error("人脸检测模型文件不存在");
    }
    
    if (!dl::vision::file_exists(m_emoModelFile.c_str()) || !dl::vision::file_exists(m_emoProtoFile.c_str())) {
        throw std::runtime_error("表情识别模型文件不存在");
    }
    
    // 初始化人脸检测器
    std::cout << "初始化人脸检测器..." << std::endl;
    m_detector = new dl::vision::ObjectDetection(
        m_detModelFile.c_str(),
        m_detProtoFile.c_str(),
        m_modelParam,
        m_numThread,
        m_device
    );
    
    // 初始化表情识别器
    std::cout << "初始化表情识别器..." << std::endl;
    m_emotionClassifier = new dl::vision::Classification(
        m_emoModelFile.c_str(),
        m_emoProtoFile.c_str(),
        m_emotionParam,
        m_numThread,
        m_device
    );
    
    // 注册回调
    m_camera.registerCallback(&m_callback);
    
    std::cout << "摄像头初始化完成" << std::endl;
}

Camera_class::~Camera_class()
{
    // 停止处理线程
    m_stopProcessing = true;
    if (m_processingThread.joinable()) {
        m_processingThread.join();
    }
    
    // 停止相机
    if (m_running) {
        stop();
    }
    
    // 释放检测器资源
    if (m_detector) {
        delete m_detector;
        m_detector = nullptr;
    }
    
    if (m_emotionClassifier) {
        delete m_emotionClassifier;
        m_emotionClassifier = nullptr;
    }
    
    std::cout << "摄像头资源已释放" << std::endl;
}

// 启动相机
bool Camera_class::start()
{
    if (m_running) {
        std::cout << "摄像头已经在运行中" << std::endl;
        return true;
    }
    
    try {
        // 启动相机
        m_camera.start();
        m_running = true;
        
        // 启动处理线程
        m_stopProcessing = false;
        m_processingThread = std::thread(&Camera_class::processingThreadFunc, this);
        
        std::cout << "摄像头启动成功" << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "摄像头启动失败: " << e.what() << std::endl;
        return false;
    }
}

// 停止相机
void Camera_class::stop()
{
    if (!m_running) {
        return;
    }
    
    // 停止处理线程
    m_stopProcessing = true;
    if (m_processingThread.joinable()) {
        m_processingThread.join();
    }
    
    // 停止相机
    m_camera.stop();
    m_running = false;
    
    std::cout << "摄像头已停止" << std::endl;
}

// 检查相机是否运行中
bool Camera_class::isRunning() const
{
    return m_running;
}

// 获取处理后的帧
cv::Mat Camera_class::getProcessedFrame()
{
    std::lock_guard<std::mutex> lock(m_frameMutex);
    return m_processedFrame.clone();
}

// 获取检测结果
const dl::vision::FrameInfo& Camera_class::getDetectionResult() const
{
    return m_lastResultInfo;
}

// 获取人脸数量
int Camera_class::getFaceCount() const
{
    return m_lastResultInfo.info.size();
}

// 获取检测到的表情
std::string Camera_class::getEmotion(int faceIndex) const
{
    if (faceIndex < 0 || faceIndex >= static_cast<int>(m_lastResultInfo.info.size())) {
        return ""; // 无效的索引
    }
    
    const auto &obj = m_lastResultInfo.info.at(faceIndex);
    
    // 检查category字段是否有效
    if (obj.category.label >= 0 && 
        obj.category.label < static_cast<int>(m_emotionParam.class_names.size())) {
        
        return m_emotionParam.class_names[obj.category.label];
    }
    
    return ""; // 无效的表情
}

// 获取表情置信度
float Camera_class::getEmotionConfidence(int faceIndex) const
{
    if (faceIndex < 0 || faceIndex >= static_cast<int>(m_lastResultInfo.info.size())) {
        return 0.0f; // 无效的索引
    }
    
    const auto &obj = m_lastResultInfo.info.at(faceIndex);
    
    // 检查category字段是否有效
    if (obj.category.label >= 0 && 
        obj.category.label < static_cast<int>(m_emotionParam.class_names.size())) {
        
        return obj.category.score;
    }
    
    return 0.0f; // 无效的表情
}

// 获取人脸中心点
bool Camera_class::getFaceCenter(int faceIndex, int &centerX, int &centerY) const
{
    if (faceIndex < 0 || faceIndex >= static_cast<int>(m_lastResultInfo.info.size())) {
        return false; // 无效的索引
    }
    
    const auto &obj = m_lastResultInfo.info.at(faceIndex);
    
    // 计算中心点坐标
    centerX = static_cast<int>((obj.x1 + obj.x2) / 2);
    centerY = static_cast<int>((obj.y1 + obj.y2) / 2);
    
    return true;
}

// 保存当前帧
bool Camera_class::saveCurrentFrame(const std::string &filename)
{
    std::lock_guard<std::mutex> lock(m_frameMutex);
    
    if (m_currentFrame.empty()) {
        return false;
    }
    
    try {
        cv::imwrite(filename, m_currentFrame);
        std::cout << "图像已保存: " << filename << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "保存图像失败: " << e.what() << std::endl;
        return false;
    }
}

// 处理帧
void Camera_class::processFrame()
{
    if (m_hasNewFrame) {
        // 创建工作副本
        cv::Mat processFrame;
        {
            std::lock_guard<std::mutex> lock(m_frameMutex);
            processFrame = m_currentFrame.clone();
            m_hasNewFrame = false;
        }
        
        // 帧计数增加
        m_frameCount++;
        
        // 每N帧执行一次人脸检测
        if (m_frameCount % m_processEveryNFrames == 0) {
            // 调整图像大小以加快处理速度
            cv::Mat resizedFrame = dl::vision::image_resize(processFrame, 320);
            
            // 清空上一次结果
            m_lastResultInfo.info.clear();
            
            // 执行人脸检测
            m_detector->detect(resizedFrame, &m_lastResultInfo, m_scoreThresh, m_iouThresh);
            
            // 如果检测到人脸，执行表情识别
            if (!m_lastResultInfo.info.empty()) {
                processEmotions(resizedFrame, &m_lastResultInfo);
            }
            
            // 设置标志
            m_hasDetectionResult = m_lastResultInfo.info.size() > 0;
            
            // 打印检测结果
            std::cout << "帧 #" << m_frameCount << ", 检测到 " 
                      << m_lastResultInfo.info.size() << " 个人脸" << std::endl;
            
            // 更新处理帧
            processFrame = resizedFrame;
        } else {
            // 调整当前帧大小以匹配检测结果尺寸
            processFrame = dl::vision::image_resize(processFrame, 320);
        }
        
        // 无论是否为检测帧，都根据最新检测结果显示
        if (m_hasDetectionResult) {
            // 可视化检测结果
            customVisualizeResult(processFrame, &m_lastResultInfo);
            
            // 计算并显示人脸中心点和表情
            drawFaceCenters(processFrame, m_lastResultInfo);
        }
        
        // 保存处理后的帧
        {
            std::lock_guard<std::mutex> lock(m_frameMutex);
            m_processedFrame = processFrame;
        }
    }
}

// 处理线程函数
void Camera_class::processingThreadFunc()
{
    while (!m_stopProcessing) {
        // 处理帧
        processFrame();
        
        // 短暂休眠，避免CPU占用过高
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

// 对检测到的人脸进行表情识别
void Camera_class::processEmotions(cv::Mat &frame, dl::vision::FrameInfo *frameInfo)
{
    if (frameInfo->info.empty() || !m_emotionClassifier) {
        std::cout << "无法进行表情识别：没有人脸或分类器未初始化" << std::endl;
        return; // 没有检测到人脸或表情分类器未初始化
    }
    
    std::cout << "进行表情分类..." << std::endl;
    
    // 直接将frameInfo传递给分类器
    m_emotionClassifier->detect(frame, frameInfo);
    
    // 输出分类结果
    for (size_t i = 0; i < frameInfo->info.size(); i++) {
        dl::vision::ObjectInfo &faceInfo = frameInfo->info[i];
        if (faceInfo.category.label >= 0 && 
            faceInfo.category.label < static_cast<int>(m_emotionParam.class_names.size())) {
            
            std::cout << "人脸 #" << i + 1 << " 识别到表情: " 
                      << m_emotionParam.class_names[faceInfo.category.label]
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
void Camera_class::customVisualizeResult(cv::Mat &imgBRG, dl::vision::FrameInfo *frameInfo)
{
    // 使用COLOR_TABLE数组来提供不同的颜色
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
            obj.category.label < static_cast<int>(m_emotionParam.class_names.size())) {
            
            // 使用检测到的表情作为标签
            labelText = m_emotionParam.class_names[obj.category.label]; // 只显示表情名称，不显示分数
            
            // 根据表情选择颜色
            color = COLOR_TABLE[obj.category.label % COLOR_TABLE.size()];
            
            // 如果背景色较浅，使用黑色文字
            if (obj.category.label == 3 || obj.category.label == 4) { // happy或neutral
                textColor = cv::Scalar(0, 0, 0); // 黑色文字
            }
            
            std::cout << "绘制表情: " << m_emotionParam.class_names[obj.category.label] 
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

// 计算并绘制人脸中心点和表情
void Camera_class::drawFaceCenters(cv::Mat &frame, const dl::vision::FrameInfo &resultInfo)
{
    for (size_t i = 0; i < resultInfo.info.size(); i++) {
        const dl::vision::ObjectInfo &info = resultInfo.info[i];
        
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
            info.category.label < static_cast<int>(m_emotionParam.class_names.size())) {
            
            std::string emotionText = "Emotion: " + m_emotionParam.class_names[info.category.label] + 
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

// CameraCallback实现
void CameraCallback::hasFrame(const cv::Mat &frame, const libcamera::ControlList &metadata)
{
    if (!frame.empty()) {
        std::lock_guard<std::mutex> lock(frameMutex);
        frame.copyTo(static_cast<Camera_class*>(this)->m_currentFrame);
        static_cast<Camera_class*>(this)->m_hasNewFrame = true;
    }
}