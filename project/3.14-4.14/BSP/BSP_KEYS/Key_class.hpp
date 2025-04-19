#ifndef __KEY_CLASS_HPP
#define __KEY_CLASS_HPP

#include <string>
#include <gpiod.h>
#include "Keys.hpp"

extern gpiod_chip *chip0;

class Key_class{
    public:
        Key_class(uint8_t offset, const std::string &consumer_key);
        virtual ~Key_class();

        uint8_t Keys_Mode1();
        uint8_t Keys_Mode2(Edge_modes mode);
        gpiod_line* getState() const;

    private:
        struct gpiod_chip *chip_ {chip0};
        uint8_t offset_;
        const std::string consumer_;
        struct gpiod_line *line_;
        
};

#endif // __KEYS_CLASS_HPP