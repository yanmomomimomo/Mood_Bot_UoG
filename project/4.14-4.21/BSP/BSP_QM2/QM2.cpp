#include "QM2_class.hpp"

QM2_class::QM2_class(uint8_t offset, const std::string &consumer)
: offset_(offset), consumer_(consumer), chip_(chip0)
{
    if (!chip_) {
        std::perror("❌ 打开 gpiochip0 失败");
        std::exit(EXIT_FAILURE);
    }
    // 获取烟雾输入线
    line_ = gpiod_chip_get_line(chip_, offset_);
    if (!line_) {
        std::perror("获取烟雾检测线失败");
        gpiod_chip_close(chip_);
        return ;
    }
    if (gpiod_line_request_input(line_, consumer_.c_str()) < 0) {
        std::perror("请求烟雾检测输入模式失败");
        gpiod_chip_close(chip_);
        return ;
    }
}

QM2_class::~QM2_class() {
    gpiod_line_release(line_);
}

int QM2_class::Smoke_check(){
    int high_count = 0;
    // 多次采样
    for (int i = 0; i < sample_c; ++i) {
        int v = gpiod_line_get_value(line_);
        if (v < 0) {
            std::perror("读取烟雾检测线值失败");
            break;
        }
        if (v) 
            high_count++;
            std::this_thread::sleep_for(std::chrono::milliseconds(sample_i));
    }

    // 判断是否超标
    if (high_count <= THRESHOLD_COUNT) {
        return SMOKE_ERR;
    } else {
        return SMOKE_NOR;
    }
}

struct gpiod_line* QM2_class::getState(){
    return line_;
}