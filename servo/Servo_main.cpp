#include <iostream>
#include <csignal>
#include "Servo.hpp"

Servo_class servo;

void handle_signal(int signal) {
    std::cout << "Caught signal " << signal << ", stopping Servo and cleaning up GPIO." << std::endl;
    servo.release_gpio();  // 释放所有 GPIO 资源
    exit(0);  // 退出程序
}

int main() {
    signal(SIGINT, handle_signal);  // 捕获中断信号
    signal(SIGTERM, handle_signal); // 捕获终止信号

    if (!gpio.init()) {  // 初始化 GPIO
        return 1;
    }


    //舵机运动测试
    servo.Servo_down(Servo1);
    sleep(1);
    servo.Servo_up(Servo1);
    servo.release_gpio();  // 释放 GPIO 引脚

    return 0;
}
