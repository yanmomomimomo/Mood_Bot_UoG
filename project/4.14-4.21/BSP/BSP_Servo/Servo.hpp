#ifndef SERVO_HPP_INCLUDED
#define SERVO_HPP_INCLUDED

#include <gpiod.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <map>
#include <mutex>
#include <thread>
#include <csignal>
#include "SYS.hpp"

#define PERIOD_US 1000 // 1ms PWM

#define GPIO_Servo1 20
#define GPIO_Servo2 27

#define SER1_CONSUMER "Servo1"
#define SER2_CONSUMER "Servo2"

#define SER1_UANGLE  10
#define SER1_COUNT  4
#define SER1_COUNT_MAX 8

#define TURN_LEFT -1
#define TURN_RIGHT 1

#define TURN_UP -1
#define TURN_DOWN 1

extern struct gpiod_chip* chip0;
#endif // SERVO_HPP_INCLUDED
