#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>

// libcamera2opencv 头文件
// object-detection-tnn-sdk 头文件
#include "object_detection.h"
#include "classification.h"
#include "file_utils.h"
#include "image_utils.h"

using namespace std;
using namespace dl;
using namespace vision;
using namespace std;

// 全局变量
const int num_thread = 1;
DeviceType device = CPU;  // 使用CPU运行，如果树莓派支持GPU可以改为GPU

// 人脸检测模型
const char *det_model_file = (char *) "../data/tnn/face/rfb-face-mask-320-320_sim.opt.tnnmodel";
const char *det_proto_file = (char *) "../data/tnn/face/rfb-face-mask-320-320_sim.opt.tnnproto";
ObjectDetectionParam model_param = FACE_MODEL;//模型参数

  // 设置检测阈值
  const float scoreThresh = 0.5;
  const float iouThresh = 0.3;

// 全局对象
ObjectDetection *detector = nullptr;
Libcam2OpenCV *camera = nullptr;

// 使用libcamera2opencv的回调类
struct DetectionCallback : Libcam2OpenCV::Callback {
    virtual void hasFrame(const cv::Mat &frame, const libcamera::ControlList &metadata) override {
        if (!frame.empty() && detector != nullptr) {
            // 调整图像大小
            cv::Mat resized_frame = image_resize(frame, 960);

            // 进行目标检测
            FrameInfo resultInfo;
            detector->detect(resized_frame, &resultInfo, scoreThresh, iouThresh);

            // 可视化结果
            detector->visualizeResult(resized_frame, &resultInfo, 1);

            // 显示图像
            cv::imshow("Camera Detection", resized_frame);
            cv::waitKey(1);  // 非阻塞式等待
        }
    }
};

void cleanup() {
    // 停止相机
    if (camera != nullptr) {
        camera->stop();
        delete camera;
        camera = nullptr;
    }

    // 释放检测器
    if (detector != nullptr) {
        delete detector;
        detector = nullptr;
    }

    cv::destroyAllWindows();
    printf("Cleaned up resources.\n");
}

int main() {
    // 初始化目标检测器
    // 创建相机回调
    DetectionCallback *callback = new DetectionCallback();

    // 初始化相机
    camera = new Libcam2OpenCV();
    camera->registerCallback(callback);


      // 启动相机
    printf("Starting camera...\n");
    camera->start(settings);

    printf("Press 'q' to quit.\n");

    // 等待用户输入q退出
    while (true) {
        char key = cv::waitKey(100);
        if (key == 'q' || key == 'Q') {
            break;
          }
    }

    // 清理资源
    cleanup();
    delete callback;

    return 0;
  }