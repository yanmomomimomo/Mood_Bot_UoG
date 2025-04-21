#ifndef GPIO_PWM_H
#define GPIO_PWM_H

#include <gpiod.h>
#include <thread>
#include <map>
#include <mutex>

#define PERIOD_US 1000 // 1ms PWM周期
#define GPIO_CHIP "/dev/gpiochip0"

namespace GPIO {
    const int IN_1 = 20;
    const int IN_2 = 21;
    const int IN_3 = 2;
    const int IN_4 = 3;
    const int server = 26;
}

class GPIODriver {
public:
    // 构造函数
    GPIODriver(const char* chip_path = GPIO_CHIP);

    // 析构函数
    ~GPIODriver();

    // 初始化 GPIO，传入 GPIO 引脚的编号，返回是否成功
    bool init();

    // 设置 GPIO 电平（1：高，0：低）
    void set_gpio_level(int pin, int level);

    // 设置 PWM 输出，占空比为百分比（0-100）
    void set_pwm_output(int pin, int duty_cycle_percent);

    // 停止所有 PWM 输出
    void stop_pwm();
    void stop_pwm(int pin);

    // 释放资源
    void release_gpio();

    void forward_start();
    void move_stop();
    void backward_start();
    //void backward_stop();
    void turnleft_start();
    void turnright_start();
    void shake_start();


    void set_pwm_pulse_ms(int pin, float pulse_ms);



private:
    gpiod_chip* chip_;  // GPIO chip 对象
    std::mutex pwm_mutex_;  // 用于 PWM 操作的锁，防止并发访问
    std::map<int, std::thread> pwm_threads_;  // 用于存储每个引脚的 PWM 线程
    std::map<int, bool> pwm_running_;  // 记录每个引脚的 PWM 状态

    std::map<int, gpiod_line*> gpio_lines_;  // 存储请求的 GPIO 引脚

    // 获取 GPIO 引脚对象
    gpiod_line* get_gpio_line(int pin);

    // 设置单个 PWM 输出引脚
    void set_pwm_for_pin(int pin, int duty_cycle_percent);
};

#endif // GPIO_PWM_H
