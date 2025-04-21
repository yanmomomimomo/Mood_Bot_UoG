#ifndef FACE_RECOGNITION_TYPES_H
#define FACE_RECOGNITION_TYPES_H

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <vector>

using namespace std;

/***
 * 分类信息
 */
struct Category {
    int label;     // 分类的类别ID
    float score;   // 分类识别的置信度分数
};


/***
 * 目标信息
 */
struct ObjectInfo {
    float x1, x2, y1, y2, score;   // 左上角x1,左上角y1,右下角x2,右下角y2,置信度分数score
    vector<cv::Point2f> landmarks; // 人脸关键点，如果ModelParam的num_landmarks为0，则不存在关键点信息
    int label;                     // 检测框的类别ID，即bboxes框的index,查询ModelParam的class_names可获得真实的类别
    Category category;             // 分类信息
};

/***
 * 图像帧的所有目标信息
 */
struct FrameInfo {
    vector<ObjectInfo> info;
};
#endif //FACE_RECOGNITION_TYPES_H
