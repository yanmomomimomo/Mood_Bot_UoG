#include "OLED_class.hpp"

int main() {
    OLED_class OLED1;

    // OLED1.Word_Show();
    OLED1.Border_Show();
    // OLED1.Word_Show();
    sleep(5);
    OLED1.Warning_Show();
    sleep(5);
    // OLED1.Border_Show();
    // OLED1.Word_Show();

    
    return 0;
}
