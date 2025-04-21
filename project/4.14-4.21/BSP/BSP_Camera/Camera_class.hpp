#ifndef __CAMERA_CLASS_HPP
#define __CAMERA_CLASS_HPP

#include <string>
#include <gpiod.h>
#include "Keys.hpp"
#include <opencv4/opencv2/opencv.hpp>
#include "libcam2opencv.h"
#include "object_detection.h"
#include "classification.h"
#include "file_utils.h"
#include "image_utils.h"

#include <mutex>
#include <thread>

extern gpiod_chip *chip0;

// 回调结构体
struct CameraCallback : public Libcam2OpenCV::Callback {
    void hasFrame(const cv::Mat &frame, const libcamera::ControlList &metadata) override;
    std::mutex frameMutex;
};

class Camera_class {
    public:
        Camera_class();
        virtual ~Camera_class();

        // 功能函数
        bool start();  // 启动相机
        void stop();   // 停止相机
        bool isRunning() const;  // 检查相机是否运行中
        
        // 获取处理后的帧
        cv::Mat getProcessedFrame();
        
        // 获取检测结果
        const dl::vision::FrameInfo& getDetectionResult() const;
        
        // 获取人脸数量
        int getFaceCount() const;
        
        // 获取检测到的表情
        std::string getEmotion(int faceIndex = 0) const;
        
        // 获取表情置信度
        float getEmotionConfidence(int faceIndex = 0) const;
        
        // 获取人脸中心点
        bool getFaceCenter(int faceIndex, int &centerX, int &centerY) const;
        
        // 保存当前帧
        bool saveCurrentFrame(const std::string &filename);

    private:
        // 相机和回调
        Libcam2OpenCV m_camera;
        CameraCallback m_callback;
        
        // 当前帧和处理帧
        cv::Mat m_currentFrame;
        cv::Mat m_processedFrame;
        bool m_hasNewFrame;
        std::mutex m_frameMutex;
        
        // 检测相关
        dl::vision::ObjectDetection *m_detector;
        dl::vision::Classification *m_emotionClassifier;
        dl::vision::FrameInfo m_lastResultInfo;
        bool m_hasDetectionResult;
        
        // 处理参数
        int m_processEveryNFrames;
        int m_frameCount;
        float m_scoreThresh;
        float m_iouThresh;
        bool m_running;
        
        // TNN模型相关参数
        int m_numThread;
        dl::DeviceType m_device;
        std::string m_detModelFile;
        std::string m_detProtoFile;
        std::string m_emoModelFile;
        std::string m_emoProtoFile;
        dl::vision::ObjectDetectionParam m_modelParam;
        dl::vision::ClassificationParam m_emotionParam;
        
        // 处理函数
        void processFrame();
        void processEmotions(cv::Mat &frame, dl::vision::FrameInfo *frameInfo);
        void customVisualizeResult(cv::Mat &imgBRG, dl::vision::FrameInfo *frameInfo);
        void drawFaceCenters(cv::Mat &frame, const dl::vision::FrameInfo &resultInfo);
        
        // 处理线程
        std::thread m_processingThread;
        bool m_stopProcessing;
        void processingThreadFunc();
        
        friend struct CameraCallback;
};

#endif // __CAMERA_CLASS_HPP