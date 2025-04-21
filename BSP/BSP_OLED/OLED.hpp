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
#include <cmath>

#define OLED_WIDTH   uint16_t(128)
#define OLED_HEIGHT  uint16_t(64)
#define BUFFER_SIZE  uint16_t(OLED_WIDTH * OLED_HEIGHT / 8)

// toggle cmd
#define NO_WARN     1
#define WARN        2
#define NOEVENT

static const char* MONTHS[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
static const char* WEEKDAYS[] = {
    "Sun", "Mon", "Tues", "Wed", "Thur", "Fri", "Sat"
};

extern uint8_t displayBuffer[BUFFER_SIZE];
extern uint8_t oled_frame[];
extern uint8_t warningPattern[];

bool OLED_init();
bool OLED_updateDisplay();
void OLED_clearDisplay(void);
#endif // __OLED_HPP