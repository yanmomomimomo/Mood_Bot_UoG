#include <dlib/opencv.h>
#include <opencv2/opencv.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>

using namespace dlib;
using namespace std;
//using namespace cv;
using namespace cv::ml;
int main()
{
	try
	{
		cv::VideoCapture cap(0);
		if (!cap.isOpened())
		{
			cerr << "Unable to connect to camera" << endl;
			return 1;
		}

		//image_window win;

		// Load face detection and pose estimation models.
		frontal_face_detector detector = get_frontal_face_detector();
		shape_predictor pose_model;
		deserialize("shape_predictor_68_face_landmarks.dat") >> pose_model;

		cv::Ptr<SVM> svm = StatModel::load<SVM>("SVM_DATA.xml");

		// Grab and process frames until the main window is closed by the user.
		while (cv::waitKey(30) != 27)
		{
			// Grab a frame
			cv::Mat temp;
			cap >> temp;

			cv_image<bgr_pixel> cimg(temp);
			// Detect faces
			std::vector<rectangle> faces = detector(cimg);
			// Find the pose of each face.
			std::vector<full_object_detection> shapes;
			for (unsigned long i = 0; i < faces.size(); ++i)
				shapes.push_back(pose_model(cimg, faces[i]));

			if (!shapes.empty()) {
				float testData[1][136];
				float index = -(faces[0].top() - faces[0].bottom()) / 300.0;
				for (int i = 0; i < 68; i++) {
					circle(temp, cvPoint(shapes[0].part(i).x(), shapes[0].part(i).y()), 2, cv::Scalar(255, 0, 0), -1);
					testData[0][i * 2] = (shapes[0].part(i).x() - faces[0].left()) / index;
					testData[0][i * 2+1] = (shapes[0].part(i).y() - faces[0].top()) / index;
					//  shapes[0].part(i).x();//68个
				}
				cv::Mat Output;

				cv::Mat query(1, 136, CV_32FC1, testData);

				if (svm->predict(query) == 250) {
					cv::putText(temp, "Happy" , cv::Point(20, 60),3, 2, cvScalar(0, 0, 255));
					cout << "Happy" << endl;
				}

				if (svm->predict(query) == 170) {
					cv::putText(temp, "Common", cv::Point(20, 60), 3, 2, cvScalar(0, 0, 255));
					cout << "Common" << endl;
				}
				if (svm->predict(query) == 300) {
					cv::putText(temp, "Disgust", cv::Point(20, 60), 3, 2, cvScalar(0, 0, 255));
					cout << "Disgust" << endl;
				}
				//	cout<<	svm->predict(query)<<endl;
			//	cout << 结果 << endl;
			}
			//Display it all on the screen
			imshow("表情识别      ESC退出", temp);

		}
	}
	catch (serialization_error& e)
	{
		cout << "You need dlib's default face landmarking model file to run this example." << endl;
		cout << "You can get it from the following URL: " << endl;
		cout << "   http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
		cout << endl << e.what() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}