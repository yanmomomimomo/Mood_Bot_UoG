//
// Created by 390737991@qq.com on 2020/6/3.
//


#include "Interpreter.h"
#include "debug.h"
#include "file_utils.h"

Interpreter::Interpreter(const string &modelPath,
                         const string &protoPath,
                         NetParam netParam,
                         int numThread,
                         DeviceType device) {
    this->param = netParam;
    int ret = this->initModel(modelPath, protoPath, numThread, device);
    if (ret == 0) {
        LOGI("TNN init successfully");
    } else {
        LOGI("TNN init failed");
    }
}

Interpreter::~Interpreter() {
    if (this->instance != nullptr) {
        this->instance->DeInit();
        this->instance = nullptr;
    }
}


int Interpreter::initModel(const string &modelPath,
                           const string &protoPath,
                           int numThread,
                           DeviceType device) {
    //vector<int> nchw = {1, 3, this->mInputHeight, this->mInputWidth};
    vector<int> nchw = {1, 3, this->param.input_height, this->param.input_width};
    string protoContent, modelContent;

    if (!file_exists(modelPath)) {
        LOGI("no tnnmodel file:%s", modelPath.c_str());
        return -1;

    }
    if (!file_exists(protoPath)) {
        LOGI("no tnnproto file:%s", protoPath.c_str());
        return -1;
    }
    LOGI("load tnnproto %s", protoPath.c_str());
    LOGI("load tnnmodel %s", modelPath.c_str());
    protoContent = load_file(protoPath);
    modelContent = load_file(modelPath);
    LOGI("tnnproto len=%d", protoContent.length());
    LOGI("tnnmodel len=%d", modelContent.length());
    this->device = device == GPU ? DEVICE_GPU : DEVICE_CPU;

    TNN_NS::Status status;
    TNN_NS::ModelConfig config;
    // config.model_type = TNN_NS::MODEL_TYPE_TNN;
    // config.model_type = TNN_NS::MODEL_TYPE_NCNN;
    config.model_type = static_cast<tnn::ModelType>(this->param.model_type);
    config.params = {protoContent, modelContent};
    shared_ptr<TNN_NS::TNN> tnn_net = make_shared<TNN_NS::TNN>();
    status = tnn_net->Init(config);
    if (status != TNN_NS::TNN_OK) {
        LOGI("TNN init failed %d,%s", (int) status,status.description().c_str());
        return -1;
    }

    TNN_NS::InputShapesMap shapeMap;
    shapeMap.insert(pair<string, TNN_NS::DimsVector>("input", nchw));
    //instance
    TNN_NS::NetworkConfig net_config;
    net_config.library_path = {""};
    net_config.device_type = this->device;
    //net_config.cache_path = "/sdcard/";
    //net_config.enable_tune_kernel  = true;
    //network_config.precision = tnn::PRECISION_HIGH;
    instance = tnn_net->CreateInst(net_config, status, shapeMap);
    if (device == CPU) {
        // fix a BUG:Error Init layer Clip_131 (err: 40966 or 0xA006)
        instance->SetCpuNumThreads(std::max(numThread, 1));
    }
    if (status != TNN_NS::TNN_OK || !instance) {
        LOGI("DEVICE_GPU:%d initialization failed, switch to DEVICE_CPU", this->device);
        // 如果出现GPU加载失败，切换到CPU
        this->device = DEVICE_CPU;
        net_config.device_type = this->device;
        instance = tnn_net->CreateInst(net_config, status, shapeMap);
        instance->SetCpuNumThreads(std::max(numThread, 1));
        if (status != TNN_NS::TNN_OK) {
            LOGI("TNN init failed %d,%s", (int) status,status.description().c_str());
            return -1;
        }
    }
    return status == TNN_NS::TNN_OK ? 0 : -1;
}


