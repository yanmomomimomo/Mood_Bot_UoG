/************************* Functions of SYSTools *************************/
// Header Declaration
#include "SYSConfig.h"

// Functions
void Task(bool &running, int KEY_PIN, std::function<void()> callback) {
    
    while (running) {
        if (Key_Press_Mode1(KEY_PIN)) {
            callback();
        }
        Delay(10);
    }
}

/*********************************** END **********************************/