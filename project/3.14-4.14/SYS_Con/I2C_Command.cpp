#include "SYS.hpp"

int i2c_fd = -1;

/**
 * @brief 向 SSD1306 发送命令
 * SSD1306 要求命令前先发送 0x00 控制字节
 */
bool I2C_writeCommand(uint8_t cmd) {
    uint8_t buf[2] = { 0x00, cmd };
    if (write(i2c_fd, buf, 2) != 2) {
        std::cerr << "OLED 命令写入失败: " << strerror(errno) << std::endl;
        return false;
    }
    return true;
}

/**
 * @brief 向 SSD1306 发送数据
 * SSD1306 数据写入时首字节为 0x40
 */
bool I2C_writeData(const uint8_t* data, size_t len) {
    uint8_t* buf = new uint8_t[len + 1];
    buf[0] = 0x40;
    std::memcpy(buf + 1, data, len);
    if (write(i2c_fd, buf, len + 1) != (ssize_t)(len + 1)) {
        std::cerr << "OLED 数据写入失败: " << strerror(errno) << std::endl;
        delete[] buf;
        return false;
    }
    delete[] buf;
    return true;
}