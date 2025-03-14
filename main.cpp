#include <iostream>
#include <thread> 
#include <chrono>
#include "SYSConfig.h"
#include "LED.h"
#include "Key.h"
#include "MotorDrive.h"
#include <mutex>

bool running_1 = true;
bool running_2 = true;

int main() {
    // 初始化 WiringPi
    if (wiringPiSetup() == -1) {
        std::cerr << "WiringPi 初始化失败！" << std::endl;
        return 1;
    }
    LED_Config();
    Key_Config();
    
    std::thread t1(Task, std::ref(running_1), KEY1_PIN, LED_RED); // 创建线程 1
    std::thread t2(Task, std::ref(running_2), KEY2_PIN, LED_YELLOW); // 创建线程 2

    // **程序无需无限循环，等待回调触发**
    std::this_thread::sleep_for(std::chrono::seconds(10));
    running_1 = false;
    running_2 = false;

    // 等待线程结束
    t1.join();
    t2.join();
    LED_END;

    return 0;
}
