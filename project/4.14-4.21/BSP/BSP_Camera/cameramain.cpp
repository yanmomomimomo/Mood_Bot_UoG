#include "Camera.hpp"

int centerX, centerY;

int main(){
    if (!Camera_Init()) {
        // 初始化失败处理
        return -1;
    }

    if (!Camera_Start()) {
        // 启动失败处理
        Camera_DeInit();
        return -1;
    }
    while (true){
        Camera_GetFaceCenter(0, &centerX, &centerY);
        printf("%d /n %d",centerX,centerY);

    }
}