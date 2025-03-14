/************************* Head File of LED *************************/
#ifndef _LED_H
#define _LED_H

// Header Declaration
#include <iostream>
#include <wiringPi.h>
#include "SYSConfig.h"

// Pin Definition
#define LED_RED_PIN		22   // WiringPi 22 = BCM 6（物理引脚 31）
#define LED_YELLOW_PIN	26   // WiringPi 26 = BCM 12（物理引脚 32）
//#define LED_ALL_PIN LED_RED_PIN | LED_YELLOW_PIN

// LED ID
#define LED_ID_RED		1
#define LED_ID_YELLOW	2

// LED Function
#define LED_ON(LED_PIN)	\
						digitalWrite(LED_PIN, LOW);\
						digitalWrite(LED_PIN, HIGH)
#define LED_OFF(LED_PIN) \
						digitalWrite(LED_PIN, LOW)
#define LED_FLASH(LED_PIN) digitalWrite(LED_PIN, digitalRead(LED_PIN)? LOW : HIGH)
#define LED_END \
					digitalWrite(LED_ID_RED, LOW);\
					digitalWrite(LED_ID_YELLOW, LOW);\
					digitalWrite(LED_ID_RED, HIGH);\
					Delay(1000);\
					digitalWrite(LED_ID_RED, LOW);\

// Function Definition
void LED_Config();
void LED_RED();
void LED_YELLOW();

#endif //_LED_H
/*********************************** END ***********************************/
