#include "Led.hpp"
#include "Led_class.hpp"

extern struct gpiod_chip *chip0;
extern struct gpiod_line *line_red, *line_yellow;

int main(void)
{
    SYS_Config();
    try {
        // LED_class led_red(GPIO_LED_RED, CONSUMER_LED_RED);
        // LED_class led_yellow(GPIO_LED_YEL, CONSUMER_LED_YEL);
        
        // //
        // // LEDCallback red_callback = [](bool state) {
        // //     std::cout << "[回调] LED 状态更新，新状态: " << (state ? "ON" : "OFF") << std::endl;
        // // };
        // // LEDCallback yel_callback = [](bool state) {
        // //     std::cout << "[回调] LED 状态更新，新状态: " << (state ? "ON" : "OFF") << std::endl;
        // // };
        
        // int intervalSec = 2;
        // int totalEvents = 10;
        
        // std::thread redThread(led_event_loop, std::ref(led_red), intervalSec, red_callback, totalEvents);
        // std::thread yelThread(led_event_loop, std::ref(led_yellow), intervalSec, yel_callback, totalEvents);

        // redThread.join();
        // yelThread.join();

    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        gpiod_chip_close(chip0);
        return 1;
    }
    gpiod_chip_close(chip0);
    return 0;
}