#include "Servo_class.hpp"

float angle_to_pulse_ms(float angle_deg) {
    if (angle_deg < 0) angle_deg = 0;
    if (angle_deg > 180) angle_deg = 180;
    return 0.5 + (angle_deg / 180.0f) * 2.0f;
}

void send_servo_pulse(gpiod_line* line, float pulse_ms, int repeat = 20) {
    int high_us = static_cast<int>(pulse_ms * 1000);
    int period_us = 20000;
    int low_us = period_us - high_us;

    for (int i = 0; i < repeat; ++i) {
        gpiod_line_set_value(line, 1);
        usleep(high_us);
        gpiod_line_set_value(line, 0);
        usleep(low_us);
    }
}


Servo_class::Servo_class(uint8_t offset, const std::string &consumer, int unit_angle, uint8_t count)
    : chip_(chip0), offset_(offset), consumer_(consumer), m_uangle(unit_angle), count_(count), count_max(2*count)
{
    line_ = gpiod_chip_get_line(chip_, offset_);
    if (!line_) {
        return;
    }
    int ret = gpiod_line_request_output(line_, consumer_.c_str(), 0);
    if (ret < 0) {
        return;
    }
    send_servo_pulse(line_, angle_to_pulse_ms(90), 20);

}

Servo_class::~Servo_class() {
    gpiod_line_set_value(line_, 0); 
    gpiod_line_release(line_);
}

void Servo_class::Serve_move(int dir){
    if (dir == 1){
        if (count_ == count_max){return ;}
        count_+=1;
        m_angle+=m_uangle;
        send_servo_pulse(line_, angle_to_pulse_ms(m_angle), 20);
    }else if (dir == -1){
        if (count_ == 0){return ;}
        count_-=1;
        m_angle-=m_uangle;
        send_servo_pulse(line_, angle_to_pulse_ms(m_angle), 20);
    }
}

