#ifndef __SERVO_CLASS_HPP
#define __SERVO_CLASS_HPP

#include "Servo.hpp"
#include <gpiod.h>
#include <string>

extern gpiod_chip *chip0;

class Servo_class {
public:
    // ���캯��
    Servo_class(const char* chip_path = GPIO_CHIP);

    ~Servo_class();
    bool Servo_init();

    void set_pwm_output(int pin, int duty_cycle_percent);

    void Servo_disable(int pin);
    void release_gpio();

    void set_pwm_pulse_ms(int pin, float pulse_ms);
    void Servo_up(int pin);
    void Servo_down(int pin);


private:
    gpiod_chip* chip_;  
    std::mutex pwm_mutex_;
    std::map<int, std::thread> pwm_threads_; 
    std::map<int, bool> pwm_running_; 

    std::map<int, gpiod_line*> gpio_lines_; 


    gpiod_line* get_gpio_line(int pin);

    void set_pwm_for_pin(int pin, int duty_cycle_percent);
};


#endif // SERVO_CLASS_HPP_INCLUDED
