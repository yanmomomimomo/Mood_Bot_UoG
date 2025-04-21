#ifndef __SERVO_CLASS_HPP
#define __SERVO_CLASS_HPP

#include "Servo.hpp"
class Servo_class {
public:
    Servo_class(uint8_t offset, const std::string &consumer, int unit_angle, uint8_t count);
    ~Servo_class();

    void Serve_move(int dir);
private:
    struct gpiod_chip *chip_ {chip0};
    uint8_t offset_;
    const std::string consumer_;
    struct gpiod_line *line_;
    uint16_t duty_;              
    int period_us {20000};            
    int m_angle{90};
    int m_uangle;
    uint8_t count_;
    uint8_t count_max;
};

class ServoPRO_class {
    public:
        ServoPRO_class(uint8_t offset, const std::string &consumer);
        ~ServoPRO_class();
    
        void Serve_move(int dir);
    private:
        struct gpiod_chip *chip_ {chip0};
        uint8_t offset_;
        const std::string consumer_;
        struct gpiod_line *line_;
};


#endif // SERVO_CLASS_HPP_INCLUDED
