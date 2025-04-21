#ifndef __KEYS_HPP
#define __KEYS_HPP

#include <iostream>
#include <cstdlib>
#include <gpiod.h>
#include <unistd.h>
#include <time.h>

#define GPIO_KEY1 6         // GPIO22 <=> 6
#define GPIO_KEY2 12        // GPIO26 <=> 12

#define CONSUMER_KEY1 "KEY1"
#define CONSUMER_KEY2 "KEY2"

#define KEY_ON uint8_t(1)
#define KEY_OFF uint8_t(0)

#define HIGH_POW uint8_t(1)
#define LOW_POW uint8_t(0)

#define NO_CLICK uint8_t(0)
#define CLICK uint8_t(1)

enum Edge_modes {Rising, Falling};

#endif // __KEYS_HPP