#include "Servo_class.hpp"

void send_servo_for_duration(gpiod_line* line, float pulse_ms, float duration_sec) {
    int high_us = static_cast<int>(pulse_ms * 1000);
    int period_us = 20000;
    int low_us = period_us - high_us;

    int cycles = static_cast<int>((duration_sec * 1000000) / period_us);

    for (int i = 0; i < cycles; ++i) {
        gpiod_line_set_value(line, 1);
        usleep(high_us);
        gpiod_line_set_value(line, 0);
        usleep(low_us);
    }
}

ServoPRO_class::ServoPRO_class(uint8_t offset, const std::string &consumer)
    : chip_(chip0), offset_(offset), consumer_(consumer)
{
    line_ = gpiod_chip_get_line(chip_, offset_);
    if (!line_) {
        return;
    }
    int ret = gpiod_line_request_output(line_, consumer_.c_str(), 0);
    if (ret < 0) {
        return;
    }
}

ServoPRO_class::~ServoPRO_class() {
    gpiod_line_set_value(line_, 0); 
    gpiod_line_release(line_);
}

void ServoPRO_class::Serve_move(int dir){
    if (dir == 1){
        send_servo_for_duration(line_, 1.65, 0.10);
    }else if (dir == -1){
        send_servo_for_duration(line_, 1.35, 0.30); 
    }else if (dir == 0){
        send_servo_for_duration(line_, 1.47, 0.5); 
    }
}

