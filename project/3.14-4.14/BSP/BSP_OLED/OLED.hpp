#ifndef __OLED_HPP
#define __OLED_HPP

#include <iostream>
#include <cstdint>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "../../SYS_Con/SYS.hpp"

#define OLED_WIDTH   uint16_t(128)
#define OLED_HEIGHT  uint16_t(64)
#define BUFFER_SIZE  uint16_t(OLED_WIDTH * OLED_HEIGHT / 8)

// 月份和星期缩写表（C风格结构体 tm 不自带英文缩写）
static const char* MONTHS[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
static const char* WEEKDAYS[] = {
    "Sun", "Mon", "Tues", "Wed", "Thur", "Fri", "Sat"
};

// OLED 显示缓冲区，SSD1306 为单比特显示（每8个像素组成1字节）
extern uint8_t displayBuffer[BUFFER_SIZE];
extern uint8_t oled_frame[];
extern uint8_t warningPattern[];

bool OLED_init();
bool OLED_updateDisplay();
void OLED_clearDisplay(void);
#endif // __OLED_HPP