#ifndef __RD_03_HPP
#define __RD_03_HPP

#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>

#include "SYS.hpp"


#define RD_GPIO    18          
#define RD_CONSUMER "RD-03"

#define NO_HUM  1
#define HUM 0

#define BAUD_RATE    B115200

extern struct gpiod_chip* chip0;

#endif // __RD_03_HPP