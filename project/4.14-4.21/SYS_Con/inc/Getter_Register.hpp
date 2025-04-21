#ifndef __GETTER_REGISTER_HPP
#define __GETTER_REGISTER_HPP

#include "EventDriven_class.hpp"
#include "Key_class.hpp"
#include "QM2_class.hpp"
#include "DHT11_class.hpp"
#include "5516_class.hpp"
#include "Rd-03_class.hpp"
#include "EventBus.hpp"
#include <string>

class DHT11_class;
class RD_class;
class S5516_class;
class QM2_class;        
class EventBus;

class KeyGetter : public GetterEventDriven {
public:
    KeyGetter(Key_class &key, EventBus &bus, const std::string &topic);
    virtual ~KeyGetter();
protected:
    virtual int blockAndWaitEvent() override;
    virtual void notifyStop(int val) override;
    
private:
    Key_class &m_key;
    EventBus   &m_bus;
    std::string m_topic;
};

class QM2Getter : public GetterEventDriven {
    public:
        QM2Getter(QM2_class &qm2, EventBus &bus, const std::string &topic);
        virtual ~QM2Getter();
        
        void startWatcher();
        void stopWatcher();
        
    protected:
        virtual int blockAndWaitEvent() override;
        virtual void notifyStop(int val) override;
        
    private:
        std::thread m_watchThread;
        std::atomic<bool> m_watchRunning{false};
        QM2_class &m_qm2;
        EventBus   &m_bus;
        std::string m_topic;
        int m_efd;
};

class DHTGetter : public GetterEventDriven {
    public:
        DHTGetter(DHT11_class &dht, EventBus &bus, const std::string &topic);
        virtual ~DHTGetter(){};
        
        void startWatcher();
        void stopWatcher();
        
    protected:
        virtual int blockAndWaitEvent() override;
        virtual void notifyStop(int val) override;
        
    private:
        DHT11_class    &m_dht;
        EventBus       &m_bus;
        std::string     m_topic;
        int             m_efd = eventfd(0, 0);
        std::thread     m_watchThread;
        std::atomic<bool> m_watchRunning{false};
};

class S5516Getter : public GetterEventDriven {
    public:
        S5516Getter(S5516_class &S5516, EventBus &bus, const std::string &topic);
        virtual ~S5516Getter();
        
        void startWatcher();
        void stopWatcher();
        
    protected:
        virtual int blockAndWaitEvent() override;
        virtual void notifyStop(int val) override;
        
    private:
        std::thread m_watchThread;
        std::atomic<bool> m_watchRunning{false};
        S5516_class &m_5516;
        EventBus   &m_bus;
        std::string m_topic;
        int m_efd;
};

class RDGetter : public GetterEventDriven {
    public:
        RDGetter(RD_class &RD, EventBus &bus, const std::string &topic);
        virtual ~RDGetter();
        
        void startWatcher();
        void stopWatcher();
        
    protected:
        virtual int blockAndWaitEvent() override;
        virtual void notifyStop(int val) override;
        
    private:
        std::thread         m_watchThread;
        std::atomic<bool>   m_watchRunning{false};
        RD_class            &m_RD;
        EventBus            &m_bus;
        std::string         m_topic;
        int                 m_efd;
};
#endif  // __GETTER_REGISTER_HPP