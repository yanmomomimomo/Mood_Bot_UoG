#include "Servo_class.hpp"
#include <iostream>
#include <unistd.h>
#include <map>
#include <mutex>
#include <thread>

Servo_class::Servo_class(const char* chip_path) {
    chip_ = gpiod_chip_open(chip_path);
    if (!chip_) {
        std::cerr << "Failed to open GPIO chip!" << std::endl;
    }
}

Servo_class::~Servo_class() {
    if (chip_) {
        gpiod_chip_close(chip_);
    }
}

bool Servo_class::Servo_init() {
    return chip_ != nullptr;
}

gpiod_line* Servo_class::get_gpio_line(int pin) {
    // ��鲢���� GPIO ���Ŷ��󣬱����ظ�����
    if (gpio_lines_.find(pin) != gpio_lines_.end()) {
        return gpio_lines_[pin];
    }

    gpiod_line* line = gpiod_chip_get_line(chip_, pin);
    if (!line) {
        std::cerr << "Failed to get GPIO line " << pin << "!" << std::endl;
        return nullptr;
    }

    int ret = gpiod_line_request_output(line, "Servo", 0);
    if (ret < 0) {
        std::cerr << "Failed to request GPIO line " << pin << " as output! Error code: " << ret << std::endl;
        return nullptr;
    }

    gpio_lines_[pin] = line;
    return line;
}


void Servo_class::set_pwm_output(int pin, int duty_cycle_percent) {
    if (duty_cycle_percent < 0 || duty_cycle_percent > 100) {
        std::cerr << "Invalid duty cycle! Must be 0�C100." << std::endl;
        return;
    }

    std::lock_guard<std::mutex> lock(pwm_mutex_);
    pwm_running_[pin] = true;

    gpiod_line* line = get_gpio_line(pin);
    if (!line) return;

    int duty_us = PERIOD_US * duty_cycle_percent / 100;
    int low_us = PERIOD_US - duty_us;

    // ����Ѵ��� PWM �̣߳�����ֹͣ
    if (pwm_threads_.find(pin) != pwm_threads_.end()) {
        pwm_running_[pin] = false;
        if (pwm_threads_[pin].joinable()) {
            pwm_threads_[pin].join();
        }
    }

    // �����µ� PWM �����߳�
    pwm_threads_[pin] = std::thread([=]() {
        while (pwm_running_[pin]) {
            gpiod_line_set_value(line, 1);
            usleep(duty_us);
            gpiod_line_set_value(line, 0);
            usleep(low_us);
        }

        // ȷ���˳�ʱ���͵�ƽ
        gpiod_line_set_value(line, 0);
    });
}

void Servo_class::Servo_disable(int pin) {
    std::lock_guard<std::mutex> lock(pwm_mutex_);
    if (pwm_running_.count(pin)) {
        pwm_running_[pin] = false;
        if (pwm_threads_[pin].joinable()) {
            pwm_threads_[pin].join();
        }
        pwm_threads_.erase(pin);
        pwm_running_.erase(pin);
    }
}

void Servo_class::release_gpio() {
    // �ͷ�������� GPIO ����
    for (auto& pair : gpio_lines_) {
        gpiod_line_set_value(pair.second, 0); // ����
        gpiod_line_release(pair.second);
    }
    gpio_lines_.clear();
}



void Servo_class::set_pwm_pulse_ms(int pin, float pulse_ms) {
    if (pulse_ms < 0.5 || pulse_ms > 2.5) {
        std::cerr << "Pulse width out of typical range (0.5ms�C2.5ms): " << pulse_ms << "ms" << std::endl;
    }

    std::lock_guard<std::mutex> lock(pwm_mutex_);
    pwm_running_[pin] = true;

    gpiod_line* line = get_gpio_line(pin);
    if (!line) return;

    int high_us = static_cast<int>(pulse_ms * 1000); // ת��Ϊ΢��
    int period_us = 20000; // 50Hz -> 20ms����
    int low_us = period_us - high_us;

    // ֹͣ�ɵ� PWM �̣߳������ڣ�
    if (pwm_threads_.find(pin) != pwm_threads_.end()) {
        pwm_running_[pin] = false;
        if (pwm_threads_[pin].joinable()) {
            pwm_threads_[pin].join();
        }
    }

    pwm_threads_[pin] = std::thread([=]() {
        while (pwm_running_[pin]) {
            gpiod_line_set_value(line, 1);
            usleep(high_us);
            gpiod_line_set_value(line, 0);
            usleep(low_us);
        }
        gpiod_line_set_value(line, 0); // ֹͣʱ����
    });
}

void Servo_class::Servo_up(int pin){
    set_pwm_pulse_ms(pin, 1.6); //  1.5ms ���壨ֹͣ��
    usleep(100*1000);
    Servo_disable(pin);
}

void Servo_class::Servo_down(int pin){
    set_pwm_pulse_ms(pin, 1.3); //  1.5ms ���壨ֹͣ��
    usleep(20*1000);
    Servo_disable(pin);
}
