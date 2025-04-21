#include <iostream>
#include <thread>
#include <functional>
#include <gpiod.h>
#include <cstring>
#include "Setter_Register.hpp"
#include "Getter_Register.hpp"
#include "EventBus.hpp"

extern struct gpiod_chip *chip0;

int main()
{
    SYS_Config();

    try {
        LED_class led_red(GPIO_LED_RED, CONSUMER_LED_RED);
        LEDSetter led_red_S(led_red); 

        Key_class key1(GPIO_KEY1, CONSUMER_KEY1);
        Key_class key2(GPIO_KEY2, CONSUMER_KEY2);

        EventBus bus;

        bus.subscribe("key1_press", [&](int val){ led_red_S.notifyEvent(val); });
        bus.subscribe("key2_press", [&](int val){ led_red_S.notifyEvent(val); });

        KeyGetter key1_G(key1, bus, "key1_press");
        KeyGetter key2_G(key2, bus, "key2_press");

        led_red_S.start();
        key1_G.start();
        key2_G.start();

        std::this_thread::sleep_for(std::chrono::seconds(10));

    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        gpiod_chip_close(chip0);
        return 1;
    }
    
    gpiod_chip_close(chip0);
    
    return 1;
}
