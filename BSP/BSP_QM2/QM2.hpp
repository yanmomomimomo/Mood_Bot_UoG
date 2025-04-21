#ifndef __QM2_HPP
#define __QM2_HPP

#include <gpiod.h>
#include <iostream>
#include <chrono>
#include <csignal>
#include <thread>
#include <cstdlib>

#define GPIO_QM2            21 
#define QM2_CONSUMER        "QM2_device"
#define SAMPLE_COUNT_QM2        5 
#define SAMPLE_INTERVAL_MS  50  
#define THRESHOLD_COUNT     3   

#define SMOKE_NOR           uint8_t(0)
#define SMOKE_ERR           uint8_t(1)

#endif // __QM2_HPP