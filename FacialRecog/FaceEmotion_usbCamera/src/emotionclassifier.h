#ifndef _EMOTION_CLASSIFIER_H_
#define _EMOTION_CLASSIFIER_H_
#include <cstdio>
#include <iostream>
#include "opencv4/opencv2/opencv.hpp"
#include <onnxruntime/onnxruntime_cxx_api.h>
#include <qt5/QtCore/QObject>

class EmotionClassifier:public QObject{
    Q_OBJECT
public:
    EmotionClassifier(QString mp="",QObject *parent=NULL);
    ~EmotionClassifier();
    int predict(cv::Mat &img);
private:
    QString model_path;
    Ort::SessionOptions session_options;
    Ort::Session *session;
    Ort::AllocatorWithDefaultOptions allocator;
    std::vector<const char *> input_name;
    std::vector<const char *> output_name;
    
};
#endif
