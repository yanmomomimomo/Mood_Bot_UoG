#include "LCD_class.hpp"
static void Delay_ms(unsigned int xms)
{
    usleep(xms * 1000); 
}

static void LCD_1IN47_Reset(LCD_class &lcd)
{
    int xms = 100;
    // LCD_RST_1;
	// Digital_Write(lcd.Getline(3),1);
	lcd.LCD_RSTSet(1);
    Delay_ms(xms);

	// LCD_RST_0;
	lcd.LCD_RSTSet(0);
	// Digital_Write(lcd.Getline(3),0);
	Delay_ms(xms);

	// LCD_RST_1;
	lcd.LCD_RSTSet(1);
	// Digital_Write(lcd.Getline(3),1);
	Delay_ms(xms);
}

static void LCD_1IN47_SetAttributes(uint8_t Scan_dir, LCD_class &lcd)
{
	// Get the screen scan direction
	uint8_t MemoryAccessReg = 0x00;

	// Get GRAM and LCD width and height
	if (Scan_dir == HORIZONTAL)
	{
		MemoryAccessReg = 0X00;
	}
	else
	{	
		MemoryAccessReg = 0X70;
	}

	// Set the read / write scan direction of the frame memory
	lcd.LCD_SendCommand(0x36); // MX, MY, RGB mode
	// LCD_SendData_8Bit(MemoryAccessReg);	//0x08 set RGB
	lcd.LCD_SendData_8Bit(MemoryAccessReg); // 0x08 set RGB
}

static void LCD_1IN47_InitReg(LCD_class &lcd)
{
	lcd.LCD_SendCommand(0x11);
	Delay_ms(120);

	lcd.LCD_SendCommand(0x3A);
	lcd.LCD_SendData_8Bit(0x05);

	lcd.LCD_SendCommand(0xB2);
	lcd.LCD_SendData_8Bit(0x0C);
	lcd.LCD_SendData_8Bit(0x0C);
	lcd.LCD_SendData_8Bit(0x00);
	lcd.LCD_SendData_8Bit(0x33);
	lcd.LCD_SendData_8Bit(0x33);

	lcd.LCD_SendCommand(0xB7);
	lcd.LCD_SendData_8Bit(0x35);

	lcd.LCD_SendCommand(0xBB);
	lcd.LCD_SendData_8Bit(0x35);

	lcd.LCD_SendCommand(0xC0);
	lcd.LCD_SendData_8Bit(0x2C);

	lcd.LCD_SendCommand(0xC2);
	lcd.LCD_SendData_8Bit(0x01);

	lcd.LCD_SendCommand(0xC3);
	lcd.LCD_SendData_8Bit(0x13);

	lcd.LCD_SendCommand(0xC4);
	lcd.LCD_SendData_8Bit(0x20);

	lcd.LCD_SendCommand(0xC6);
	lcd.LCD_SendData_8Bit(0x0F);

	lcd.LCD_SendCommand(0xD0);
	lcd.LCD_SendData_8Bit(0xA4);
	lcd.LCD_SendData_8Bit(0xA1);

	lcd.LCD_SendCommand(0xD6);
	lcd.LCD_SendData_8Bit(0xA1);

	lcd.LCD_SendCommand(0xE0);
	lcd.LCD_SendData_8Bit(0xF0);
	lcd.LCD_SendData_8Bit(0x00);
	lcd.LCD_SendData_8Bit(0x04);
	lcd.LCD_SendData_8Bit(0x04);
	lcd.LCD_SendData_8Bit(0x04);
	lcd.LCD_SendData_8Bit(0x05);
	lcd.LCD_SendData_8Bit(0x29);
	lcd.LCD_SendData_8Bit(0x33);
	lcd.LCD_SendData_8Bit(0x3E);
	lcd.LCD_SendData_8Bit(0x38);
	lcd.LCD_SendData_8Bit(0x12);
	lcd.LCD_SendData_8Bit(0x12);
	lcd.LCD_SendData_8Bit(0x28);
	lcd.LCD_SendData_8Bit(0x30);

	lcd.LCD_SendCommand(0xE1);
	lcd.LCD_SendData_8Bit(0xF0);
	lcd.LCD_SendData_8Bit(0x07);
	lcd.LCD_SendData_8Bit(0x0A);
	lcd.LCD_SendData_8Bit(0x0D);
	lcd.LCD_SendData_8Bit(0x0B);
	lcd.LCD_SendData_8Bit(0x07);
	lcd.LCD_SendData_8Bit(0x28);
	lcd.LCD_SendData_8Bit(0x33);
	lcd.LCD_SendData_8Bit(0x3E);
	lcd.LCD_SendData_8Bit(0x36);
	lcd.LCD_SendData_8Bit(0x14);
	lcd.LCD_SendData_8Bit(0x14);
	lcd.LCD_SendData_8Bit(0x29);
	lcd.LCD_SendData_8Bit(0x32);

	lcd.LCD_SendCommand(0x21);

	lcd.LCD_SendCommand(0x11);
	Delay_ms(120);
	lcd.LCD_SendCommand(0x29);
}

