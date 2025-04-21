#ifndef SITTING_CLASSIFICATION_TNN_ANDROID_CLASSIFICATION_H
#define SITTING_CLASSIFICATION_TNN_ANDROID_CLASSIFICATION_H
#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "Types.h"
#include "Interpreter.h"

using namespace std;

/***
 * SSD Detection Model Param
 */
struct ClassificationParam {
    ModelType model_type;                  // 模型类型，MODEL_TYPE_TNN，MODEL_TYPE_NCNN等
    int input_width;                       // 模型输入宽度，单位：像素
    int input_height;                      // 模型输入高度，单位：像素
    bool use_rgb;                          // 是否使用RGB作为模型输入（PS：接口固定输入BGR，use_rgb=ture时，预处理将BGR转换为RGB）
    NetNodes InputNodes;                   // 输入节点名称
    NetNodes OutputNodes;                  // 输出节点名称
    vector<float> box_scale;               // box缩放倍数(width，height),如{1.2，1.2}
    vector<string> class_names;            // 类别集合
};


/***
 *  坐姿分类模型参数
 */
static ClassificationParam SITTING_MODEL = {MODEL_TYPE_TNN,
                                            128,
                                            128,
                                            true,
                                            {{{"input", nullptr}}}, //InputNodes
                                            {{{"output", nullptr}}},
                                            {1.2, 1.2},
                                            {"0_straight", "1_leaning", "2_others"}};


/***
 *  戴口罩分类模型参数
 */
static ClassificationParam FACE_MASK_MODEL = {MODEL_TYPE_TNN,
                                              128,
                                              128,
                                              true,
                                              {{{"input", nullptr}}}, //InputNodes
                                              {{{"output", nullptr}}},
                                              {1.1, 1.1},
                                              {"nomask", "mask", ""}};

/***
 *  表情识别模型参数
 */
static ClassificationParam EMOTION_MODEL = {MODEL_TYPE_TNN,
                                            112,
                                            112,
                                            true,
                                            {{{"input", nullptr}}}, //InputNodes
                                            {{{"output", nullptr}}},
                                            {1.1, 1.1},
                                            {"angry", "disgust", "fear", "happy", "neutral", "sad", "surprise"}};


/***
 *  疲劳驾驶分类模型参数(drowsy)
 */
static ClassificationParam DROWSY_MODEL = {MODEL_TYPE_TNN,
                                           112,
                                           112,
                                           true,
                                           {{{"input", nullptr}}}, //InputNodes
                                           {{{"output", nullptr}}},
                                           {1.0, 1.0},
                                           {"undrowsy", "drowsy"}};


/***
 *  卡片分类模型参数
 */
static ClassificationParam CARD_CLS_MODEL = {MODEL_TYPE_TNN,
                                             112,
                                             112,
                                             true,
                                             {{{"input", nullptr}}}, //InputNodes
                                             {{{"output", nullptr}}},
                                             {1.0, 1.0},
                                             {""}};

namespace dl {
    namespace vision {
        class Classification {
        public:
            /***
             * 构造函数，初始化Classification检测模型
             * @param modelPath: TNN *.tnnmodel参数文件路径（含后缀名）
             * @param protoPath: TNN *.tnnproto模型文件路径（含后缀名）
             * @param param：模型输入参数
             * @param numThread:  开启线程数
             * @param DeviceType: 运行设备，默认TNNCPU
             */
            Classification(const string modelPath,
                           const string protoPath,
                           ClassificationParam param,
                           int numThread = 1,
                           DeviceType device = CPU);

            /***
             * release
             */
            ~Classification();

            /***
             * 图像分类
             * @param imgBRG： 输入BGR图片
             * @param frameInfo： 输出/输出目标检测结果
             * @param scoreThresh： 置信度阈值，取值0~1.0，默认0.5
             * @param iouThresh：   NMS的IOU阈值，取值0~1.0，默认0.3
             * @return
             */
            int detect(cv::Mat imgBRG, FrameInfo *frameInfo);

            /***
             * 可视化检测结果
             * @param imgBRG: BGR Image
             * @param frameInfo:
             * @param waitKey: 等待key的时间，默认0
             */
            int visualizeResult(cv::Mat &imgBRG, FrameInfo *frameInfo, int waitKey = 0);

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
            int initTNNInterpreter(const string modelPath,
                                   const string protoPath,
                                   bool use_rgb,
                                   int numThread,
                                   DeviceType device);

            /***
             *
             * @param image
             * @param tensor
             */
            void preProcessing(cv::Mat &imgBGR, ObjectInfo *objectInfo, NetNodes *inputNodes);


            /***
             *
             * @param scores
             * @param boxes
             * @param landmarks
             * @param scoreThresh
             * @param iouThresh
             * @param outInfo
             */
            void postProcessing(NetNodes *outputNodes, Category *category);

        public:
            float time_total{0.0f};           // 模型检测总共时间
            float time_pre_process{0.0f};     // 模型预处理时间
            float time_model_infer{0.0f};     // 模型推理时间
            float time_post_process{0.0f};    // 模型后处理时间

        private:
            const string TAG = "ClassificationCpp";
            NetNodes mInputNodes;
            NetNodes mOutputNodes;
            Interpreter *interpreter = nullptr;
            ClassificationParam mParam;
            int mInputWidth, mInputHeight;
            // scale=1/std/255 , bias=-m/std
            vector<float> bias = {-0.5 / 0.5, -0.5 / 0.5, -0.5 / 0.5, 0.f};
            vector<float> scale = {1.f / 0.5 / 255, 1.f / 0.5 / 255, 1.f / 0.5 / 255, 0.f};
        };
    }
}

#endif //SITTING_CLASSIFICATION_TNN_ANDROID_CLASSIFICATION_H
