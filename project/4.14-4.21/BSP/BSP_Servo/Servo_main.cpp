#include "Servo_class.hpp"

int main() {
    SYS_Config();
    Servo_class Servo1(GPIO_Servo1, SER1_CONSUMER, SER1_UANGLE, SER1_COUNT);
    ServoPRO_class Servo2(GPIO_Servo2, SER2_CONSUMER);
    while (true){
        Servo2.Serve_move(0);
    }


    std::cout << "✅ Done." << std::endl;
    return 0;

    std::cout << "Servo pulse sent." << std::endl;
    return 0;
}
