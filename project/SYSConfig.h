/************************* Head File of SYSConfig *************************/
#ifndef _SYSCONFIG_H
#define _SYSCONFIG_H

// Header Declaration
#include <iostream>
#include <thread> 
#include <chrono>
#include "SYSConfig.h"
#include "LED.h"
#include "Key.h"
#include "MotorDrive.h"
#include <functional>
#include <stdio.h>

extern bool running_1;
extern bool running_2;

// Function Definition
void Delay(int time);
void Task(bool &running, int KEY_PIN, std::function<void()> callback);

#endif //_SYSCONFIG_H
/*********************************** END ***********************************/
