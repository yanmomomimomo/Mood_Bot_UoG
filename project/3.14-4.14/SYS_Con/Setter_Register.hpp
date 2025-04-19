#ifndef __SETTER_REGISTER_HPP
#define __SETTER_REGISTER_HPP

#include "EventDriven_class.hpp"
#include "../BSP/BSP_LED/Led_class.hpp"

extern std::atomic<bool> g_ledTrigger;

class LEDSetter : public SetterEventDriven, public EventNotifier {
public:
    LEDSetter(LED_class &led);
    virtual ~LEDSetter();

    int getEventFd() const override;
    void notifyEvent();
protected:
    // 阻塞等待函数：使用 timerfd 阻塞
    // 阻塞后，返回 g_ledTrigger 的状态
    virtual bool blockAndWaitEvent() override;
    virtual void toggle() override;
    virtual bool getState() const override;
    
private:
    LED_class &m_led;
    int m_efd;
};


#endif //__SETTER_REGISTER_HPP