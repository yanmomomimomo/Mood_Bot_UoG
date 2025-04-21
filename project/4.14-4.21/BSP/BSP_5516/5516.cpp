#include "5516_class.hpp"

S5516_class::S5516_class(uint8_t offset, const std::string &consumer)
    : chip_(chip0), offset_(offset), consumer_(consumer)
{
    line_ = gpiod_chip_get_line(chip_, offset_);
    if (!line_) {
        gpiod_chip_close(chip_);
        return;
    }

    if (gpiod_line_request_input(line_, consumer_.c_str()) < 0) {
        gpiod_chip_close(chip_);
        return;
    }
}

S5516_class::~S5516_class(){
    if (line_){
        gpiod_line_set_value(line_, 0);
        gpiod_line_release(line_);
    }
}

int S5516_class::GetValue(){
    int high_count = 0;
    for (int i = 0; i < 5; ++i) {
        int v = gpiod_line_get_value(line_);
        if (v < 0) {
            break;
        }
        if (v) 
            high_count++;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    if (high_count >= 3) {
        return NO_LIGHT;
    } else {
        return LIGHT;
    }

}