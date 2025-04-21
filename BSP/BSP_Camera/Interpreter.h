#ifndef DETECTOR_INTERPRETER_H
#define DETECTOR_INTERPRETER_H

#include <tnn/utils/blob_converter.h>
#include <tnn/core/tnn.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace std;
#ifdef  TNN_ARM_ENABLE
static TNN_NS::DeviceType DEVICE_CPU = TNN_NS::DEVICE_ARM;
#else
static TNN_NS::DeviceType DEVICE_CPU = TNN_NS::DEVICE_NAIVE;
#endif

#ifdef  TNN_OPENCL_ENABLE
static TNN_NS::DeviceType DEVICE_GPU = TNN_NS::DEVICE_OPENCL;
#else
static TNN_NS::DeviceType DEVICE_GPU = TNN_NS::DEVICE_CUDA;
#endif

/***
 * TNN设备
 */
typedef enum {
    // run on CPU
    CPU = 0,
    // run on GPU, if failed run on CPU(需要OpenCL支持)
    GPU = 1,
    // run on NPU, if failed run on CPU(暂不支持NPU)
    NPU = 2,
} DeviceType;


/***
 * TNN模型
 */
typedef enum {
    MODEL_TYPE_TNN = 0x0001,
    MODEL_TYPE_NCNN = 0x0100,
    MODEL_TYPE_OPENVINO = 0x1000,
    MODEL_TYPE_COREML = 0x2000,
    MODEL_TYPE_SNPE = 0x3000,
    MODEL_TYPE_HIAI = 0x4000,
    MODEL_TYPE_ATLAS = 0x5000,
    MODEL_TYPE_RKCACHE = 0x6000
} ModelType;

/***
 * 模型参数
 */
struct NetParam {
    ModelType model_type;                  // 模型类型，MODEL_TYPE_TNN，MODEL_TYPE_NCNN等
    int input_width;                       // 模型输入宽度，单位：像素
    int input_height;                      // 模型输入高度，单位：像素
    bool use_rgb;                          // 是否使用RGB作为模型输入（PS：接口固定输入BGR，use_rgb=ture时，预处理将BGR转换为RGB）
    bool reverse_channel;                  // 设置是否翻转channel的位置BCHW
    vector<float> scale;                   // 数据预处理函数的参数：计算公式formular: y = scale*x + bias
    vector<float> bias;

};


/***
 * 节点名称
 */
struct NetNode {
    string name;
    shared_ptr<TNN_NS::Mat> tensor;
};

struct NetNodes {
    vector<NetNode> nodes;
};


/***
 * 打印tensor的数值
 */
template<typename TYPE>
void print_tensor(shared_ptr<TNN_NS::Mat> tensor, int c0 = 0, int h0 = 0, int w0 = 0, string tag = "v");

/***
 * TNN解析器
 */
class Interpreter {
public:
    /***
     * 初始化解析器
     * @param modelPath: *.tnnmodel参数文件路径（含后缀名）
     * @param protoPath: *.tnnproto模型文件路径（含后缀名）
     * @param inputWidth 模型输入宽度，单位：像素
     * @param inputHeight 模型输入高度，单位：像素
     * @param numThread 开启线程数
     * @param device  运行设备，默认CPU
     */
    Interpreter(const string &modelPath,
                const string &protoPath,
                NetParam netParam,
                int numThread,
                DeviceType device);

    /***
     * 析构函数
     */
    ~Interpreter();

    /***
     * 进行预处理，将输入imgBGR处理为模型输入的格式，并把数据保存在输入节点inputNodes
     * @param imgBGR 输入检测的图片BGR格式
     * @param inputNodes 模型输入节点
     * @return
     */
    int preProcessing(cv::Mat &imgBGR, NetNodes *inputNodes);

    /***
     * 行后处理，并把数据保存在输出节点outputNodes
     * @param outputNodes
     * @return
     */
    int postProcessing(NetNodes *outputNodes);

    /***
     * 进行模型推理
     * @param inputNodes  模型输入的节点数据
     * @param outputNodes 模型输出的节点数据
     * @return
     */
    int forward(NetNodes *inputNodes, NetNodes *outputNodes);


    /***
     * 进行模型检测
     * @param imgBRG 模型输入的检测图片
     * @param outputNodes 模型输出的节点数据
     * @return
     */
    int detect(cv::Mat &imgBRG, NetNodes *outputNodes);


private:
    /***
     * 初始化TNN解析器
     * @param modelPath
     * @param protoPath
     * @param numThread
     * @param device
     * @return
     */
    int initModel(const string &modelPath,
                  const string &protoPath,
                  int numThread,
                  DeviceType device);


public:
    const string TAG = "TNNInterpreter";
    float time_total{0.0f};           // 模型检测总共时间
    float time_pre_process{0.0f};     // 模型预处理时间
    float time_model_infer{0.0f};     // 模型推理时间
    float time_post_process{0.0f};    // 模型后处理时间

    shared_ptr<TNN_NS::Instance> instance = nullptr;
    TNN_NS::DeviceType device;  // 运行实例设备
    NetParam param;
};


#endif //DETECTOR_INTERPRETER_H
