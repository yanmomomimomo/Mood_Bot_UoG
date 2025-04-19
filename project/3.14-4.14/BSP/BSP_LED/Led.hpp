#ifndef __LED_HPP
#define __LED_HPP

// h files Declaration
#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../SYS_Con/SYS.hpp"

// Pin Declaration
#define CONSUMER_LED_RED "LED_RED"
#define CONSUMER_LED_YEL "LED_YELLOW"
#define GPIO_LED_RED     uint8_t(19)   // GPIO24 <=> 19
#define GPIO_LED_YEL     uint8_t(16)   // GPIO27 <=> 16

#define LED_ON 1
#define LED_OFF 0

extern struct gpiod_line *line_red, *line_yellow;

#endif // _LED_HPP