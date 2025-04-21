#include "face_mesh.h"
#include <string.h>
#include <QtCore/QThread>
#include "gui.h"

QString emotion_model_path;
int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
    if(argc<2)
       return -1;
    emotion_model_path=QString(argv[1]);
    FaceMesh detector;
    Gui gui;
    gui.showMaximized();
    QObject::connect(&detector,&FaceMesh::frameDone,&gui,&Gui::showImage);
    QObject::connect(&detector,&FaceMesh::emotionDone,&gui,&Gui::showEmotion);
    std::cout << "======= face_mesh ============" << std::endl;
    const char* model = "mediapipe/graphs/face_detection/face_detection_desktop_live.pbtxt";
    int res = detector.initModel(model);
    if (res < 0) {
        std::cout << "======= initModel error ============" << std::endl;
        return -1;
    }
    detector.start();
    return app.exec();
}
