#include "classification.h"
#include "debug.h"
#include "file_utils.h"
#include "image_utils.h"
#include "math_utils.h"

#define clip(x, y) (x < 0 ? 0 : (x > y ? y : x))


namespace dl {
    namespace vision {

        Classification::Classification(const string modelPath,
                                       const string protoPath,
                                       ClassificationParam param,
                                       int numThread,
                                       DeviceType device) {
            mParam = param;
            mInputWidth = param.input_width;
            mInputHeight = param.input_height;
            mInputNodes = param.InputNodes;
            mOutputNodes = param.OutputNodes;
            initTNNInterpreter(modelPath, protoPath, param.use_rgb, numThread, device);

        }

        Classification::~Classification() {
            if (this->interpreter != nullptr) {
                delete interpreter;
                interpreter = nullptr;
            }
        }

        int Classification::initTNNInterpreter(const string modelPath,
                                               const string protoPath,
                                               bool use_rgb,
                                               int numThread,
                                               DeviceType device) {
            NetParam netParam = {mParam.model_type,
                                 mParam.input_width,
                                 mParam.input_height,
                                 use_rgb,
                                 false,
                                 this->scale,
                                 this->bias};
            interpreter = new Interpreter(modelPath, protoPath,
                                          netParam,
                                          numThread, device);
            return 0;
        }


        int Classification::detect(cv::Mat imgBRG, FrameInfo *frameInfo) {
            this->time_pre_process = 0.f;
            this->time_model_infer = 0.f;
            this->time_post_process = 0.f;
            this->time_total = 0.f;
            if (imgBRG.empty()) {
                LOGI("image is empty ,please check!");
                return 0;
            }

            int nums = frameInfo->info.size();
            DEBUG_TIME(t0);
            for (int i = 0; i < nums; ++i) {
                // preProcessing
                DEBUG_TIME(t1);
                preProcessing(imgBRG, &frameInfo->info.at(i), &this->mInputNodes);
                DEBUG_TIME(t2);
                // Inference and extract results
                interpreter->forward(&this->mInputNodes, &this->mOutputNodes);
                DEBUG_TIME(t3);
                // post_process
                postProcessing(&this->mOutputNodes, &frameInfo->info.at(i).category);
                DEBUG_TIME(t4);
                this->time_pre_process += RUN_TIME(t2 - t1);
                this->time_model_infer += RUN_TIME(t3 - t2);
                this->time_post_process += RUN_TIME(t4 - t3);
            }
            DEBUG_TIME(t5);
            this->time_total = RUN_TIME(t5 - t0);
            /*
            LOGW("===================Classification====================");
            LOGW("-->pre_process  : %3.5f/%d=%3.5f ms", this->time_pre_process, nums, this->time_pre_process / nums);
            LOGW("-->model_infer  : %3.5f/%d=%3.5f ms", this->time_model_infer, nums, this->time_model_infer / nums);
            LOGW("-->post_process : %3.5f/%d=%3.5f ms", this->time_post_process, nums, this->time_post_process / nums);
            LOGW("-->avg_total    : %3.5f/%d=%3.5f ms", this->time_total, nums, this->time_total / nums);
            LOGW("====================================================");
            */
            return 0;
        }


