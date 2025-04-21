#include "Setter_Register.hpp"
#include "COM_List.hpp"

AudioSetter::AudioSetter(Audio_class &audio, int periodSec )
          : m_audio(audio),
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

AudioSetter::~AudioSetter(){
    ::close(m_timerfd);
}

int AudioSetter::blockAndWaitEvent(){
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

void AudioSetter::toggle(int cmd) {
    if (cmd == happy){
        // m_audio.SetVol(50);
        m_audio.AudioPlay(happy_music);
    } else if (cmd == sad){
        // m_audio.SetVol(50);
        m_audio.AudioPlay(sad_music);
    } else if (cmd == tired){
        // m_audio.SetVol(50);
        m_audio.AudioPlay(tired_music);
    } else if(cmd == 0){
        m_audio.SetVol(0);
    } else{ m_audio.AudioStop();}
}

bool AudioSetter::getState() const {
    return m_isWarning;
}


void AudioSetter::notifyEvent(int val){
    if (val == -1){

    }else{
        pending_.store(val);
        uint64_t one = 1;
        ssize_t s = ::write(m_eventfd, &one, sizeof(one));
        if (s == -1) {
            return;
        }
    }
}