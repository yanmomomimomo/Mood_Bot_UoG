#include "Setter_Register.hpp"

SetterEventDriven::SetterEventDriven() : m_callback(nullptr), m_running(false), m_cmd(0){}

SetterEventDriven::~SetterEventDriven(){
    stop();
}

void SetterEventDriven::registerCallback(Callback cb) {
    m_callback = cb;
}

void SetterEventDriven::run(){
    // std::cout<<"[Thread " << std::this_thread::get_id() << "] running loop start"<<std::endl;
    while (m_running.load()) {
        m_cmd.store(blockAndWaitEvent());
        if ( !m_cmd.load() ){
            continue;
        }
        // bool state = getState();
        if(m_callback) {
            m_callback(m_cmd);
        }
    }
}

void SetterEventDriven::start() {
    // std::cout << "[SetterEventDriven] start() called, m_running=" 
            //   << m_running.load() << std::endl;
    if (m_running.load()) return;
    m_running.store(true);
    m_thread = std::thread(&SetterEventDriven::run, this);
    // std::cout << "[SetterEventDriven] thread spawned, id=" 
    //           << m_thread.get_id() << std::endl;
  }

void SetterEventDriven::stop() {
    m_running.store(false);
    notifyStop(-1);
   if (m_thread.joinable()) {
        m_thread.join();
    }
}

void SetterEventDriven::notifyStop(const int val) {};
