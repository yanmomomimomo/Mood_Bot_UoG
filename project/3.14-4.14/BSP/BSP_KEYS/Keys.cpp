#include "Key_class.hpp"

extern struct gpiod_chip *chip0;

Key_class::Key_class(uint8_t offset, const std::string &consumer_key)
    : chip_(chip0), offset_(offset), consumer_(consumer_key)
{
    line_ = gpiod_chip_get_line(chip_, offset_);
    if (!line_) {
        gpiod_chip_close(chip_);
        throw std::runtime_error("Get GPIO Line error!" + std::to_string(offset_));
    }
    
    struct gpiod_line_request_config config = {
        .consumer = consumer_.c_str(),
        .request_type = GPIOD_LINE_REQUEST_EVENT_BOTH_EDGES,
        .flags = GPIOD_LINE_REQUEST_FLAG_BIAS_PULL_UP  // 启用内部上拉
    };

    if (gpiod_line_request(line_, &config, 0) < 0){
        throw std::runtime_error("Line Mode error!" + std::to_string(offset_));
        gpiod_chip_close(chip_);
    }
}

Key_class::~Key_class(){
    gpiod_line_release(line_);
}

// 按键
uint8_t Key_class::Keys_Mode1(){
    uint8_t value = gpiod_line_get_value(line_);
    // printf("电平为%d\n", value);
    if (value == 1){ return KEY_OFF;}
    else if (value == 0){ return KEY_ON;}
    else{
        throw std::runtime_error("value get error!" + std::to_string(offset_));
        gpiod_chip_close(chip0);
        return EOF;
    }
}

static uint8_t Pow_lev = HIGH_POW;
uint8_t Key_class::Keys_Mode2( Edge_modes mode){
    uint8_t value = gpiod_line_get_value(line_);
    if (Pow_lev > value && mode == Falling){
        Pow_lev = value;
        return CLICK;
    }else if (Pow_lev < value && mode == Rising){
        Pow_lev = value;
        return CLICK;
    }else{ 
        Pow_lev = value;
        return NO_CLICK;
    }
}

gpiod_line*  Key_class::getState() const{
    return line_;
}