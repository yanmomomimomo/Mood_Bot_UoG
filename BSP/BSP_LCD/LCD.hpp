#ifndef __LCD_HPP
#define __LCD_HPP
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>		//exit()
#include <signal.h>     //signal()
#include <gpiod.h>
#include <vector>
#include "SYS.hpp"
// #include "LCD_class.hpp"

class LCD_class;

extern struct gpiod_chip *chip0;

#define LCD_1IN47_HEIGHT 320
#define LCD_1IN47_WIDTH 172

#define HORIZONTAL 0
#define VERTICAL   1

#define LCD_CS_Pin    22
#define LCD_DC_Pin    23
#define LCD_RST_Pin   24
#define LCD_BL_Pin    26

#define LCD_CON_CS "lcd_cs"
#define LCD_CON_RST "lcd_rst"
#define LCD_CON_DC "lcd_dc"
#define LCD_CON_BL "lcd_bl"

void Handler_1IN47_LCD(int signo);
void LCD_1IN47_Init(uint8_t Scan_dir, LCD_class &lcd);
void LCD_SetWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint8_t Scan_dir, LCD_class &lcd);
#endif // __LCD_HPP