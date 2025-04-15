#ifndef SERVO_CLASS_HPP_INCLUDED
#define SERVO_CLASS_HPP_INCLUDED

#include "Servo.hpp"
#include <gpiod.h>
#include <string>

extern gpiod_chip *chip0;

class Servo_class {
public:
    // 构造函数
    Servo_class(const char* chip_path = GPIO_CHIP);

    // 析构函数
    ~Servo_class();

    // 初始化 GPIO，传入 GPIO 引脚的编号，返回是否成功
    bool Servo_init();

    // 设置 PWM 输出，占空比为百分比（0-100）
    void set_pwm_output(int pin, int duty_cycle_percent);

    // 停止舵机 PWM 输出

    void Servo_disable(int pin);

    // 释放资源
    void release_gpio();

    void set_pwm_pulse_ms(int pin, float pulse_ms);
    void Servo_up(int pin);
    void Servo_down(int pin);


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


#endif // SERVO_CLASS_HPP_INCLUDED
