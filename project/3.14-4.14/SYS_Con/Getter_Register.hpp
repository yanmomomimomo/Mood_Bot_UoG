#ifndef __GETTER_REGISTER_HPP
#define __GETTER_REGISTER_HPP

#include "EventDriven_class.hpp"
#include "../BSP/BSP_KEYS/Key_class.hpp"

class KeyGetter : public GetterEventDriven {
public:
    KeyGetter(Key_class &key, EventNotifier &notifier);
    virtual ~KeyGetter();
protected:
    // 阻塞后，返回 g_ledTrigger 的状态
    virtual bool blockAndWaitEvent() override;
    
private:
    Key_class &m_key;
    EventNotifier &m_notifier;
};

#endif  // __GETTER_REGISTER_HPP