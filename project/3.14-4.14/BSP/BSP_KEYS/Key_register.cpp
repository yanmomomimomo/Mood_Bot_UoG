#include "../../SYS_Con/Getter_Register.hpp"
#include "../../SYS_Con/Setter_Register.hpp"
#include "Key_class.hpp"
#include "../../SYS_Con/EventBus.hpp"

// // led_event register -> class LEDSetter::
KeyGetter::KeyGetter(Key_class &key, EventBus &bus, const std::string &topic)
    : m_key(key), m_bus(bus), m_topic(topic)
{
    
    registerCallback([this](uint8_t event) {
        if (event == CLICK) {
            m_bus.publish(m_topic);
        }
        // std::cout << "key_event_loop: 检测到按键 CLICK" << std::endl;
        
    });
}

KeyGetter::~KeyGetter() {

}

bool KeyGetter::blockAndWaitEvent() {
    int ret = gpiod_line_event_wait(m_key.getState(), nullptr);
    if (ret < 0) {
        std::cerr << "key_event_loop: gpiod_line_event_wait 调用失败" << std::endl;
        return false;
    }else if(ret = 0){
        return false;
    }

    struct gpiod_line_event event;
    if (gpiod_line_event_read(m_key.getState(), &event) < 0) {
        std::cerr << "key_event_loop: 读取按键事件失败" << std::endl;
        return false;
    }
    if (event.event_type == GPIOD_LINE_EVENT_FALLING_EDGE) {
        return true;  // 1 表示按键点击
    }
    return false;
}

