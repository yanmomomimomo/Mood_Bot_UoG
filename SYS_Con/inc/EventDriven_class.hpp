#ifndef __EVENTDRIVEN_CLASS_HPP
#define __EVENTDRIVEN_CLASS_HPP

#include <functional>
#include <unistd.h>
#include <sys/timerfd.h>
#include <cstring>
#include <iostream>
#include <atomic>
#include <thread>

#include <sys/eventfd.h>
#include <stdint.h>

class SetterEventDriven {
public:
    using Callback = std::function<void(int)>;
    
    SetterEventDriven();
    virtual ~SetterEventDriven();
    
    void registerCallback(Callback cb);
    void run();
    void stop();
    void start();
    
protected:

    virtual int blockAndWaitEvent() = 0;
    virtual void toggle(int cmd) = 0;
    virtual bool getState() const = 0;

    virtual void notifyStop(const int val) ;
    
private:
    std::thread         m_thread;
    std::atomic<bool>   m_running;
    std::atomic<int>   m_cmd;
    Callback            m_callback;
};

class GetterEventDriven {
    public:
        using Callback = std::function<void(int)>;
        
        GetterEventDriven();
        virtual ~GetterEventDriven();
        
        void registerCallback(Callback cb);
        void run();
        void stop();
        void start();

    protected:
        virtual int blockAndWaitEvent() = 0;
        virtual void notifyStop(const int val)  = 0;
        
    private:
        Callback            m_callback;
        std::thread         m_thread;
        std::atomic<bool>   m_running;
    };

class EventNotifier {
    public:
        virtual ~EventNotifier() = default;
        virtual int getEventFd() const = 0;
    };

#endif // __EVENTDRIVEN_CLASS_HPP