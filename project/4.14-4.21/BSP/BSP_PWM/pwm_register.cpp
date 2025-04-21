#include "Setter_Register.hpp"
#include "COM_List.hpp"

PWMSetter::PWMSetter(PWM_class &pwm, int periodSec)
          : m_pwm(pwm),
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

PWMSetter::~PWMSetter(){
    ::close(m_timerfd);
}

int PWMSetter::blockAndWaitEvent(){
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
            std::cerr << "LEDSetter: 读取 eventfd 失败" << std::endl;
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

void PWMSetter::toggle(int cmd) {
    if (cmd == Clockwise) {
        m_pwm.Rotation(Clockwise);
    } else if (cmd == Cou_Clockwise){
        m_pwm.Rotation(Cou_Clockwise);
    }
}

bool PWMSetter::getState() const {
    return m_isWarning;
}

void PWMSetter::notifyEvent(int val){
    pending_.store(val);
    uint64_t one = 1;
    ssize_t s = ::write(m_eventfd, &one, sizeof(one));
    if (s == -1) {
        std::cerr << "LEDSetter: 读取 eventfd 失败" << std::endl;
        return;
    }

}