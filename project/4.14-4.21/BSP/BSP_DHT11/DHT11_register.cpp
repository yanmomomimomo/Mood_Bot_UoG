#include "Getter_Register.hpp"

DHTGetter::DHTGetter(DHT11_class &dht, EventBus &bus, const std::string &topic)
      : m_dht(dht), m_bus(bus), m_topic(topic)
    {
        registerCallback([this](int event){
            m_bus.publish(m_topic, event);
        });
    }

int DHTGetter::blockAndWaitEvent(){
        uint64_t v = 0;
        ssize_t n = ::read(m_efd, &v, sizeof(v));
        if (n != sizeof(v)) return -1;
        return static_cast<int>(v);
    }

void DHTGetter::notifyStop(int /*unused*/){
        uint64_t one = 1;
        ::write(m_efd, &one, sizeof(one));
    }

void DHTGetter::startWatcher() {
        m_watchRunning.store(true);
        m_watchThread = std::thread([this](){
            while (m_watchRunning.load()) {
                int value = m_dht.MT_check();
                if (value >= 0) {
                    uint64_t v = static_cast<uint64_t>(value);
                    ::write(m_efd, &v, sizeof(v));
                }
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
        });
    }

void DHTGetter::stopWatcher() {
        m_watchRunning.store(false);
        if (m_watchThread.joinable()) m_watchThread.join();
    }
