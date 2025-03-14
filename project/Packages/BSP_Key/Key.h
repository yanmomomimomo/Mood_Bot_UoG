/************************* Head File of Key *************************/
#ifndef _KEY_H
#define _KEY_H

// Header Declaration
#include <iostream>
#include <wiringPi.h>
#include "SYSConfig.h"

// Pin Definition
#define KEY1_PIN 24 // WiringPi 1 = BCM 18（物理引脚 12）
#define KEY2_PIN 27 // WiringPi 1 = BCM 18（物理引脚 12）


// Function Definition
#define KEY_ON	1
#define KEY_OFF 0

// Function Definition
void Key_Config();
uint8_t Key_Press_Mode1(int KEY_PIN);
#endif //_KEY_H
/*********************************** END ***********************************/
