#include "pwm_class.hpp"
#include <iostream>
#include <unistd.h>
#include <map>
#include <mutex>
#include <thread>

extern struct gpiod_chip *chip0;

static PWM_Pin PWM1[2] = {
    {nullptr, CONSUMER_PWM_11, GPIO_PWM_11},
    {nullptr, CONSUMER_PWM_12, GPIO_PWM_12}
};
static PWM_Pin PWM2[2] = {
    {nullptr, CONSUMER_PWM_21, GPIO_PWM_21},
    {nullptr, CONSUMER_PWM_22, GPIO_PWM_22}
};

PWM_class::PWM_class(uint8_t PWM_number)
    :chip_(chip0), Duty_(50), period(1000)
{
    if (PWM_number == PWMGROUP1){
        PWM_0_ = PWM1[0];
        PWM_1_ = PWM1[1];
    }else if (PWM_number == PWMGROUP2){
        PWM_0_ = PWM2[0];
        PWM_1_ = PWM2[1];
    }

    PWM_0_.line = gpiod_chip_get_line(chip_, PWM_0_.GPIO_Pin);
    PWM_1_.line = gpiod_chip_get_line(chip_, PWM_1_.GPIO_Pin);
    if (!PWM_1_.line || !PWM_0_.line) {
        std::cerr << "Failed to get GPIO line !" << std::endl;
        return;
    }

    int ret = gpiod_line_request_output(PWM_1_.line, PWM_1_.consumer.c_str(), 0) ||
        gpiod_line_request_output(PWM_0_.line, PWM_0_.consumer.c_str(), 0) ;
    if (ret < 0) {
        std::cerr << "Failed to request GPIO line as output! Error code: " << ret << std::endl;
        return;
    }
}

PWM_class::~PWM_class(){
    gpiod_line_set_value(PWM_1_.line, 0); // 拉低
    gpiod_line_set_value(PWM_0_.line, 0); // 拉低
    gpiod_line_release(PWM_1_.line);
    gpiod_line_release(PWM_0_.line);
}

void PWM_class::Rotation(uint8_t dir){
    int duty_us = Duty_  * period / 100;
    // printf("%d\t%d\n", duty_us,(period - duty_us) );
    if (dir == Stop){
        gpiod_line_set_value(PWM_1_.line, 0); // 拉低
        gpiod_line_set_value(PWM_0_.line, 0); 
    }else if(dir == Clockwise){
        gpiod_line_set_value(PWM_1_.line, 0); // 拉低
        gpiod_line_set_value(PWM_0_.line, 1); 
        usleep(duty_us);
        
        gpiod_line_set_value(PWM_0_.line, 0); 
        usleep(period - duty_us);
    }else if(dir == Cou_Clockwise){
        // 
        gpiod_line_set_value(PWM_0_.line, 0); 
        gpiod_line_set_value(PWM_1_.line, 1); // 拉低
        usleep(duty_us);
        gpiod_line_set_value(PWM_1_.line, 0);
        usleep(period - duty_us);
    }
}