        void Classification::preProcessing(cv::Mat &imgBGR, ObjectInfo *objectInfo, NetNodes *inputNodes) {
            // 128--->112
            cv::Rect2f rect(objectInfo->x1, objectInfo->y1,
                            objectInfo->x2 - objectInfo->x1,
                            objectInfo->y2 - objectInfo->y1);
            rect = extend_rect(rect, mParam.box_scale.at(0), mParam.box_scale.at(1));

            // ✅ 限制在图像有效区域
            rect &= cv::Rect2f(0, 0, imgBGR.cols, imgBGR.rows);

            // 检查 rect 是否有效（宽高大于 0）
            if (rect.width <= 1 || rect.height <= 1) {
                // std::cerr << "⚠️ 无效 rect，跳过当前目标，rect=" << rect << std::endl;
                return;
            }
            //objectInfo->x1 = rect.x;
            //objectInfo->y1 = rect.y;
            //objectInfo->x2 = rect.x + rect.width;
            //objectInfo->y2 = rect.y + rect.height;
            cv::Mat crop = image_crop(imgBGR, rect);
            if (crop.empty()) {
                std::cerr << "⚠️ crop image is empty! rect=" << rect << std::endl;
                return;
            }
            
            cv::resize(crop, crop, cv::Size(int(128.f * mParam.input_width / 112),
                                            int(128.f * mParam.input_height / 112)));
            crop = image_center_crop(crop, mParam.input_width, mParam.input_height);
            //image_show("crop",crop);
            interpreter->preProcessing(crop, inputNodes);
        }


        void Classification::postProcessing(NetNodes *outputNodes, Category *category) {
            auto output_tensor = outputNodes->nodes.at(0).tensor;
            int size = output_tensor->GetChannel();
            auto *data = (float *) output_tensor->GetData();// (batch size,NumAnchors,4,1)
            const float *output_ptr = &data[0];
            vector<float> output;
            for (int i = 0; i < size; i++) {
                output.push_back(output_ptr[i]);
            }
            vector<float> scores;
            softmax(output, scores, category->label, category->score);
            // PRINT_VECTOR("output:", output);
            // PRINT_VECTOR("scores:", scores);
        }

        static int Com_Gener(float x, float y, std::string label){
            int result;
            if(label == "happy" || label == "surprise"){
                result = 3;
            }else if (label == "sad"){
                result = 2;
            }else if (label =="disgust"){
                result = 4;
            }else{ result = 1;}
            
            if(x<450){
                result = result*10+1;
            }else if(x>750){
                result = result*10+2;
            }else{result = result*10 + 0;}

            if(y<210){
                result = result*10+1;
            }else if(y>500){
                result = result*10+2;
            }else{result = result*10 + 0;}
            return result;
        }

        int Classification::visualizeResult(cv::Mat &imgBRG,
                                             FrameInfo *frameInfo,
                                             int waitKey) {
            int value;
            float x_av, y_av;
            std::string name_s;
            // LOGD("label:%d,score:%3.5f", frameInfo->label, frameInfo->score);
            // string labels = to_string(frameInfo->label) + ":" + to_string(frameInfo->score);
            printf("%d",frameInfo->info.size());
            for (int i = 0; i < frameInfo->info.size(); i++) {
                auto obj = frameInfo->info.at(i);
                cv::Rect rect(obj.x1, obj.y1, obj.x2 - obj.x1, obj.y2 - obj.y1);
                //string name = to_string(obj.label) + ":" + to_string(obj.score);
                //string name = to_string(obj.category.label) + "," + to_string(obj.category.score);
                string name = mParam.class_names[obj.category.label] + "," + to_string(obj.category.score).substr(0, 5);
                cv::Scalar c = COLOR_TABLE[obj.category.label % COLOR_TABLE.size()];
                draw_rect_text(imgBRG, rect, name, c, 2, 1.2);
                draw_points_texts(imgBRG, obj.landmarks);
                // LOGD("i=%d,det=[%3.5f,%3.5f,%3.5f,%3.5f,%3.5f],category=[%s]", i, obj.x1, obj.y1, obj.x2, obj.y2,
                //      obj.score, name.c_str());
                x_av = (obj.x1 + obj.x2)/2;
                y_av = (obj.y1 + obj.y2)/2;
                name_s = mParam.class_names[obj.category.label];
            }
            value = Com_Gener(x_av, y_av, name_s);

            return value;
            // cv::namedWindow("result", cv::WINDOW_NORMAL);
            // cv::imshow("result", imgBRG);
            // cv::waitKey(waitKey);
        }
    }
}
