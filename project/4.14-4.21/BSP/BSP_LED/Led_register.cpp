#include "Setter_Register.hpp"

// led_event register -> class LEDSetter::
LEDSetter::LEDSetter(LED_class &led) : m_led(led) {
    m_efd = eventfd(0, 0); 
    // std::cout<<"[LEDSetter ctor] m_efd="<<m_efd<<std::endl;
    if (m_efd < 0) {
        perror("LEDSetter: eventfd 创建失败");
    }
    registerCallback([this](int cmd) {
        toggle(cmd);
    });
}

LEDSetter::~LEDSetter() {
    close(m_efd);
}

void LEDSetter::notifyEvent(int val) {
    if (val == -1){
        m_led.LED_SWITCH(LED_OFF);
    }else{
        pending_.store(val);
        uint64_t one = 1;
        ::write(m_efd, &one, sizeof(one)); 
    }
}

int LEDSetter::blockAndWaitEvent() {
    uint64_t value = 0;
    // std::cout<<"[LEDSetter read] blocking on "<<m_efd<<std::endl;
    ssize_t s = ::read(m_efd, &value, sizeof(value));
    if (s == -1) {
        return 0;
    }
    return pending_.load();        
}

void LEDSetter::toggle(int cmd) {
    // int cmd = blockAndWaitEvent();
    // printf("%d",cmd);
    if (cmd == 1) {
        m_led.LED_Toggle();
    } else if (cmd == 2) {
        m_led.LED_Flash(1);
    } else if (cmd == 3) {
        m_led.LED_Flash(2);
    }
}

bool LEDSetter::getState() const{
    return m_led.getState();
}