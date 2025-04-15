#include <iostream>
#include <csignal>
#include "gpio_pwm.hpp"


GPIODriver gpio;

void handle_signal(int signal) {
    std::cout << "Caught signal " << signal << ", stopping PWM and cleaning up GPIO." << std::endl;
    gpio.stop_pwm();  // 停止所有 PWM 输出
    gpio.release_gpio();  // 释放所有 GPIO 资源
    exit(0);  // 退出程序
}

int main() {
    signal(SIGINT, handle_signal);  // 捕获中断信号
    signal(SIGTERM, handle_signal); // 捕获终止信号

    if (!gpio.init()) {  // 初始化 GPIO
        return 1;
    }

    /*//电机运动测试
    gpio.turnleft_start();


    sleep(5);  // 运行一段时间

    gpio.move_stop();
    gpio.turnright_start();
    sleep(5);  // 运行一段时间
    gpio.move_stop();
    gpio.shake_start();*/

    //舵机运动测试
    gpio.set_pwm_pulse_ms(GPIO::server, 1.7); // GPIO 17 输出 1.5ms 脉冲（中位）
    sleep(1);

    gpio.release_gpio();  // 释放 GPIO 引脚
    gpio.stop_pwm();
    return 0;
}
