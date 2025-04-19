#include "Led_class.hpp"

extern struct gpiod_chip *chip0;

LED_class::LED_class(uint8_t offset, const std::string &consumer)
    : chip_(chip0), offset_(offset), consumer_(consumer)
{
    // 获取指定偏移号的 GPIO 线路
    line_ = gpiod_chip_get_line(chip_, offset_);
    if (!line_) {
        gpiod_chip_close(chip_);
        throw std::runtime_error("Get GPIO Line error!" + std::to_string(offset_));
    }

    // 请求该线路为输出模式，初始电平为低 (0)
    if (gpiod_line_request_output(line_, consumer_.c_str(), 0) < 0) {
        gpiod_chip_close(chip_);
        throw std::runtime_error("LED mode error!");
    }

    LED_Flash(1);
}

LED_class::~LED_class(){
    if (line_){
        gpiod_line_set_value(line_, 0);
        gpiod_line_release(line_);
    }
}

void LED_class::LED_Flash(uint8_t times){
    for(int i = 1; i<times; i++){
        gpiod_line_set_value(line_, 1);
        usleep(800000);
        gpiod_line_set_value(line_, 0);
        usleep(800000);
    }
}

void LED_class::LED_SWITCH( uint8_t signal){
    if (signal == LED_ON){
        gpiod_line_set_value(line_, 1);
    }else if (signal == LED_OFF){
        gpiod_line_set_value(line_, 0);
    }
}

// true -> high power       false -> low power
bool LED_class::getState() {
    int val = gpiod_line_get_value(line_);
    if (val < 0) {
        std::cerr << "读取 LED 状态失败（offset=" << offset_ << "）" << std::endl;
        return false;
    }
    return (val == 1);
}

void LED_class::LED_Toggle(){
    if (getState()){
        gpiod_line_set_value(line_, 0);
    }else{
        gpiod_line_set_value(line_, 1);
    }
}