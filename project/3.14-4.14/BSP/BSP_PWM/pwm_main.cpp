#include <iostream>
#include <csignal>
#include "pwm_class.hpp"
#include "../../SYS_Con/SYS.hpp"

int main() {
    SYS_Config();
    try{
        class PWM_class PWM1(PWMGROUP1);
        class PWM_class PWM2(PWMGROUP2);

        int count = 10000;
        while (count){
            // printf("%d",count);
            PWM2.Rotation(Cou_Clockwise);
            // sleep(1);
            // PWM2.Rotation(Clockwise);
            // sleep(1);
            count --;
        }
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        gpiod_chip_close(chip0);
        return 1;
    }
    gpiod_chip_close(chip0);
    return 0;
}
