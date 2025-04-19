#include "../../SYS_Con/Setter_Register.hpp"

// led_event register -> class LEDSetter::
LEDSetter::LEDSetter(LED_class &led) : m_led(led) {
    m_efd = eventfd(0, 0);  // 阻塞模式
    // std::cout<<"[LEDSetter ctor] m_efd="<<m_efd<<std::endl;
    if (m_efd < 0) {
        perror("LEDSetter: eventfd 创建失败");
    }
    registerCallback([this](bool state) {
        toggle();
        // m_led.toggle();
        // std::cout << "LED 状态改变，新状态: " << (state ? "亮" : "灭") << std::endl;
    });
}

LEDSetter::~LEDSetter() {
    close(m_efd);
}

int LEDSetter::getEventFd() const { 
    return m_efd; 
}

void LEDSetter::notifyEvent() {
    uint64_t one = 1;
    ::write(m_efd, &one, sizeof(one));
}

bool LEDSetter::blockAndWaitEvent() {
    uint64_t value = 0;
    // std::cout<<"[LEDSetter read] blocking on "<<m_efd<<std::endl;
    ssize_t s = read(m_efd, &value, sizeof(value));
    if (s == -1) {
        std::cerr << "LEDSetter: 读取 eventfd 失败" << std::endl;
        return false;
    }
    // 如果读取到的 value 大于 0，说明有事件触发
    return (value > 0);
}

void LEDSetter::toggle() {
    m_led.LED_Toggle();
}

bool LEDSetter::getState() const{
    return m_led.getState();
}