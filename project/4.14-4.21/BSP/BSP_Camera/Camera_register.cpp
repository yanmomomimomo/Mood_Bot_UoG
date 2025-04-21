#include "Getter_Register.hpp"
#include "Camera_class.hpp"
#include "Camera.hpp"

// CameraGetter类实现
CameraGetter::CameraGetter(Camera_class &camera, const std::string &topic)
    : m_camera(camera), m_topic(topic)
{
    registerCallback([this](uint8_t event) {
        // 根据事件类型触发不同的动作
        if (event == CLICK) {
            // 获取当前检测到的人脸数量
            int faceCount = m_camera.getFaceCount();
            
            // 如果检测到人脸，发布相关事件
            if (faceCount > 0) {
                // 获取第一个人脸的表情
                int emotion = Camera_GetEmotion(0);
                // 获取表情的置信度
                float confidence = Camera_GetEmotionConfidence(0);
                
                // 根据表情类型发布不同的事件代码
                switch (emotion) {
                    case EMOTION_HAPPY:
                        m_bus.publish(m_topic, 1); // 开心表情
                        break;
                    case EMOTION_SAD:
                        m_bus.publish(m_topic, 2); // 悲伤表情
                        break;
                    case EMOTION_ANGRY:
                        m_bus.publish(m_topic, 3); // 生气表情
                        break;
                    case EMOTION_NEUTRAL:
                        m_bus.publish(m_topic, 4); // 中性表情
                        break;
                    case EMOTION_SURPRISE:
                        m_bus.publish(m_topic, 5); // 惊讶表情
                        break;
                    case EMOTION_FEAR:
                        m_bus.publish(m_topic, 6); // 恐惧表情
                        break;
                    case EMOTION_DISGUST:
                        m_bus.publish(m_topic, 7); // 厌恶表情
                        break;
                    default:
                        m_bus.publish(m_topic, 0); // 未知表情
                        break;
                }
            } else {
                // 没有检测到人脸
                m_bus.publish(m_topic, 0);
            }
        }
    });
}

CameraGetter::~CameraGetter() {
    // 清理资源
}

bool CameraGetter::blockAndWaitEvent() {
    // 等待检测到人脸变化
    int lastFaceCount = -1;
    int currentFaceCount = 0;
    
    // 创建超时计时器
    auto startTime = std::chrono::steady_clock::now();
    const int timeoutSeconds = 10; // 设置10秒超时
    
    while (true) {
        // 检查超时
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
        if (elapsedTime.count() >= timeoutSeconds) {
            return false; // 超时返回
        }
        
        // 获取当前人脸数量
        currentFaceCount = m_camera.getFaceCount();
        
        // 如果人脸数量发生变化，触发事件
        if (lastFaceCount != currentFaceCount) {
            if (lastFaceCount == -1) {
                // 首次获取，只更新lastFaceCount
                lastFaceCount = currentFaceCount;
            } else {
                // 人脸数量变化，触发回调
                if (currentFaceCount > 0) {
                    // 获取表情
                    int emotion = Camera_GetEmotion(0);
                    
                    // 根据表情类型触发不同的事件
                    if (emotion != CAMERA_ERROR && emotion != CAMERA_NOT_INITIALIZED) {
                        return true; // 成功检测到有效事件
                    }
                }
                
                // 更新上一次的人脸数量
                lastFaceCount = currentFaceCount;
            }
        }
        
        // 短暂休眠，避免CPU占用过高
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    return false; // 默认返回失败
}

