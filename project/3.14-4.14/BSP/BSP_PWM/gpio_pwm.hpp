#ifndef GPIO_PWM_H
#define GPIO_PWM_H

#include <gpiod.h>
#include <thread>
#include <map>
#include <mutex>
#include "../../SYS_Con/SYS.hpp"

#define PERIOD_US 1000 // 1ms PWM周期

#define PWMGROUP1 uint8_t(1)
#define PWMGROUP2 uint8_t(2)

#define GPIO_PWM_11 uint8_t(4)
#define GPIO_PWM_12 uint8_t(17)
#define GPIO_PWM_21 uint8_t(27)
#define GPIO_PWM_22 uint8_t(22)

#define CONSUMER_PWM_11 "PWM_1"
#define CONSUMER_PWM_12 "PWM_2"
#define CONSUMER_PWM_21 "PWM_3"
#define CONSUMER_PWM_22 "PWM_4"

#define Stop uint8_t(0)
#define Clockwise uint8_t(1)
#define Cou_Clockwise uint8_t(2)



// #define Forward uint8_t(1)
// #define Backward uint8_t(0)

// #define Left uint8_t(1)
// #define Right uint8_t(0)

struct PWM_Pin{
    gpiod_line* line;
    std::string consumer;
    uint8_t GPIO_Pin;
};

#endif // GPIO_PWM_H
