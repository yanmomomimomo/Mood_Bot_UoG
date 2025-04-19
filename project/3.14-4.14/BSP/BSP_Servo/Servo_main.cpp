#include <iostream>
#include <csignal>
#include "Servo_class.hpp"
#include "Servo.hpp"

Servo_class servo;

void handle_signal(int signal) {
    std::cout << "Caught signal " << signal << ", stopping Servo and cleaning up GPIO." << std::endl;
    servo.release_gpio();  
    exit(0); 
}

int main() {
    signal(SIGINT, handle_signal); 
    signal(SIGTERM, handle_signal); 

    if (!servo.Servo_init()) {  
        return 1;
    }

    while (true){
        servo.Servo_down(Servo1);
        sleep(1);
        servo.Servo_down(Servo1);
        sleep(1);
        servo.Servo_down(Servo1);
        sleep(1);
        servo.Servo_up(Servo1);
        sleep(1);
        servo.Servo_up(Servo1);
        sleep(1);
        servo.Servo_up(Servo1);
        sleep(1);
    }
    
    
    
    servo.release_gpio(); 

    return 0;
}
