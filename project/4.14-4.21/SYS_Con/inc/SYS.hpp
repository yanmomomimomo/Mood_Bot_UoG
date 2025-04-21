#ifndef __SYS_HPP
#define __SYS_HPP

#include <gpiod.h>
#include <iostream>
#include <cstdlib>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <cstring>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <linux/spi/spidev.h>
#include <any>

// devices
#include "Getter_Register.hpp"
#include "Setter_Register.hpp"
#include "COM_List.hpp"
#include "faces.hpp"

// SPI0
#define SPI_DEVICE "/dev/spidev0.0"
#define SPI_SPEED  25000000  // 25MHz
#define SPI_MODE   SPI_MODE_0

// SSD1306 I2C-1
#define I2C1_ADDRESS  0x3C
#define I2C1_DEV "/dev/i2c-1"

// UART
#define SERIAL_DEV  "/dev/ttyAMA10"

extern struct gpiod_chip *chip0;

void SYS_Config();

// I2C-1
extern int i2c_fd;
bool I2C_writeCommand(uint8_t cmd);
bool I2C_writeData(const uint8_t* data, size_t len);

// SPI0
extern int spi_fd;
bool SPI_WriteByte(uint8_t value);
bool SPI_Write_nByte(uint8_t *pData, uint32_t Len);
bool Digital_Write(struct gpiod_line *line, int value);
int SPI0_Init();
void DEV_Exit();
#endif // __SYS_H