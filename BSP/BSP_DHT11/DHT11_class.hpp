#ifndef __DHT11_CLASS_HPP
#define __DHT11_CLASS_HPP

#include "DHT11.hpp"

extern struct gpiod_chip* chip0;

class DHT11_class{
    public:
        DHT11_class(uint8_t offset, const std::string &consumer_key);
        ~DHT11_class();

        int MT_check();

    private:
        struct gpiod_chip *chip_ {chip0};
        uint8_t offset_;
        const std::string consumer_;
        struct gpiod_line *line_;

};

#endif // __DHT11_CLASS_HPP