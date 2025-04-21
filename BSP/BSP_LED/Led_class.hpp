#ifndef __LED_CLASS_HPP
#define __LED_CLASS_HPP

#include <string>
#include <gpiod.h>
#include "Led.hpp"

extern gpiod_chip *chip0;

class LED_class {
public:
    LED_class(uint8_t offset, const std::string &consumer);
    virtual ~LED_class();

    void LED_Flash(uint8_t times);
    void LED_SWITCH(uint8_t signal);
    void LED_Toggle();
    bool getState();

private:
    gpiod_chip* chip_ {chip0};      
    gpiod_line* line_ {nullptr};      
    uint8_t offset_ {0};           
    std::string consumer_ {nullptr};  
};

#endif // LED_HPP