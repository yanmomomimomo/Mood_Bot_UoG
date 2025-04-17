#include "libcam2opencv.h"

// 用于显示图像的全局变量
cv::Mat currentFrame;
bool hasNewFrame = false;

// 根据README示例定义回调结构体
struct MyCallback : Libcam2OpenCV::Callback {
    virtual void hasFrame(const cv::Mat &frame, const libcamera::ControlList &) {
        if (!frame.empty()) {
            // 复制帧以便在主线程中显示
            frame.copyTo(currentFrame);
            hasNewFrame = true;
            
            // 打印帧信息（仅在第一帧）
            static bool first_frame = true;
            if (first_frame) {
                std::cout << "首帧信息: " << frame.cols << "x" << frame.rows
                          << ", 类型=" << frame.type()
                          << ", 通道数=" << frame.channels() << std::endl;
                first_frame = false;
            }
        }
        cv::namedWindow("Camera", cv::WINDOW_NORMAL);

        // 根据README示例创建相机和回调实例
        Libcam2OpenCV camera;
        MyCallback myCallback;

        // 注册回调
        std::cout << "注册回调..." << std::endl;
        camera.registerCallback(&myCallback);

        // 启动相机
        std::cout << "启动相机..." << std::endl;
        camera.start();

        std::cout << "按下 'q' 退出" << std::endl;

        // 主循环
        int frameCount = 0;
        while (true) {
            // 如果有新帧，则显示
            if (hasNewFrame) {
                cv::imshow("Camera", currentFrame);
                hasNewFrame = false;

                // 每30帧打印一次中心像素值
                if (frameCount++ % 30 == 0 && !currentFrame.empty()) {
                    cv::Vec3b pixel = currentFrame.at<cv::Vec3b>(currentFrame.rows/2, currentFrame.cols/2);
                    std::cout << "帧 #" << frameCount
                              << ", 中心像素值: [" << (int)pixel[0] << ","
                              << (int)pixel[1] << "," << (int)pixel[2] << "]"
                              << std::endl;
                }
            }

            // 检查退出
            char key = cv::waitKey(10);
            if (key == 'q' || key == 'Q') {
                break;
        // 停止相机
        std::cout << "停止相机..." << std::endl;
        camera.stop();

        cv::destroyAllWindows();

    } catch (const std::exception& e) {
        std::cerr << "错误: " << e.what() << std::endl;
        return -1;
    }