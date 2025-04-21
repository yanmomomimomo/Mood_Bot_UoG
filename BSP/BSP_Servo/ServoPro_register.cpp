#include "Setter_Register.hpp"
#include "COM_List.hpp"

SERPSetter::SERPSetter(ServoPRO_class &serp, int periodSec)
          : m_ser(serp),
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

SERPSetter::~SERPSetter(){
    ::close(m_timerfd);
}

int SERPSetter::blockAndWaitEvent(){
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
        return pending_.load();
    }

    if (fds[0].revents & POLLIN) {
        uint64_t expirations;
        ssize_t s = read(m_timerfd, &expirations, sizeof(expirations));
        pending_.store(0); 
        return false;
    }
    return false;
}

void SERPSetter::toggle(int cmd) {
    if (cmd == LEFT) {
        m_ser.Serve_move(-1);
    } else if (cmd == RIGHT){
        m_ser.Serve_move(1);
    }
}

bool SERPSetter::getState() const {
    return m_isWarning;
}

void SERPSetter::notifyEvent(int val){
    pending_.store(val);
    uint64_t one = 1;
    ssize_t s = ::write(m_eventfd, &one, sizeof(one));
    if (s == -1) {
        return;
    }

}