#include "emotionclassifier.h"

Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "ONNXRuntime");
EmotionClassifier::EmotionClassifier(QString mp,QObject *parent)
{
    model_path=mp;
    session=new Ort::Session(env, model_path.toStdString().c_str(), session_options);
    input_name.push_back("input");
    output_name.push_back("output");
}

EmotionClassifier::~EmotionClassifier()
{

}

int EmotionClassifier::predict(cv::Mat &img)
{
    cv::Mat resized_image;
    cv::resize(img,resized_image,cv::Size(224,224));
    cv::Mat float_image;
    resized_image.convertTo(float_image,CV_32FC3,1.0/255.0);
    std::vector<int64_t> input_shape = {1, 3, 224, 224};
    std::vector<float> input_tensor(1*3*224*224);
        // NHWC to NCHW
        for (int c = 0; c < 3; c++) {
            for (int h = 0; h < 224; h++) {
                for (int w = 0; w < 224; w++) {
                    input_tensor[c * 224 * 224 + h * 224 + w] = 
                        float_image.at<cv::Vec3f>(h, w)[c];
                }
            }
        }
    Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtAllocatorType::OrtArenaAllocator, OrtMemType::OrtMemTypeDefault);
    Ort::Value input_tensor_ort = Ort::Value::CreateTensor<float>(memory_info, input_tensor.data(), input_tensor.size(),input_shape.data(), input_shape.size());
    auto output_tensors = session->Run(Ort::RunOptions{nullptr}, input_name.data(), &input_tensor_ort, 1, output_name.data(), 1);
    float* output_data = output_tensors[0].GetTensorMutableData<float>();
    size_t output_size = output_tensors[0].GetTensorTypeAndShapeInfo().GetElementCount();
    int max_index =0;
    for(int i=0;i<output_size;i++)
    {
        if(output_data[i]>output_data[max_index])
        {
            max_index=i;
        }
    }
    return max_index;
}
