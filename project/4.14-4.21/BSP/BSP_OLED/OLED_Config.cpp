#include "OLED.hpp"
#include "SYS.hpp"

bool OLED_init() {
    if (!I2C_writeCommand(0xAE)) return false;  // Display Off

    if (!I2C_writeCommand(0xD5)) return false;  // Set display clock divide ratio/oscillator frequency
    if (!I2C_writeCommand(0x80)) return false;

    if (!I2C_writeCommand(0xA8)) return false;  // Set multiplex ratio
    if (!I2C_writeCommand(OLED_HEIGHT - 1)) return false; 

    if (!I2C_writeCommand(0xD3)) return false;  // Set display offset
    if (!I2C_writeCommand(0x00)) return false;  // No offset

    if (!I2C_writeCommand(0x40)) return false;  // Set start line address at 0

    if (!I2C_writeCommand(0x8D)) return false;  // Charge pump setting
    if (!I2C_writeCommand(0x14)) return false;  // Enable charge pump

    if (!I2C_writeCommand(0x20)) return false;  // Set Memory Addressing Mode
    if (!I2C_writeCommand(0x00)) return false;  // Horizontal addressing mode

    if (!I2C_writeCommand(0xA1)) return false; 

    if (!I2C_writeCommand(0xC8)) return false;

    if (!I2C_writeCommand(0xDA)) return false;  // Set COM Pins Hardware Configuration
    if (!I2C_writeCommand(0x12)) return false;

    if (!I2C_writeCommand(0x81)) return false;  // Set Contrast Control
    if (!I2C_writeCommand(0x7F)) return false;

    if (!I2C_writeCommand(0xA4)) return false;  // Disable Entire Display On (resume to RAM display)
    if (!I2C_writeCommand(0xA6)) return false; 

    if (!I2C_writeCommand(0xAF)) return false;  // Display ON

    std::memset(displayBuffer, 0, BUFFER_SIZE);

    return true;
}

void OLED_clearDisplay(void) {
    memset(displayBuffer, 0, sizeof(displayBuffer));
    
    I2C_writeCommand(0x21);                    
    I2C_writeCommand(0x00);                  
    I2C_writeCommand(OLED_WIDTH - 1);      
    I2C_writeCommand(0x22);                    
    I2C_writeCommand(0x00);                  
    I2C_writeCommand((OLED_HEIGHT / 8) - 1); 
    I2C_writeData(displayBuffer, sizeof(displayBuffer));
}

bool OLED_updateDisplay() {
    I2C_writeCommand(0x21);         
    I2C_writeCommand(0x00);        
    I2C_writeCommand(127);         
    I2C_writeCommand(0x22);         
    I2C_writeCommand(0x00);        
    I2C_writeCommand((OLED_HEIGHT / 8) - 1);

    I2C_writeData(displayBuffer, sizeof(displayBuffer));

    return true;
}
