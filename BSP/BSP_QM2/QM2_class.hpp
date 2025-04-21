#ifndef __QM2_CLASS_HPP
#define __QM2_CLASS_HPP

#include "QM2.hpp"

extern struct gpiod_chip* chip0;

class QM2_class{
    public:
        QM2_class(uint8_t offset, const std::string &consumer_key);
        ~QM2_class();

        int Smoke_check();
        struct gpiod_line* getState();

    private:
        struct gpiod_chip *chip_ {chip0};
        uint8_t offset_;
        const std::string consumer_;
        struct gpiod_line *line_;
        uint8_t threshold_ {THRESHOLD_COUNT};
        uint8_t sample_c {SAMPLE_COUNT_QM2};
        uint8_t sample_i {SAMPLE_INTERVAL_MS};

};

#endif // __QM2_CLASS_HPP