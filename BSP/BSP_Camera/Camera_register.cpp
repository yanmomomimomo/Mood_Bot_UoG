#include "Getter_Register.hpp"

CameraGetter::CameraGetter(Camera_class &camera, EventBus &bus, const std::string &topic)
      : m_camera(camera), m_bus(bus), m_topic(topic)
    {
        m_efd = eventfd(0, 0); 
        if (m_efd < 0) {
        }
        registerCallback([this](int event){
            m_bus.publish(m_topic, event);
        });
    }

int CameraGetter::blockAndWaitEvent(){
        uint64_t v = 0;
        ssize_t n = ::read(m_efd, &v, sizeof(v));
        if (n != sizeof(v)) return -1;
        return static_cast<int>(v);
    }

void CameraGetter::notifyStop(int /*unused*/){
        uint64_t one = 1;
        ::write(m_efd, &one, sizeof(one));
    }

void CameraGetter::startWatcher() {
        m_watchRunning.store(true);
        m_watchThread = std::thread([this](){
            while (m_watchRunning.load()) {
                m_camera.Collect();
                int value = m_camera.ImageAnalysis();
                std::cout<<value<<std::endl;
                if (value >= 0) {
                    uint64_t v = static_cast<uint64_t>(value);
                    ::write(m_efd, &v, sizeof(v));
                }
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
        });
    }

void CameraGetter::stopWatcher() {
        m_watchRunning.store(false);
        if (m_watchThread.joinable()) m_watchThread.join();
    }
