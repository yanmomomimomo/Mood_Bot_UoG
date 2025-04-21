#include "Setter_Register.hpp"
#include "COM_List.hpp"

OLEDSetter::OLEDSetter(OLED_class &oled, int periodSec)
          : m_oled(oled),
            m_isWarning(false)
{
    m_timerfd = ::timerfd_create(CLOCK_MONOTONIC, 0);
    if (m_timerfd < 0) {
        perror("OLEDSetter: timerfd_create");
    }
    struct itimerspec its;
    std::memset(&its, 0, sizeof(its));
    its.it_value.tv_sec    = periodSec;
    its.it_interval.tv_sec = periodSec;
    if (timerfd_settime(m_timerfd, 0, &its, nullptr) < 0) {
        perror("OLEDSetter: timerfd_settime");
    }

     m_eventfd = eventfd(0, 0);
     if (m_eventfd < 0) {
         perror("eventfd_create failed");
     }

    registerCallback([this](int cmd) {
        toggle(cmd);
    });
}

OLEDSetter::~OLEDSetter(){
    ::close(m_timerfd);
}

int OLEDSetter::blockAndWaitEvent(){
    struct pollfd fds[2];
    fds[0].fd     = m_timerfd;
    fds[0].events = POLLIN;

    fds[1].fd     = m_eventfd;
    fds[1].events = POLLIN;

    int ret = ::poll(fds, 2, -1);
    if (ret < 0) {
        perror("OLEDSetter: poll");
        return false;
    }
    if (fds[1].revents & POLLIN) {
        uint64_t val;
        ssize_t s = ::read(m_eventfd, &val, sizeof(val));
        if (s == -1) {
            return 0;
        }
        // std::cout<<s<<"\t"<<pending_.load()<<std::endl;
        return pending_.load();
    }

    if (fds[0].revents & POLLIN) {
        uint64_t expirations;
        ssize_t s = read(m_timerfd, &expirations, sizeof(expirations));
        if (m_isWarning){
            m_oled.Border_Show();
            m_isWarning = !m_isWarning;
        }
        pending_.store(0); 
        m_oled.Date_upgrade();
        return false;
    }
    return false;
}

void OLEDSetter::toggle(int cmd) {
    if (cmd == OLED_WARNING) {
        m_oled.Warning_Show();
        m_isWarning = true;
    } else{
        if (m_isWarning){
            m_oled.Border_Show();
            m_isWarning = !m_isWarning;
        }
        m_oled.Date_upgrade();
        // std::cout<<cmd<<std::endl;
        m_oled.TM_upgrade(cmd);
        // m_oled.Word_Show();
    }
}

bool OLEDSetter::getState() const {
    return m_isWarning;
}

void OLEDSetter::notifyEvent(int val){
    if (val == -1){
        m_oled.OLED_Shootdown();
    }else{
        pending_.store(val);
        uint64_t one = 1;
        ssize_t s = ::write(m_eventfd, &one, sizeof(one));
        if (s == -1) {
            return;
        }
    }
}