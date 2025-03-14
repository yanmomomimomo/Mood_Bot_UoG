/************************* Head File of MotorDrive *************************/
#ifndef _MOTORDRIVE_H
#define _MOTORDRIVE_H

// Header Declaration
#include <iostream>
#include <wiringPi.h>

// Pin Definition
#define PWM_PIN 18 // ��������12����Ӧ BCM_GPIO 18
#define PWM_RANGE 1024 // PWM ��Χ

// Function Definition
void MotorDrive_Config(int dutyCycle);
#endif //_MOTORDRIVE_H
/*********************************** END ***********************************/
