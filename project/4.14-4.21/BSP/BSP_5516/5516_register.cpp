#include "Getter_Register.hpp"

// led_event register -> class LEDSetter::
S5516Getter::S5516Getter(S5516_class &S5516, EventBus &bus, const std::string &topic)
    : m_5516(S5516), m_bus(bus), m_topic(topic)
{
    m_efd = eventfd(0, 0); 
    if (m_efd < 0) {
    }
    registerCallback([this](uint8_t event) {
        std::cout<<event<<std::endl;
        m_bus.publish(m_topic, 0);
    });
}

S5516Getter::~S5516Getter() {

}

int S5516Getter::blockAndWaitEvent() {
    uint64_t value = 0;
    ssize_t s = ::read(m_efd, &value, sizeof(value));
    if (s == -1) {
        std::cerr << "LEDSetter: 读取 eventfd 失败" << std::endl;
        return 0;
    }
    
    if (value == NO_LIGHT){
        return 1;
    } else{
        return 0;
    }
}

void S5516Getter::notifyStop(int val){}


void S5516Getter::startWatcher() {
    m_watchRunning.store(true);
    m_watchThread = std::thread([this]() {
        while (m_watchRunning.load()) {
            int state = m_5516.GetValue();
            if (state == SMOKE_ERR) {
                uint64_t one = 1;
                ::write(m_efd, &one, sizeof(one));
            } else {continue;}
        }
    });
}

void S5516Getter::stopWatcher() {
    m_watchRunning.store(false);
    if (m_watchThread.joinable()) {
        m_watchThread.join();
    }
}