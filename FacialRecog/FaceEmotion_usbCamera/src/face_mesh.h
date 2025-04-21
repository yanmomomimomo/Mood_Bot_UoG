#ifndef _FACE_MESH_H_
#define _FACE_MESH_H_

#include <cstdlib>
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/formats/image_frame.h"
#include "mediapipe/framework/formats/image_frame_opencv.h"
#include "mediapipe/framework/port/file_helpers.h"
#include "mediapipe/framework/port/opencv_highgui_inc.h"
#include "mediapipe/framework/port/opencv_imgproc_inc.h"
#include "mediapipe/framework/port/opencv_video_inc.h"
#include "mediapipe/framework/port/parse_text_proto.h"
#include "mediapipe/framework/port/status.h"
#include "mediapipe/framework/formats/detection.pb.h"
#include "mediapipe/framework/formats/landmark.pb.h"
#include "mediapipe/framework/formats/rect.pb.h"
#include "opencv2/highgui/highgui_c.h"
#include <functional>
#include <QtWidgets/QWidget>
#include <QtCore/QTimer>
#include <QtCore/QDebug>
#include <QtWidgets/QApplication>
#include <QtGui/QResizeEvent>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QSpinBox>
#include <iostream>
#include <random>
#include <vector>
#include <QtCore/QDateTime>
#include <QtCore/QThread>
#include "emotionclassifier.h"
#include <QtGui/QImage>

class FaceMesh : public QThread
{
    Q_OBJECT

public:
    FaceMesh();
    ~FaceMesh();
    int initModel(const char* model_path) noexcept;
    int release();
    void runVideo();
    
private slots:
    void updateFrame();
signals:
    void frameDone(QImage&);
    void emotionDone(int&);
    void servoTurn(int);
private:
    void run();
    int valid_emotion_count=0;
    int last_emotion_index=0;
    bool ready=true;
    void resizeEvent(QResizeEvent *re);
    absl::Status initGraph(const char* model_path);
    absl::Status releaseGraph();
    int extractFace(cv::Mat& image,cv::Mat &firstface);
    const char* kInputStream = "input_video";
    const char* kOutputStream = "output_video";
    const char* kWindowName = "Camera";
    const char* kOutputLandmarks = "face_detections";
    bool init_ = false;
    mediapipe::CalculatorGraph graph_;
    std::unique_ptr<mediapipe::OutputStreamPoller> pPoller_;
    std::unique_ptr<mediapipe::OutputStreamPoller> pPollerLandmarks_; // landmarks
    std::vector<cv::Scalar> color_map={cv::Scalar(0,0,255),cv::Scalar(0,255,0),cv::Scalar(255,0,255),cv::Scalar(0,255,255)};
    int fps;
    QTimer *timer_for_render;
    cv::VideoCapture capture;
    bool frame_ready=true;
    EmotionClassifier *ec;
};
#endif
