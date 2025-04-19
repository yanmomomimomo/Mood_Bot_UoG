#include <iostream>
#include <thread>
#include <functional>
#include <gpiod.h>
#include <cstring>
#include "../../SYS_Con/Setter_Register.hpp"
#include "../../SYS_Con/Getter_Register.hpp"
#include "../../SYS_Con/EventBus.hpp"

extern struct gpiod_chip *chip0;

int main()
{
    SYS_Config();

    try {
        LED_class led_red(GPIO_LED_RED, CONSUMER_LED_RED);
        LEDSetter led_red_S(led_red); //GPIOSetter

        // 注册 LED 状态回调：切换后打印当前 LED 状态
        
        // 获取 LEDSetter 的 eventfd，用于按键事件通知
        // int efd = led_red_S.getEventFd();

        Key_class key1(GPIO_KEY1, CONSUMER_KEY1);
        Key_class key2(GPIO_KEY2, CONSUMER_KEY2);

        EventBus bus;

        bus.subscribe("key1_press", [&]{ led_red_S.notifyEvent(); });
        bus.subscribe("key2_press", [&]{ led_red_S.notifyEvent(); });

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
    
    // 释放 GPIO 线路和芯片资源
    gpiod_chip_close(chip0);
    
    return 1;
}
