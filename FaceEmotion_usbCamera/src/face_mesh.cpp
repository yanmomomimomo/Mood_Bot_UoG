#include "face_mesh.h"
#include <iostream>
#include <thread>
#include <string>
using namespace std;
int img_width = 640;  
int img_height = 480;
      
extern QString emotion_model_path;
FaceMesh::FaceMesh()
{

}

FaceMesh::~FaceMesh()
{

}

void FaceMesh::resizeEvent(QResizeEvent *re)
{

}
int FaceMesh::initModel(const char* model_path) noexcept {
    absl::Status run_status = initGraph(model_path);
    if (!run_status.ok())
        return -1;
    init_ = true;

    return  1;
}

int FaceMesh::release() {
    absl::Status run_status = releaseGraph();
    return run_status.ok() ? 1 : -1;
}

absl::Status FaceMesh::initGraph(const char* model_path) {
    std::string calculator_graph_config_contents;
    MP_RETURN_IF_ERROR(mediapipe::file::GetContents(model_path, &calculator_graph_config_contents));
    mediapipe::CalculatorGraphConfig config =
        mediapipe::ParseTextProtoOrDie<mediapipe::CalculatorGraphConfig>(
            calculator_graph_config_contents);
    MP_RETURN_IF_ERROR(graph_.Initialize(config));
    auto sop = graph_.AddOutputStreamPoller(kOutputStream);
    assert(sop.ok());
    pPoller_ = std::make_unique<mediapipe::OutputStreamPoller>(std::move(sop.value()));
    mediapipe::StatusOrPoller poseLandmark = graph_.AddOutputStreamPoller(kOutputLandmarks);
    assert(poseLandmark.ok());
    pPollerLandmarks_ = std::make_unique<mediapipe::OutputStreamPoller>(std::move(poseLandmark.value()));

    MP_RETURN_IF_ERROR(graph_.StartRun({}));
    std::cout << "======= graph_ StartRun success ============" << std::endl;
    return absl::OkStatus();
}

int FaceMesh::extractFace(cv::Mat& image,cv::Mat &firstface)
{
    mediapipe::Packet detection_packet;
    int face_num=0;
    int bad_wait=0;
    if(pPollerLandmarks_->QueueSize()>1)
    {
      if(!pPollerLandmarks_->Next(&detection_packet))
      {
          return face_num;
      }
      if (detection_packet.IsEmpty()) {
          return face_num;
      }
      auto& detections = detection_packet.Get<std::vector<mediapipe::Detection>>();
      for(int i=0;i<detections.size();i++)
      {
        auto& detection=detections[i];
        const auto& rel_bbox = detection.location_data().relative_bounding_box();
        float xmin = rel_bbox.xmin();
        float ymin = rel_bbox.ymin();
        float width = rel_bbox.width();
        float height = rel_bbox.height();
        int abs_xmin = static_cast<int>(xmin * img_width)-10;
        if(abs_xmin<0)abs_xmin=0;
        int abs_ymin = static_cast<int>(ymin * img_height)-10;
        if(abs_ymin<0)abs_ymin=0;
        int abs_width = static_cast<int>(width * img_width)+20;
        int abs_height = static_cast<int>(height * img_height)+20;
        std::string text="("+std::to_string(abs_xmin);
        text=text+","+std::to_string(abs_ymin);
        text=text+","+std::to_string(abs_width);
        text=text+","+std::to_string(abs_height);
        text=text+")";
        cv::putText(image,text,cv::Point(abs_xmin,abs_ymin),cv::FONT_HERSHEY_COMPLEX,1.0,cv::Scalar(255,0,0));
        cv::rectangle(image,cv::Point(abs_xmin,abs_ymin),cv::Point(abs_xmin+abs_width,abs_ymin+abs_height),cv::Scalar(0,0,255),2);
        try{
            image(cv::Rect(abs_xmin,abs_ymin,abs_width,abs_height)).copyTo(firstface);
            face_num=1;
        }
        catch(...){
        }
        break;
      }
    }
    return face_num;
}

void FaceMesh::runVideo()
{
    capture=cv::VideoCapture(0);
    // RET_CHECK(capture.isOpened());
    capture.set(cv::CAP_PROP_FRAME_WIDTH, img_width);
    capture.set(cv::CAP_PROP_FRAME_HEIGHT, img_height);
    fps=10;
    timer_for_render->start(1000/fps);
}

void FaceMesh::run()
{
    timer_for_render=new QTimer();
    //timer_for_render->moveToThread(this);
    timer_for_render->setTimerType(Qt::PreciseTimer);
    connect(timer_for_render,&QTimer::timeout,this,&FaceMesh::updateFrame);
    ec=new EmotionClassifier(emotion_model_path);
    runVideo();
    exec();
}

void FaceMesh::updateFrame()
{
    cv::Mat camera_frame_raw;
    capture >> camera_frame_raw;
    if (camera_frame_raw.empty())
        return;
    cv::Mat camera_frame;
    camera_frame_raw.copyTo(camera_frame);
    cv::cvtColor(camera_frame, camera_frame, cv::COLOR_BGR2RGB);
    //cv::flip(camera_frame, camera_frame,1);
    if(frame_ready)
    {
        frame_ready=false;
    }
    else
    {
        std::cout<<"skip frame"<<std::endl;
        return;
    }
    auto input_frame = absl::make_unique<mediapipe::ImageFrame>(
        mediapipe::ImageFormat::SRGB, camera_frame.cols, camera_frame.rows,
        mediapipe::ImageFrame::kDefaultAlignmentBoundary);
    cv::Mat input_frame_mat = mediapipe::formats::MatView(input_frame.get());
    camera_frame.copyTo(input_frame_mat);

    // Send image packet into the graph.
    size_t frame_timestamp_us =
        (double)cv::getTickCount() / (double)cv::getTickFrequency() * 1e6;
    graph_.AddPacketToInputStream(kInputStream, mediapipe::Adopt(input_frame.release()).At(mediapipe::Timestamp(frame_timestamp_us)));
    mediapipe::Packet packet;
    if (pPoller_->Next(&packet))
    {
        auto& output_frame = packet.Get<mediapipe::ImageFrame>();
        cv::Mat output_frame_mat = mediapipe::formats::MatView(&output_frame);
        output_frame_mat.release();
    }
    cv::Mat face_mat;
    int num=extractFace(camera_frame,face_mat);
    QImage qimg(camera_frame.data, 
                camera_frame.cols, 
                camera_frame.rows, 
                camera_frame.step, 
                QImage::Format_RGB888);
    emit frameDone(qimg);
    if(num>0)
    {
        int emotion_index=ec->predict(face_mat);
        if(last_emotion_index==emotion_index)
        {
           valid_emotion_count++;
           if(valid_emotion_count>=10)
           {
              valid_emotion_count=0;
              emit emotionDone(emotion_index);
           }
        }
        last_emotion_index=emotion_index;
    }
    frame_ready=true;
}

absl::Status FaceMesh::releaseGraph()
{
    MP_RETURN_IF_ERROR(graph_.CloseInputStream(kInputStream));
    MP_RETURN_IF_ERROR(graph_.CloseInputStream(kOutputLandmarks));
    return graph_.WaitUntilDone();
}
