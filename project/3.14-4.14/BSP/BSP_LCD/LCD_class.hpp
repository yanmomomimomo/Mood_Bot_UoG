#ifndef __LCD_CLASS_HPP
#define __LCD_CLASS_HPP
#include "LCD.hpp"

class LCD_class{
    public:
        LCD_class(uint16_t Hight, uint16_t Width, uint8_t Scan_dir);
        virtual ~LCD_class();

        struct gpiod_line* Getline(uint8_t i);

        void LCD_SendData_8Bit(uint8_t Data);
        void LCD_SendData_16Bit(uint16_t Data);
        void LCD_SendCommand(uint8_t Reg);

        void LCD_Clear(uint16_t Color);

        void LCD_CSSet(uint8_t value);
        void LCD_BLSet(uint8_t value);
        void LCD_RSTSet(uint8_t value);
        void LCD_DCSet(uint8_t value);

        void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
        void Test_FillScreen(uint16_t color);

        void LCD_DisplayImage(const uint16_t image[172 * 320]) ;

    private:
        struct gpiod_line *line_cs_;
        struct gpiod_line *line_rst_;
        struct gpiod_line *line_dc_;
        struct gpiod_line *line_bl_;
        struct gpiod_chip *chip_ {chip0};
        uint16_t Hight_;
        uint16_t Width_;
        uint8_t Scan_dir_;

};

#endif //  __LCD_CLASS_HPP