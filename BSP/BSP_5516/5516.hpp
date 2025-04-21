#ifndef __5516_HPP
#define __5516_HPP

#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "SYS.hpp"

#define GPIO_5516    17
#define CONSUMER_5516 "light-sensor"

#define LIGHT  0
#define NO_LIGHT 1

extern struct gpiod_chip* chip0;
#endif // __5516_HPP