int Interpreter::preProcessing(cv::Mat &imgBGR, NetNodes *inputNodes) {
    // 数据始终位于CPU，不需要设置成OPENCL，tnn自动复制cpu->gpu
    //TNN_NS::DimsVector target_dims = {1, 3, this->mInputHeight, this->mInputWidth};
    TNN_NS::DimsVector target_dims = {1, 3, this->param.input_height, this->param.input_width};
    //LOGW("instance device:%d", this->device);
    //LOGW("data device    :%d", DEVICE_CPU);
    cv::Mat input;
    cv::resize(imgBGR, input, cv::Size(this->param.input_width, this->param.input_height));
    if (this->param.use_rgb) {
        cv::cvtColor(input, input, cv::COLOR_BGR2RGB);
    }
    for (auto &nodes:inputNodes->nodes) {
        nodes.tensor = make_shared<TNN_NS::Mat>(DEVICE_CPU, TNN_NS::N8UC3, target_dims, input.data);
        // step 1. set input mat
        TNN_NS::MatConvertParam input_convert_param;
        input_convert_param.scale = this->param.scale;
        input_convert_param.bias = this->param.bias;
        input_convert_param.reverse_channel = this->param.reverse_channel;
        // TNN初始化时设置CPU或者GPU模式
        auto status = instance->SetInputMat(inputNodes->nodes.at(0).tensor, input_convert_param);
        if (status != TNN_NS::TNN_OK) {
            LOGE("SetInputMat Error: %s", status.description().c_str());
            return status;
        }
    }
    return 0;
}

int Interpreter::postProcessing(NetNodes *outputNodes) {
    // TO DO
    return 0;
}


int Interpreter::detect(cv::Mat &imgBRG, NetNodes *outputNodes) {
    if (imgBRG.empty()) {
        LOGI("image is empty ,please check!");
        return 0;
    }
    // preProcessing
    DEBUG_TIME(t0);
    NetNodes *inputNodes;
    preProcessing(imgBRG, inputNodes);
    DEBUG_TIME(t1);
    // Inference and extract results
    forward(inputNodes, outputNodes);
    DEBUG_TIME(t2);
    // post_process
    postProcessing(outputNodes);
    DEBUG_TIME(t3);
    this->time_pre_process = RUN_TIME(t1 - t0);
    this->time_model_infer = RUN_TIME(t2 - t1);
    this->time_post_process = RUN_TIME(t3 - t2);
    this->time_total = RUN_TIME(t3 - t0);
    LOGW("===================TNNInterpreter========================");
    LOGW("-->pre_process  : %3.5f ms", this->time_pre_process);
    LOGW("-->model_infer  : %3.5f ms", this->time_model_infer);
    LOGW("-->post_process : %3.5f ms", this->time_post_process);
    LOGW("-->avg_total    : %3.5f ms", this->time_total);
    LOGW("==========================================================");
    return 0;
}


int Interpreter::forward(NetNodes *inputNodes, NetNodes *outputNodes) {
    // step 2. Forward
    auto status = instance->ForwardAsync(nullptr);
    //status = instance->Forward();
    if (status != TNN_NS::TNN_OK) {
        LOGE("Forward Error: %s", status.description().c_str());
        return status;
    }
    for (auto &nodes:outputNodes->nodes) {
        TNN_NS::MatConvertParam output_convert_param;
        //shared_ptr<TNN_NS::Mat> output_tensor = nullptr;
        status = instance->GetOutputMat(nodes.tensor, output_convert_param,
                                        nodes.name,
                                        DEVICE_CPU,
                                        TNN_NS::NCHW_FLOAT);
        //print_tensor<float>(nodes.tensor, 0, 0, 0, nodes.name);
        if (status != TNN_NS::TNN_OK) {
            LOGE("GetOutputMat Error: %s", status.description().c_str());
            return status;
        }
    }
    return status;
}

template<typename TYPE>
void print_tensor(shared_ptr<TNN_NS::Mat> tensor, int c0, int h0, int w0, string tag) {
    //三维数组维展a[C][H][W],下标为a[c][j][i]，则一维表达式为a[(c*H+j)*W+i]
    int channel = tensor->GetChannel();
    int height = tensor->GetHeight();
    int width = tensor->GetWidth();
    auto *data = (TYPE *) tensor->GetData();//(batch size,NumAnchors,nun_class,1)
    const TYPE *ptr = &data[0];
    for (int c = c0; c < channel; c++) {
        for (int j = h0; j < height; ++j) {
            for (int i = w0; i < width; ++i) {
                auto v = ptr[(c * height + j) * width + i];
                printf("%s[%d][%d][%d]=", tag.c_str(), c, j, i);
                cout << v << endl;
            }
            printf("---------------------------\n");
        }
        printf("===============================\n");
    }
}
