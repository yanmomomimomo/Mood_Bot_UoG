#include "Getter_Register.hpp"

// led_event register -> class LEDSetter::
KeyGetter::KeyGetter(Key_class &key, EventBus &bus, const std::string &topic)
    : m_key(key), m_bus(bus), m_topic(topic)
{
    
    registerCallback([this](uint8_t event) {
        if (event == CLICK) {
            m_bus.publish(m_topic, 2);
        }
        
    });
}

KeyGetter::~KeyGetter() {

}

int KeyGetter::blockAndWaitEvent() {
    int ret = gpiod_line_event_wait(m_key.getState(), nullptr);
    if (ret < 0) {
        return false;
    }else if(ret = 0){
        return false;
    }

    struct gpiod_line_event event;
    if (gpiod_line_event_read(m_key.getState(), &event) < 0) {
        return false;
    }
    if (event.event_type == GPIOD_LINE_EVENT_FALLING_EDGE) {
        return true; 
    }
    return false;
}

void KeyGetter::notifyStop(int val){}