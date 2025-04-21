#include "Getter_Register.hpp"

RDGetter::RDGetter(RD_class &RD, EventBus &bus, const std::string &topic)
    : m_RD(RD), m_bus(bus), m_topic(topic)
{
    m_efd = eventfd(0, 0);
    if (m_efd < 0) {
    }
    registerCallback([this](uint8_t event) {
        std::cout<<event<<std::endl;
        m_bus.publish(m_topic, 0);
    });
}

RDGetter::~RDGetter() {

}

int RDGetter::blockAndWaitEvent() {
    uint64_t value = 0;
    // std::cout<<"[LEDSetter read] blocking on "<<m_efd<<std::endl;
    ssize_t s = ::read(m_efd, &value, sizeof(value));
    // std::cout<<value<<std::endl;
    if (s == -1) {
        return 0;
    }
    
    if (value == NO_LIGHT){
        return 1;
    } else{
        return 0;
    }
}

void RDGetter::notifyStop(int val){}


void RDGetter::startWatcher() {
    m_watchRunning.store(true);
    m_watchThread = std::thread([this]() {
        while (m_watchRunning.load()) {
            int state = m_RD.GetValue();
            if (state == NO_HUM) {
                // std::cout<<state<<std::endl;
                uint64_t one = 1;
                ::write(m_efd, &one, sizeof(one));
            } else {continue;}
        }
    });
}

void RDGetter::stopWatcher() {
    m_watchRunning.store(false);
    if (m_watchThread.joinable()) {
        m_watchThread.join();
    }
}