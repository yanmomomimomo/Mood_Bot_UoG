#include "SYS.hpp"

int spi_fd = -1;

int SPI0_Init()
{
    spi_fd = open(SPI_DEVICE, O_RDWR);
    if (spi_fd < 0) {
        perror("Open SPI device failed");
        return -1;
    }

    uint8_t mode = SPI_MODE_0;
    uint8_t bits = 8;
    uint32_t speed = 25000000; // 25MHz
    if (ioctl(spi_fd, SPI_IOC_WR_MODE, &mode) < 0 ||
        ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bits) < 0 ||
        ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
        perror("SPI ioctl config failed");
        return -1;
    }

    uint8_t check_mode;
    ioctl(spi_fd, SPI_IOC_RD_MODE, &check_mode);
    // printf("SPI mode confirmed: %d\n", check_mode);

    return 0;
}

bool Digital_Write(struct gpiod_line *line, int value)
{
    if (!line) {
        fprintf(stderr, "[Digital_Write] line is NULL!\n");
        return false;
    }
    if (!gpiod_line_is_requested(line)) {
        fprintf(stderr, "[Digital_Write] line is NOT requested yet!\n");
        return false;
    }
    if (gpiod_line_set_value(line, value) < 0) {
        perror("[Digital_Write] gpiod_line_set_value failed");
        return false;
    }
    return true;
}

bool SPI_WriteByte(uint8_t value)
{
    // printf("[SPI OUT] 0x%02X\n", value);
    if (write(spi_fd, &value, 1) != 1) {
        perror("SPI_WriteByte failed");
        return false;
    }
    return true;
}

bool SPI_Write_nByte(uint8_t *pData, uint32_t Len)
{
    const int MAX_CHUNK = 4096;  // Linux SPI write
    uint32_t total_written = 0;

    while (total_written < Len) {
        int chunk = (Len - total_written > MAX_CHUNK) ? MAX_CHUNK : (Len - total_written);
        ssize_t written = write(spi_fd, pData + total_written, chunk);

        if (written < 0) {
            perror("SPI chunk write failed");
            return false;
        }

        total_written += written;
    }

    // printf("[SPI BULK] Total written: %d bytes\n", total_written);
    return true;
}

void DEV_Exit()
{
    if (spi_fd >= 0) close(spi_fd);
}