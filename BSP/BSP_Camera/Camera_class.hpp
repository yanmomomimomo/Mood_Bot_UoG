#ifndef __CAMERA_CLASS_HPP
#define __CAMERA_CLASS_HPP

#include "Camera.hpp"

extern DeviceType device;

class Camera_class{
    public:
        Camera_class(int i);
        ~Camera_class();

        bool Collect();
        int ImageAnalysis();
    private:
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

        int camera {0};

        cv::VideoCapture cap;
        cv::Mat frame;
        FrameInfo resultInfo;
};

#endif // __CAMERA_CLASS_HPP