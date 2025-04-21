#include "Camera_class.hpp"



int main() {
    Camera_class* Camera = new Camera_class();
    if(Camera == nullptr) {
        std::cerr << "Camera init error" << std::endl;
        return -1;
    }

    while (true) {
        if (!Camera->Collect()){break;}
        Camera->ImageAnalysis();
    }
    
    return 0;
}
