//
// Created by 390737991@qq.com on 2020/6/3.
//

#include "object_detection.h"
#include "debug.h"
#include "file_utils.h"
#include "image_utils.h"

#define clip(x, y) (x < 0 ? 0 : (x > y ? y : x))


namespace dl {
    namespace vision {

        ObjectDetection::ObjectDetection(const string modelPath,
                                         const string protoPath,
                                         ObjectDetectionParam param,
                                         int numThread,
                                         DeviceType device) {
            mParam = param;
            mNumLandmarks = param.num_landmarks;
            mInputWidth = param.input_width;
            mInputHeight = param.input_height;
            mInputNodes = param.InputNodes;
            mOutputNodes = param.OutputNodes;
            this->generateAnchors();

            initInterpreter(modelPath, protoPath, param.use_rgb, numThread, device);

        }

        ObjectDetection::~ObjectDetection() {
            priors.clear();
            vector<vector<float>>().swap(priors);
            if (this->interpreter != nullptr) {
                delete interpreter;
                interpreter = nullptr;
            }
        }

        int ObjectDetection::initInterpreter(const string modelPath,
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


        int ObjectDetection::detect(cv::Mat imgBRG, FrameInfo *frameInfo, float scoreThresh, float iouThresh) {
            if (imgBRG.empty()) {
                LOGI("image is empty ,please check!");
                return 0;
            }
            // preProcessing
            DEBUG_TIME(t0);
            preProcessing(imgBRG, &this->mInputNodes);
            DEBUG_TIME(t1);
            // Inference and extract results
            interpreter->forward(&this->mInputNodes, &this->mOutputNodes);
            DEBUG_TIME(t2);
            // post_process
            postProcessing(&this->mOutputNodes, scoreThresh, iouThresh, frameInfo->info);
            DEBUG_TIME(t3);
            this->time_pre_process = RUN_TIME(t1 - t0);
            this->time_model_infer = RUN_TIME(t2 - t1);
            this->time_post_process = RUN_TIME(t3 - t2);
            this->time_total = RUN_TIME(t3 - t0);
            LOGW("===================ObjectDetection========================");
            LOGW("-->pre_process  : %3.5f ms", this->time_pre_process);
            LOGW("-->model_infer  : %3.5f ms", this->time_model_infer);
            LOGW("-->post_process : %3.5f ms", this->time_post_process);
            LOGW("-->avg_total    : %3.5f ms", this->time_total);
            LOGW("==========================================================");
            return 0;
        }


        void ObjectDetection::generateAnchors() {
            priors.clear();
            vector<vector<float>>().swap(priors);
            vector<vector<float>> featuremap_size;
            vector<vector<float>> shrinkage_size;
            for (auto size :  {mInputWidth, mInputHeight}) {
                vector<float> fm_item;
                for (float stride : mParam.strides) {
                    fm_item.push_back(ceil(size / stride));
                }
                featuremap_size.push_back(fm_item);
            }

            vector<float> tmp_list1;
            vector<float> tmp_list2;
            for (int i = 0; i < 4; i++) {
                tmp_list1.push_back(mInputWidth / featuremap_size[0][i]);
                tmp_list2.push_back(mInputHeight / featuremap_size[1][i]);
            }
            shrinkage_size.push_back(tmp_list1);
            shrinkage_size.push_back(tmp_list2);

            /* generate prior anchors */
            for (int index = 0; index < mNumFeatureMap; index++) {
                float scale_w = mInputWidth / shrinkage_size[0][index];
                float scale_h = mInputHeight / shrinkage_size[1][index];
                for (int j = 0; j < featuremap_size[1][index]; j++) {
                    for (int i = 0; i < (featuremap_size[0][index]); i++) {
                        float x_center = (i + 0.5f) / scale_w;
                        float y_center = (j + 0.5f) / scale_h;

                        for (float k : mParam.min_boxes[index]) {
                            float w = k / mInputWidth;
                            float h = k / mInputHeight;
                            for (auto ratio: mParam.aspect_ratios) {
                                //priors.push_back({clip(x_center, 1.0f), clip(y_center, 1.0f), clip(w, 1), clip(h, 1)});
                                priors.push_back({clip(x_center, 1.0f), clip(y_center, 1.0f), clip(w * ratio[0], 1.0f),
                                                  clip(h * ratio[1], 1.0f)});

                            }

                        }
                    }
                }
            }
            mNumAnchors = priors.size();
            LOGI("Anchor Numbers:%d\n", mNumAnchors);
        }

        void ObjectDetection::preProcessing(cv::Mat &imgBGR, NetNodes *inputNodes) {
            // ex.set_num_threads(num_thread);
            mSrcHeight = imgBGR.rows;
            mSrcWidth = imgBGR.cols;
            // Determinate net_in_size
            if (mInputWidth <= 0 || mInputHeight <= 0) {
                if (mSrcWidth > mSrcHeight) {
                    mInputWidth = 1000;
                    mInputHeight = mSrcHeight * 1000 / mSrcWidth;
                } else {
                    mInputHeight = 1000;
                    mInputWidth = mSrcWidth * 1000 / mSrcHeight;
                }
                // 如果设置等比例输入图像，需要每次重新生成anchor
                // Generate anchors
                generateAnchors();
            }
            if (mParam.padding) {
                imgBGR = image_boxes_resize_padding(imgBGR, cv::Size(mInputWidth, mInputHeight),
                                                    cv::Scalar(114, 114, 114));
                //image_show("image", imgBGR, 10);
            }

            interpreter->preProcessing(imgBGR, inputNodes);
        }


        void ObjectDetection::postProcessing(NetNodes *outputNodes,
                                             float scoreThresh,
                                             float iouThresh,
                                             vector<ObjectInfo> &outInfo) {
            vector<ObjectInfo> bbox_collection;
            generateFaceInfo(bbox_collection, outputNodes, scoreThresh);
            nms(bbox_collection, outInfo, iouThresh);
            if (mParam.padding) {
                // 简单缩放回原图
                float scale_w = 1.0;
                float scale_h = 1.0;
                vector<cv::Box> boxes;//x1, y1, x2, y2, score
                vector<cv::Point2f> points;//x1, y1, x2, y2, score
                for (ObjectInfo &info : outInfo) {
                    info.x1 = info.x1 / scale_w;
                    info.x2 = info.x2 / scale_w;
                    info.y1 = info.y1 / scale_h;
                    info.y2 = info.y2 / scale_h;
                    boxes.push_back({info.x1, info.y1, info.x2, info.y2, info.score});
                    for (cv::Point2f &point : info.landmarks) {
                        points.push_back(point);
                    }

                }
                image_boxes_resize_padding_inverse(cv::Size(mSrcWidth, mSrcHeight),
                                                   cv::Size(mInputWidth, mInputHeight),
                                                   boxes, points);
                for (int i = 0; i < boxes.size(); i++) {
                    outInfo[i].x1 = boxes[i].x1;
                    outInfo[i].y1 = boxes[i].y1;
                    outInfo[i].x2 = boxes[i].x2;
                    outInfo[i].y2 = boxes[i].y2;
                    for (int n = 0; n < mNumLandmarks; n++) {
                        outInfo[i].landmarks[n].x = points[i * mNumLandmarks + n].x;
                        outInfo[i].landmarks[n].y = points[i * mNumLandmarks + n].y;
                    }
                }
            }
        }

        void ObjectDetection::generateFaceInfo(vector<ObjectInfo> &bbox_collection,
                                               NetNodes *outputNodes,
                                               float scoreThresh) {
            // 如果模型固化bboxes的后处理，则设置freeze_header=true
            // outputNodes：boxes,scores,ldmks
            float sw = mParam.padding ? mInputWidth : 1.0f * mSrcWidth;
            float sh = mParam.padding ? mInputHeight : 1.0f * mSrcHeight;

            auto boxes = outputNodes->nodes.at(0).tensor;
            auto scores = outputNodes->nodes.at(1).tensor;
            auto *bboxes_data = (float *) boxes->GetData();// (batch size,NumAnchors,4,1)
            auto *scores_data = (float *) scores->GetData();//(batch size,NumAnchors,nun_class,1)
            assert(mNumAnchors == scores->GetChannel()); //please check ModelParam input_width and input_height
            int num_class = scores->GetHeight();
            const float *bboxes_ptr = &bboxes_data[0];
            const float *scores_ptr = &scores_data[0];
            for (int i = 0; i < mNumAnchors; i++) {
                for (int k = 1; k < num_class; ++k) {
                    if (scores_ptr[i * num_class + k] > scoreThresh) {
                        ObjectInfo info;
                        info.label = k;
                        // Decode boxes
                        if (!mParam.freeze_header) {
                            //convert locations to center boxes
                            float x_center = bboxes_ptr[i * 4] * center_variance * priors[i][2] + priors[i][0];
                            float y_center = bboxes_ptr[i * 4 + 1] * center_variance * priors[i][3] + priors[i][1];
                            float w = exp(bboxes_ptr[i * 4 + 2] * size_variance) * priors[i][2];
                            float h = exp(bboxes_ptr[i * 4 + 3] * size_variance) * priors[i][3];
                            //convert  center boxes to corner boxes
                            info.x1 = clip(x_center - w / 2.0, 1) * sw;
                            info.y1 = clip(y_center - h / 2.0, 1) * sh;
                            info.x2 = clip(x_center + w / 2.0, 1) * sw;
                            info.y2 = clip(y_center + h / 2.0, 1) * sh;

                            info.x1 = clip(x_center - w / 2.0, 1) * sw;
                            info.y1 = clip(y_center - h / 2.0, 1) * sh;
                            info.x2 = clip(x_center + w / 2.0, 1) * sw;
                            info.y2 = clip(y_center + h / 2.0, 1) * sh;
                        } else {
                            info.x1 = clip(bboxes_ptr[i * 4], 1) * sw;
                            info.y1 = clip(bboxes_ptr[i * 4 + 1], 1) * sh;
                            info.x2 = clip(bboxes_ptr[i * 4 + 2], 1) * sw;
                            info.y2 = clip(bboxes_ptr[i * 4 + 3], 1) * sh;
                        }
                        info.score = clip(scores_ptr[i * num_class + k], 1.f);

                        //Decode landmarks
                        for (int j = 0; j < mNumLandmarks; j++) {
                            auto landmarks = outputNodes->nodes.at(2).tensor;
                            auto *landms_data = (float *) landmarks->GetData();// dim=(1,num_anchors,2,1) NCHW
                            const float *landms_ptr = &landms_data[0];
                            // float tmp_x = landmarks.channel(0)[i * 2 * num_landmarks + j * 2];
                            // float tmp_y = landmarks.channel(0)[i * 2 * num_landmarks + j * 2 + 1];
                            float tmp_x = landms_ptr[i * 2 * mNumLandmarks + j * 2];
                            float tmp_y = landms_ptr[i * 2 * mNumLandmarks + j * 2 + 1];
                            if (!mParam.freeze_header) {
                                tmp_x = clip(priors[i][0] + tmp_x * center_variance * priors[i][2], 1);
                                tmp_y = clip(priors[i][1] + tmp_y * center_variance * priors[i][3], 1);
                            }
                            tmp_x = tmp_x * sw;
                            tmp_y = tmp_y * sh;
                            cv::Point2f tmp_point;
                            tmp_point.x = tmp_x;
                            tmp_point.y = tmp_y;
                            info.landmarks.push_back(tmp_point);
                        }
                        // LOGI("freeze_decode:%d\n",freeze_decode);
                        bbox_collection.push_back(info);
                    }

                }
            }
        }

        void ObjectDetection::nms(vector<ObjectInfo> &inputInfo,
                                  vector<ObjectInfo> &outInfo,
                                  float iouThresh,
                                  int type) {
            std::sort(inputInfo.begin(), inputInfo.end(),
                      [](const ObjectInfo &a, const ObjectInfo &b) { return a.score > b.score; });

            int box_num = inputInfo.size();

            vector<int> merged(box_num, 0);
            for (int i = 0; i < box_num; i++) {
                if (merged[i])
                    continue;
                vector<ObjectInfo> buf;

                buf.push_back(inputInfo[i]);
                merged[i] = 1;

                float h0 = inputInfo[i].y2 - inputInfo[i].y1 + 1;
                float w0 = inputInfo[i].x2 - inputInfo[i].x1 + 1;

                float area0 = h0 * w0;
                for (int j = i + 1; j < box_num; j++) {

                    if (merged[j])
                        continue;
                    float inner_x0 = std::max(inputInfo[i].x1, inputInfo[j].x1);
                    float inner_y0 = std::max(inputInfo[i].y1, inputInfo[j].y1);

                    float inner_x1 = std::min(inputInfo[i].x2, inputInfo[j].x2);
                    float inner_y1 = std::min(inputInfo[i].y2, inputInfo[j].y2);

                    float inner_h = inner_y1 - inner_y0 + 1;
                    float inner_w = inner_x1 - inner_x0 + 1;

                    if (inner_h <= 0 || inner_w <= 0)
                        continue;

                    float inner_area = inner_h * inner_w;

                    float h1 = inputInfo[j].y2 - inputInfo[j].y1 + 1;
                    float w1 = inputInfo[j].x2 - inputInfo[j].x1 + 1;

                    float area1 = h1 * w1;

                    float score = inner_area / (area0 + area1 - inner_area);

                    if (score > iouThresh) {
                        merged[j] = 1;
                        buf.push_back(inputInfo[j]);
                    }
                }
                switch (type) {
                    case hard_nms: {
                        outInfo.push_back(buf[0]);
                        break;
                    }
                    case blending_nms: {
                        float total = 0;
                        for (int i = 0; i < buf.size(); i++) {
                            total += exp(buf[i].score);
                        }
                        ObjectInfo rects;
                        memset(&rects, 0, sizeof(rects));
                        for (int i = 0; i < buf.size(); i++) {
                            float rate = exp(buf[i].score) / total;
                            rects.x1 += buf[i].x1 * rate;
                            rects.y1 += buf[i].y1 * rate;
                            rects.x2 += buf[i].x2 * rate;
                            rects.y2 += buf[i].y2 * rate;
                            rects.score += buf[i].score * rate;
                            rects.landmarks = buf[i].landmarks;
                            rects.label = buf[i].label;
                        }
                        outInfo.push_back(rects);
                        break;
                    }
                    default: {
                        LOGI("wrong type of nms.");
                        exit(-1);
                    }
                }
            }
        }

        void ObjectDetection::visualizeResult(cv::Mat &imgBRG,
                                              FrameInfo *frameInfo,
                                              int waitKey) {
            for (int i = 0; i < frameInfo->info.size(); i++) {
                auto obj = frameInfo->info.at(i);
                cv::Rect rect(obj.x1, obj.y1, obj.x2 - obj.x1, obj.y2 - obj.y1);
                //string name = to_string(obj.label) + ":" + to_string(obj.score);
                string name = mParam.class_names[obj.label] + ":" + to_string(obj.score).substr(0, 5);
                cv::Scalar c = COLOR_TABLE[obj.label % COLOR_TABLE.size()];
                draw_rect_text(imgBRG, rect, name, c, 2, 1.0);
                draw_points_texts(imgBRG, obj.landmarks);
                LOGD("i=%d,bboxe:[%3.5f,%3.5f,%3.5f,%3.5f],score:%3.5f", i, obj.x1, obj.y1, obj.x2, obj.y2, obj.score);
            }
            cv::imwrite("../result.jpg", imgBRG);
            cv::namedWindow("result", cv::WINDOW_NORMAL);
            cv::imshow("result", imgBRG);
            cv::waitKey(waitKey);
        }

    }
}
