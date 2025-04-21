#ifndef __CAMERA_HPP
#define __CAMERA_HPP

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

extern const int num_thread; // 开启CPU线程数目
extern DeviceType computeDevice;         // 比如表示推理设备（CPU/GPU）
  // 选择运行设备CPU/GPU
// 人脸检测模型
extern const char *det_model_file;
extern const char *det_proto_file ;
extern ObjectDetectionParam model_param ;//模型参数
// 分类模型
extern const char *cls_model_file;
extern const char *cls_proto_file;
extern ClassificationParam ClassParam;//模型参数

// 设置检测阈值
extern const float scoreThresh;
extern const float iouThresh;


#endif // __CAMERA_HPP