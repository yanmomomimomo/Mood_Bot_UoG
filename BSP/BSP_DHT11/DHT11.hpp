#ifndef __DHT11_HPP
#define __DHT11_HPP

#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <signal.h>
#include <time.h>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "SYS.hpp"

#define DHT_GPIO             4
#define RESPONSE_TIMEOUT_MS 7      // ms
#define LOGIC_THRESHOLD_US  56     // µs
#define MAX_EDGES           82     
#define DHT_CONSUME "DHT11"

#endif  // __DHT11_HPP