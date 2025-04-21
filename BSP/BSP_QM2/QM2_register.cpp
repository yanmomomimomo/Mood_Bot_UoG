#include "Getter_Register.hpp"

// led_event register -> class LEDSetter::
QM2Getter::QM2Getter(QM2_class &qm2, EventBus &bus, const std::string &topic)
    : m_qm2(qm2), m_bus(bus), m_topic(topic)
{
    m_efd = eventfd(0, 0);
    if (m_efd < 0) {
        perror("LEDSetter: eventfd 创建失败");
    }
    registerCallback([this](uint8_t event) {
        std::cout<<event<<std::endl;
        m_bus.publish(m_topic, 0);
    });
}

QM2Getter::~QM2Getter() {

}

int QM2Getter::blockAndWaitEvent() {
    uint64_t value = 0;
    // std::cout<<"[LEDSetter read] blocking on "<<m_efd<<std::endl;
    ssize_t s = ::read(m_efd, &value, sizeof(value));
    // std::cout<<value<<std::endl;
    if (s == -1) {
        return 0;
    }
    
    if (value == SMOKE_ERR){
        return 1;
    } else{
        return 0;
    }
}

void QM2Getter::notifyStop(int val){}


void QM2Getter::startWatcher() {
    m_watchRunning.store(true);
    m_watchThread = std::thread([this]() {
        while (m_watchRunning.load()) {
            int state = m_qm2.Smoke_check();
            if (state == SMOKE_ERR) {
                // std::cout<<state<<std::endl;
                uint64_t one = 1;
                ::write(m_efd, &one, sizeof(one));
            } else {continue;}
        }
    });
}

void QM2Getter::stopWatcher() {
    m_watchRunning.store(false);
    if (m_watchThread.joinable()) {
        m_watchThread.join();
    }
}