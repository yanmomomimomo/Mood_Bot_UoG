#ifndef __PWM_CLASS_HPP
#define __PWM_CLASS_HPP

#include "gpio_pwm.hpp"

extern struct gpiod_chip *chip0;

class PWM_class{
    public:
        PWM_class(uint8_t PWM_number);
        virtual ~PWM_class();

        void Rotation(uint8_t dir);
        void Flash();
    private:
        gpiod_chip* chip_ {chip0};    
        uint8_t Duty_ {100};
        PWM_Pin PWM_0_;
        PWM_Pin PWM_1_;
        uint16_t period {1000};
};

#endif