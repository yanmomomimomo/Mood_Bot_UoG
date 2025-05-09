#include "Getter_Register.hpp"

GetterEventDriven::GetterEventDriven() : m_callback(nullptr), m_running(false){}
GetterEventDriven::~GetterEventDriven(){
    stop();
}

void GetterEventDriven::registerCallback(Callback cb) {
    m_callback = cb;
}

void GetterEventDriven::run(){
    // std::cout<<"[Thread " << std::this_thread::get_id() << "] running loop start"<<std::endl;
    while (m_running.load()) {

        int code = blockAndWaitEvent();
        if (code <= 0) continue;     
        if (m_callback) m_callback(code);
    }
}

void GetterEventDriven::start() {
    // std::cout << "[SetterEventDriven] start() called, m_running=" 
    //           << m_running.load() << std::endl;
    if (m_running.load()) return;
    m_running.store(true);
    m_thread = std::thread(&GetterEventDriven::run, this);
    // std::cout << "[SetterEventDriven] thread spawned, id=" 
    //           << m_thread.get_id() << std::endl;
  }

void GetterEventDriven::stop() {
    m_running.store(false);
    if (m_thread.joinable()) m_thread.join();
  }
