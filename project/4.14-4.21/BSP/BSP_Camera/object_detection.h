//
// Created by 390737991@qq.com on 2020/6/3.
//

#ifndef FACE_RECOGNITION_FACE_DETECTION_H
#define FACE_RECOGNITION_FACE_DETECTION_H
#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include "Types.h"
#include "Interpreter.h"

using namespace std;

#define hard_nms 1
#define blending_nms 2


/***
 * SSD Detection Model Param
 */
struct ObjectDetectionParam {
    ModelType model_type;                  // 模型类型，MODEL_TYPE_TNN，MODEL_TYPE_NCNN等
    int input_width;                       // 模型输入宽度，单位：像素
    int input_height;                      // 模型输入高度，单位：像素
    bool use_rgb;                          // 是否使用RGB作为模型输入（PS：接口固定输入BGR，use_rgb=ture时，预处理将BGR转换为RGB）
    bool padding;                          // 是否通过Padding进行等比例缩放
    bool freeze_header;                    // 模型anchor是否进行了固化处理,固化后，可以加速，但会要求固定的输入分辨率
    int num_landmarks;                     // 关键点个数
    vector<vector<float>> min_boxes;       // anchor大小，单位：像素
    vector<float> strides;                 // 每个featuremap的缩放倍数
    vector<vector<float>> aspect_ratios;   // anchor的长宽比
    NetNodes InputNodes;                   // 输入节点名称
    NetNodes OutputNodes;                  // 输出节点名称
    vector<string> class_names;            // 类别集合
};


/***
 *  人脸+人体检测模型参数
 */
static ObjectDetectionParam FACE_PERSON_MODEL = {MODEL_TYPE_TNN,
                                                 320,
                                                 320,
                                                 true,
                                                 true,
                                                 true,
                                                 0,
                                                 {{10.f, 16.f, 24.f},
                                                  {32.f, 48.f},
                                                  {64.f, 96.f},
                                                  {128.f, 192.f, 256.f}},//min_boxes
                                                 {8.0f, 16.0f, 32.0f, 64.0f},//strides
                                                 {{1.0, 1.0}, {1.2, 1.5}, {1.0, 2.0}},   //aspect_ratios
                                                 {{{"input", nullptr}}}, //InputNodes
                                                 {{{"boxes", nullptr},   //OutputNodes
                                                   {"scores", nullptr}}},
                                                 {"BACKGROUND", "face", "person"}};


/***
 *  人脸检测参数
 */
static ObjectDetectionParam FACE_MODEL = {MODEL_TYPE_TNN,
                                          320,
                                          320,
                                          true,
                                          true,
                                          false,
                                          0,
                                          {{10.f, 16.f, 24.f},
                                           {32.f, 48.f},
                                           {64.f, 96.f},
                                           {128.f, 192.f, 256.f}},//min_boxes
                                          {8.0f, 16.0f, 32.0f, 64.0f},//strides
                                          {{1.0, 1.0}},//aspect_ratios
                                          {{{"input", nullptr}}}, //InputNodes
                                          {{{"boxes", nullptr},   //OutputNodes
                                            {"scores", nullptr}}},
                                          {"BACKGROUND", "face"}};


/***
 * 人体检测模型参数
 */
static ObjectDetectionParam PERSON_MODEL = {MODEL_TYPE_TNN,
                                            320,
                                            320,
                                            true,
                                            true,
                                            true,
                                            0,
                                            {{32.f},
                                             {48.f},
                                             {64.f, 96.f},
                                             {128.f, 192.f, 256.f}},//min_boxes
                                            {8.0f, 16.0f, 32.0f, 64.0f},//strides
                                            {{1.0, 1.0}, {1.2, 1.5}, {1.0, 2.0}},//aspect_ratios
                                            {{{"input", nullptr}}}, //InputNodes
                                            {{{"boxes", nullptr},   //OutputNodes
                                              {"scores", nullptr}}},
                                            {"BACKGROUND", "person"}};
/***
 *  人脸和关键点检测参数
 */
static ObjectDetectionParam FACE_LANDMARK_MODEL = {MODEL_TYPE_TNN,
                                                   320,
                                                   320,
                                                   true,
                                                   true,
                                                   false,
                                                   5,
                                                   {{10.f, 16.f, 24.f},
                                                    {32.f, 48.f},
                                                    {64.f, 96.f},
                                                    {128.f, 192.f, 256.f}},//min_boxes
                                                   {8.0f, 16.0f, 32.0f, 64.0f},//strides
                                                   {{1.0, 1.0}},//aspect_ratios
                                                   {{{"input", nullptr}}}, //InputNodes
                                                   {{{"boxes", nullptr},   //OutputNodes
                                                     {"scores", nullptr},
                                                     {"landm", nullptr}}},
                                                   {"BACKGROUND", "face"}};


/***
 *  卡片检测参数
 */
static ObjectDetectionParam CARD_DET_MODEL = {MODEL_TYPE_TNN,
                                              320,
                                              320,
                                              true,
                                              true,
                                              true,
                                              0,
                                              {{16.f},
                                               {32.f, 48.f},
                                               {64.f, 96.f},
                                               {128.f, 192.f, 256.f}},//min_boxes
                                              {8.0f, 16.0f, 32.0f, 64.0f},//strides
                                              {{1.0, 1.0}, {1.2, 1.5}, {1.0, 2.0}, {1.5, 1.2},
                                               {2.0, 1.0}},//aspect_ratios
                                              {{{"input", nullptr}}}, //InputNodes
                                              {{{"boxes", nullptr},   //OutputNodes
                                                {"scores", nullptr}}},
                                              {"BACKGROUND", "card"}};


