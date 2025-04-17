//
// Created by Pan on 2020/6/24.
//

#include "object_detection.h"
#include "classification.h"
#include <iostream>
#include <string>
#include <vector>
#include "file_utils.h"
#include "image_utils.h"

using namespace dl;
using namespace vision;
using namespace std;


const int num_thread = 1; // 开启CPU线程数目
DeviceType device = GPU;  // 选择运行设备CPU/GPU
// 人脸检测模型
const char *det_model_file = (char *) "../data/tnn/face/rfb-face-mask-320-320_sim.opt.tnnmodel";
const char *det_proto_file = (char *) "../data/tnn/face/rfb-face-mask-320-320_sim.opt.tnnproto";
ObjectDetectionParam model_param = FACE_MODEL;//模型参数
// 分类模型
const char *cls_model_file = (char *) "../data/tnn/emotion/mobilenet_v2_112_112.tnnmodel";
const char *cls_proto_file = (char *) "../data/tnn/emotion/mobilenet_v2_112_112.tnnproto";
ClassificationParam ClassParam = EMOTION_MODEL;//模型参数

// 设置检测阈值
const float scoreThresh = 0.5;
const float iouThresh = 0.3;
ObjectDetection *detector = new ObjectDetection(det_model_file,
                                                det_proto_file,
                                                model_param,
                                                num_thread,
                                                device);

Classification *classifier = new Classification(cls_model_file,
                                                cls_proto_file,
                                                ClassParam,
                                                num_thread,
                                                device);

/***
 * 测试图片文件
 */
void test_image_file() {
    //测试图片的目录
    string image_dir = "../data/test_image";
    std::vector<string> image_list = get_files_list(image_dir);
    for (string image_path:image_list) {
        cv::Mat bgr_image = cv::imread(image_path);
        bgr_image = image_resize(bgr_image, 960);
        if (bgr_image.empty()) continue;
        FrameInfo resultInfo;
        // 进行人脸检测
        detector->detect(bgr_image, &resultInfo, scoreThresh, iouThresh);
        // 进行图像分类
        classifier->detect(bgr_image, &resultInfo);
        // 可视化检测结果
        classifier->visualizeResult(bgr_image, &resultInfo);
    }
    delete detector;
    detector = nullptr;
    delete classifier;
    classifier = nullptr;
    printf("FINISHED.\n");
}

/***
 * 测试视频文件
 * @return
 */
int test_video_file() {
    //测试视频文件
    string video_file = "../data/video/video-test.mp4";
    cv::VideoCapture cap;
    bool ret = get_video_capture(video_file, cap);
    cv::Mat frame;
    while (ret) {
        cap >> frame;
        if (frame.empty()) break;
        FrameInfo resultInfo;
        // 进行人脸检测
        detector->detect(frame, &resultInfo, scoreThresh, iouThresh);
        // 进行图像分类
        classifier->detect(frame, &resultInfo);
        // 可视化检测结果
        classifier->visualizeResult(frame, &resultInfo, 20);
    }
    cap.release();
    delete detector;
    detector = nullptr;
    delete classifier;
    classifier = nullptr;
    printf("FINISHED.\n");
    return 0;

}


/***
 * 测试摄像头
 * @return
 */
int test_camera() {
    int camera = 0; //摄像头ID号(请修改成自己摄像头ID号)
    cv::VideoCapture cap;
    bool ret = get_video_capture(camera, cap);
    cv::Mat frame;
    while (ret) {
        cap >> frame;
        if (frame.empty()) break;
        FrameInfo resultInfo;
        // 进行人脸检测
        detector->detect(frame, &resultInfo, scoreThresh, iouThresh);
        // 进行图像分类
        classifier->detect(frame, &resultInfo);
        // 可视化检测结果
        classifier->visualizeResult(frame, &resultInfo, 20);
    }
    cap.release();
    delete detector;
    detector = nullptr;
    delete classifier;
    classifier = nullptr;
    printf("FINISHED.\n");
    return 0;

}


int main() {
    test_image_file();   // 测试图片文件
    //test_video_file();   // 测试视频文件
    //test_camera();       //测试摄像头
    return 0;
}
