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

// 抽象基类，用于所有 setter 外设的事件驱动封装
class SetterEventDriven {
public:
    using Callback = std::function<void(bool)>;
    
    SetterEventDriven();
    virtual ~SetterEventDriven();
    
    void registerCallback(Callback cb);
    void run();
    void stop();
    void start();
    
protected:
    // 纯虚函数：阻塞等待具体设备事件
    virtual bool blockAndWaitEvent() = 0;
    // 纯虚函数：切换设备状态
    virtual void toggle() = 0;
    // 纯虚函数：获取设备当前状态
    virtual bool getState() const = 0;
    
private:
    std::thread         m_thread;
    std::atomic<bool>   m_running;
    Callback            m_callback;
};

// 抽象基类，用于所有 Getter 外设的事件驱动封装
class GetterEventDriven {
    public:
        using Callback = std::function<void(uint8_t)>;
        
        GetterEventDriven();
        virtual ~GetterEventDriven();
        
        void registerCallback(Callback cb);
        void run();
        void stop();
        void start();
        
    protected:
        // 纯虚函数：阻塞等待具体设备事件
        virtual bool blockAndWaitEvent() = 0;
        
    private:
        Callback            m_callback;
        std::thread         m_thread;
        std::atomic<bool>   m_running;
    };

class EventNotifier {
    public:
        virtual ~EventNotifier() = default;
    
        // 返回用于 write() / read() 的 eventfd 文件描述符
        virtual int getEventFd() const = 0;
    };

#endif // __EVENTDRIVEN_CLASS_HPP