/***
 *  卡片检测参数
 */
static ObjectDetectionParam RETAILS_DET_MODEL = {MODEL_TYPE_TNN,
                                                 320,
                                                 160,
                                                 true,
                                                 true,
                                                 true,
                                                 0,
                                                 {{10.f, 16.f},
                                                  {24.f, 32.f,},
                                                  {48.f, 64.f, 96.f},
                                                  {128.f, 192.f, 256.f}},//min_boxes
                                                 {8.0f, 16.0f, 32.0f, 64.0f},//strides
                                                 {{1.0, 1.0}, {1.2, 1.5}, {1.5, 1.2}, {1.0, 2.0},
                                                  {2.0, 1.0}},//aspect_ratios
                                                 {{{"input", nullptr}}}, //InputNodes
                                                 {{{"boxes", nullptr},   //OutputNodes
                                                   {"scores", nullptr}}},
                                                 {"BACKGROUND", "retails"}};


static ObjectDetectionParam MODEL_TYPE[] = {
        FACE_MODEL,
        FACE_LANDMARK_MODEL,
        PERSON_MODEL,
        FACE_PERSON_MODEL,
};


namespace dl {
    namespace vision {
        class ObjectDetection {
        public:
            /***
             * 构造函数，初始化SSD检测模型
             * @param modelPath: TNN *.tnnmodel参数文件路径（含后缀名）
             * @param protoPath: TNN *.tnnproto模型文件路径（含后缀名）
             * @param param：模型输入参数
             * @param numThread:  开启线程数
             * @param TNNDevice: 运行设备，默认TNNCPU
             */
            ObjectDetection(const string modelPath,
                            const string protoPath,
                            ObjectDetectionParam param,
                            int numThread = 1,
                            DeviceType device = CPU);

            /***
             * release
             */
            ~ObjectDetection();

            /***
             * 目标检测
             * @param imgBRG： 输入BGR图片
             * @param frameInfo： 输出/输出目标检测结果
             * @param scoreThresh： 置信度阈值，取值0~1.0，默认0.5
             * @param iouThresh：   NMS的IOU阈值，取值0~1.0，默认0.3
             * @return
             */
            int detect(cv::Mat imgBRG, FrameInfo *frameInfo, float scoreThresh = 0.5, float iouThresh = 0.3);

            /***
             * 可视化检测结果
             * @param imgBRG: BGR Image
             * @param frameInfo:
             * @param waitKey: 等待key的时间，默认0
             */
            void visualizeResult(cv::Mat &imgBRG, FrameInfo *frameInfo, int waitKey = 0);

        private:

            /***
             * 初始化TNNInterpreter
             * @param modelPath
             * @param protoPath
             * @param use_rgb
             * @param numThread
             * @param device
             * @return
             */
            int initInterpreter(const string modelPath,
                                const string protoPath,
                                bool use_rgb,
                                int numThread,
                                DeviceType device);

            /***
             * 
             * @param image 
             * @param tensor 
             */
            void preProcessing(cv::Mat &imgBGR, NetNodes *inputNodes);


            /***
             * 
             * @param scores 
             * @param boxes 
             * @param landmarks 
             * @param scoreThresh 
             * @param iouThresh 
             * @param outInfo 
             */
            void postProcessing(NetNodes *outputNodes,
                                float scoreThresh,
                                float iouThresh,
                                vector<ObjectInfo> &outInfo);

            /***
             * 
             * @param bbox_collection 
             * @param boxes 
             * @param score 
             * @param landmarks 
             * @param scoreThresh 
             */
            void generateFaceInfo(vector<ObjectInfo> &bbox_collection,
                                  NetNodes *outputNodes,
                                  float scoreThresh = 0.5);

            /***
             * 
             * @param inputInfo
             * @param outInfo
             * @param iouThresh
             * @param type 
             */
            void nms(vector<ObjectInfo> &inputInfo,
                     vector<ObjectInfo> &outInfo,
                     float iouThresh,
                     int type = hard_nms);

            /***
             * 产生anchor
             */
            void generateAnchors();

        public:
            float time_total{0.0f};           // 模型检测总共时间
            float time_pre_process{0.0f};     // 模型预处理时间
            float time_model_infer{0.0f};     // 模型推理时间
            float time_post_process{0.0f};    // 模型后处理时间

        private:
            const string TAG = "SSDdDetectionCpp";
            NetNodes mInputNodes;
            NetNodes mOutputNodes;

            Interpreter *interpreter = nullptr;
            ObjectDetectionParam mParam;
            int mSrcWidth, mSrcHeight;
            int mInputWidth, mInputHeight;
            int mNumAnchors, mNumLandmarks;
            int mNumFeatureMap{4};

            const float center_variance = 0.1;
            const float size_variance = 0.2;
            // for older model
            //vector<float> bias = {-104.f/1.0, -117.f/1.0, -123.f/1.0,0};
            //vector<float> scale = {1.0, 1.0, 1.0,0};
            // for new model
            // scale=1/std/255 , bias=-m/std
            vector<float> bias = {-127.f / 128, -127.f / 128, -127.f / 128, 0.f};
            vector<float> scale = {1.f / 128, 1.f / 128, 1.f / 128, 0.f};
            vector<vector<float>> priors;
        };
    }
}

#endif //FACE_RECOGNITION_FACE_DETECTION_H
