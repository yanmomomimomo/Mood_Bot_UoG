#include "Camera_class.hpp"

const int num_thread = 6; // 开启CPU线程数目
DeviceType device = GPU;  // 选择运行设备CPU/GPU
// 人脸检测模型
const char *det_model_file = (char *) "/home/MootBot/MoodBot_Product/lib/data/tnn/face/rfb-face-mask-320-320_sim.opt.tnnmodel";
const char *det_proto_file = (char *) "/home/MootBot/MoodBot_Product/lib/data/tnn/face/rfb-face-mask-320-320_sim.opt.tnnproto";
ObjectDetectionParam model_param = FACE_MODEL;//模型参数
// 分类模型
const char *cls_model_file = (char *) "/home/MootBot/MoodBot_Product/lib/data/tnn/emotion/mobilenet_v2_112_112.tnnmodel";
const char *cls_proto_file = (char *) "/home/MootBot/MoodBot_Product/lib/data/tnn/emotion/mobilenet_v2_112_112.tnnproto";
ClassificationParam ClassParam = EMOTION_MODEL;//模型参数

// 设置检测阈值
const float scoreThresh = 0.5;
const float iouThresh = 0.3;

Camera_class::Camera_class(int i){
    bool ret = get_video_capture(camera, cap);
    if (!ret){
        std::cout<<"Camera_class Error"<<std::endl;
    }
}

Camera_class::~Camera_class(){
    cap.release();
    delete detector;
    detector = nullptr;
    delete classifier;
    classifier = nullptr;
    printf("FINISHED.\n");
}

bool Camera_class::Collect(){
    cap >> frame;
    if (frame.empty()) return false;
    return true;
}

int Camera_class::ImageAnalysis(){
    int value;
    // 进行人脸检测
    detector->detect(frame, &resultInfo, scoreThresh, iouThresh);
    // 进行图像分类
    classifier->detect(frame, &resultInfo);
    // 可视化检测结果
    value = classifier->visualizeResult(frame, &resultInfo, 20);
    return value;
}