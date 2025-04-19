#include "SYS.hpp"

struct gpiod_chip *chip0;
// static gpiod_line *Key1_line, *Key2_line;
// static gpiod_line *line_red, *line_yellow;

void SYS_Config(){
    // chip0 = gpiod_chip_open_by_name("gpiochip0");
    // Key2_line = gpiod_chip_get_line(chip0, GPIO_KEY2);
    // Key1_line = gpiod_chip_get_line(chip0, GPIO_KEY1);
    // line_red = gpiod_chip_get_line(chip0, GPIO_LED_RED);
    // line_yellow = gpiod_chip_get_line(chip0, GPIO_LED_YEL);
    // if (!Key2_line || !Key1_line || !line_red || !line_yellow) {
    //     perror("无法获取目标GPIO线路");
    //     gpiod_chip_close(chip0);
    //     exit(EXIT_FAILURE);
    // }

    // gpiod_line_release(Key2_line);
    // gpiod_line_release(Key1_line);
    // gpiod_line_release(line_red);
    // gpiod_line_release(line_yellow);

    // gpiod_chip_close(chip0);

    // sleep(1);
    chip0 = gpiod_chip_open_by_name("gpiochip0");
}