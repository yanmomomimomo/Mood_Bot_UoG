#include "OLED.hpp"

bool OLED_init() {
    if (!I2C_writeCommand(0xAE)) return false;  // Display Off

    if (!I2C_writeCommand(0xD5)) return false;  // Set display clock divide ratio/oscillator frequency
    if (!I2C_writeCommand(0x80)) return false;

    if (!I2C_writeCommand(0xA8)) return false;  // Set multiplex ratio
    if (!I2C_writeCommand(OLED_HEIGHT - 1)) return false;  // 64行显示时参数为 63（0x3F）

    if (!I2C_writeCommand(0xD3)) return false;  // Set display offset
    if (!I2C_writeCommand(0x00)) return false;  // No offset

    if (!I2C_writeCommand(0x40)) return false;  // Set start line address at 0

    if (!I2C_writeCommand(0x8D)) return false;  // Charge pump setting
    if (!I2C_writeCommand(0x14)) return false;  // Enable charge pump

    if (!I2C_writeCommand(0x20)) return false;  // Set Memory Addressing Mode
    if (!I2C_writeCommand(0x00)) return false;  // Horizontal addressing mode

    if (!I2C_writeCommand(0xA1)) return false;  // Set segment re-map (A0/A1) – 0xA1表示左右翻转

    if (!I2C_writeCommand(0xC8)) return false;  // Set COM Output Scan Direction – 0xC8为上下翻转

    if (!I2C_writeCommand(0xDA)) return false;  // Set COM Pins Hardware Configuration
    if (!I2C_writeCommand(0x12)) return false;

    if (!I2C_writeCommand(0x81)) return false;  // Set Contrast Control
    if (!I2C_writeCommand(0x7F)) return false;

    if (!I2C_writeCommand(0xA4)) return false;  // Disable Entire Display On (resume to RAM display)
    if (!I2C_writeCommand(0xA6)) return false;  // Set Normal Display (非反相)

    if (!I2C_writeCommand(0xAF)) return false;  // Display ON

    // 初始化后清空缓冲区
    std::memset(displayBuffer, 0, BUFFER_SIZE);

    return true;
}

void OLED_clearDisplay(void) {
    // 将整个缓冲区清零（全黑）
    memset(displayBuffer, 0, sizeof(displayBuffer));
    
    // 更新 OLED 显示（一次性刷新整个屏幕）
    I2C_writeCommand(0x21);                    // 设置列地址
    I2C_writeCommand(0x00);                    // 开始列
    I2C_writeCommand(OLED_WIDTH - 1);        // 结束列
    I2C_writeCommand(0x22);                    // 设置页地址
    I2C_writeCommand(0x00);                    // 开始页
    I2C_writeCommand((OLED_HEIGHT / 8) - 1);   // 结束页
    I2C_writeData(displayBuffer, sizeof(displayBuffer));
}

// bool OLED_updateDisplay() {
//     if (!I2C_writeCommand(0x21)) return false;  // Set Column Address
//     if (!I2C_writeCommand(0x00)) return false;  // Column start address (0)
//     if (!I2C_writeCommand(OLED_WIDTH - 1)) return false;  // Column end address (127)

//     if (!I2C_writeCommand(0x22)) return false;  // Set Page Address
//     if (!I2C_writeCommand(0x00)) return false;  // Page start address (0)
//     if (!I2C_writeCommand((OLED_HEIGHT / 8) - 1)) return false;  // Page end address

//     if (!I2C_writeData(displayBuffer, BUFFER_SIZE)) return false;

//     return true;
// }

bool OLED_updateDisplay() {
    I2C_writeCommand(0x21);         // 设置列地址
    I2C_writeCommand(0x00);         // 开始列
    I2C_writeCommand(127);          // 结束列
    I2C_writeCommand(0x22);         // 设置页地址
    I2C_writeCommand(0x00);         // 开始页
    I2C_writeCommand((OLED_HEIGHT / 8) - 1); // 结束页

    // 将整个显示缓冲区写入 OLED（一次性刷新全屏）
    I2C_writeData(displayBuffer, sizeof(displayBuffer));

    return true;
}