void LCD_1IN47_Init(uint8_t Scan_dir, LCD_class &lcd)
{
	// Hardware reset
	LCD_1IN47_Reset(lcd);

	// Set the resolution and scanning method of the screen
	LCD_1IN47_SetAttributes(Scan_dir, lcd);

	// Set the initialization register
	LCD_1IN47_InitReg(lcd);
}

void LCD_SetWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint8_t Scan_dir, LCD_class &lcd)
{
	if (Scan_dir == HORIZONTAL)
	{ 
		
		// // set the X coordinates
		// lcd.LCD_SendCommand(0x2A);
		// lcd.LCD_SendData_8Bit(0x00);
		// lcd.LCD_SendData_8Bit(Xstart + 0x22);
		// lcd.LCD_SendData_8Bit(((Xend + 0x22) - 1) >> 8);
		// lcd.LCD_SendData_8Bit((Xend + 0x22) - 1);

		// // set the Y coordinates
		// lcd.LCD_SendCommand(0x2B);
		// lcd.LCD_SendData_8Bit(0x00);
		// lcd.LCD_SendData_8Bit(Ystart);
		// lcd.LCD_SendData_8Bit((Yend - 1) >> 8);
		// lcd.LCD_SendData_8Bit(Yend - 1);
		Xstart += 34;
    	Xend   += 34;
		lcd.LCD_SendCommand(0x2A); // Column
		lcd.LCD_SendData_8Bit(Xstart >> 8);
		lcd.LCD_SendData_8Bit(Xstart & 0xFF);
		lcd.LCD_SendData_8Bit((Xend - 1) >> 8);
		lcd.LCD_SendData_8Bit((Xend - 1) & 0xFF);

		lcd.LCD_SendCommand(0x2B); // Row
		lcd.LCD_SendData_8Bit(Ystart >> 8);
		lcd.LCD_SendData_8Bit(Ystart & 0xFF);
		lcd.LCD_SendData_8Bit((Yend - 1) >> 8);
		lcd.LCD_SendData_8Bit((Yend - 1) & 0xFF);
	}
	else
	{ 
		// set the X coordinates
		lcd.LCD_SendCommand(0x2A);
		lcd.LCD_SendData_8Bit(Xstart >> 8);
		lcd.LCD_SendData_8Bit(Xstart);
		lcd.LCD_SendData_8Bit((Xend - 1) >> 8);
		lcd.LCD_SendData_8Bit(Xend - 1);

		// set the Y coordinates
		lcd.LCD_SendCommand(0x2B);
		lcd.LCD_SendData_8Bit(Ystart >> 8);
		lcd.LCD_SendData_8Bit(Ystart + 0x22);
		lcd.LCD_SendData_8Bit((Yend - 1 + 0x22) >> 8);
		lcd.LCD_SendData_8Bit(Yend - 1 + 0x22);
	}

	lcd.LCD_SendCommand(0X2C);
}