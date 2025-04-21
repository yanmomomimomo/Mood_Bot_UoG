#include "SYS.hpp"

struct gpiod_chip *chip0;
// static gpiod_line *Key1_line, *Key2_line;
// static gpiod_line *line_red, *line_yellow;

void SYS_Config(){
    
    chip0 = gpiod_chip_open_by_name("gpiochip0");
}