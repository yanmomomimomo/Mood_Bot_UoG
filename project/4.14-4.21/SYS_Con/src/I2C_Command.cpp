#include "SYS.hpp"

int i2c_fd = -1;

bool I2C_writeCommand(uint8_t cmd) {
    uint8_t buf[2] = { 0x00, cmd };
    if (write(i2c_fd, buf, 2) != 2) {
        return false;
    }
    return true;
}

bool I2C_writeData(const uint8_t* data, size_t len) {
    uint8_t* buf = new uint8_t[len + 1];
    buf[0] = 0x40;
    std::memcpy(buf + 1, data, len);
    if (write(i2c_fd, buf, len + 1) != (ssize_t)(len + 1)) {
        delete[] buf;
        return false;
    }
    delete[] buf;
    return true;
}