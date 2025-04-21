#ifndef __SETTER_REGISTER_HPP
#define __SETTER_REGISTER_HPP

#include "EventDriven_class.hpp"
#include "Led_class.hpp"
#include "OLED_class.hpp"
#include "LCD_class.hpp"
#include "Servo_class.hpp"
#include "pwm_class.hpp"
#include "Audio_class.hpp"
// #include "EventBus.hpp"

#include <sys/timerfd.h>
#include <poll.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <functional>

class Servo_class;
class ServoPRO_class;
class LCD_class;
class OLED_class;
class LED_class;
class PWM_class;
class Audio_class;


// LED Register
class LEDSetter : public SetterEventDriven{
public:
    LEDSetter(LED_class &led);
    virtual ~LEDSetter();

    void notifyEvent(int val);
protected:
    virtual int blockAndWaitEvent() override;
    virtual void toggle(int cmd) override;
    virtual bool getState() const override;
    
private:
    LED_class &m_led;
    int m_efd;
    std::atomic<int> pending_ {0};
};

// OLED register
class OLEDSetter : public SetterEventDriven {
    public:
        OLEDSetter(OLED_class &oled, int periodSec = 5);
        ~OLEDSetter() override;
        void notifyEvent(int val);
    protected:
        virtual int blockAndWaitEvent() override;
        virtual void toggle(int cmd) override;
        virtual bool getState() const override;

    private:
        OLED_class &m_oled;
        int         m_timerfd;
        bool        m_isWarning;
        std::atomic<int> pending_ {0};
        int         m_eventfd;
    };

    // OLCD register
class LCDSetter : public SetterEventDriven {
    public:
        LCDSetter(LCD_class &lcd, int periodSec = 10);
        ~LCDSetter() override;

        void notifyEvent(int val);
    protected:
        virtual int blockAndWaitEvent() override;
        virtual void toggle(int cmd) override;
        virtual bool getState() const override;

    private:
        LCD_class &m_lcd;
        int         m_timerfd;
        bool        m_isWarning;
        std::atomic<int> pending_ {0};
        int         m_eventfd;
};

// Servo register
class SERSetter : public SetterEventDriven {
    public:
        SERSetter(Servo_class &ser, int periodSec = 10);
        ~SERSetter() override;

        void notifyEvent(int val);
    protected:
        virtual int blockAndWaitEvent() override;
        virtual void toggle(int cmd) override;
        virtual bool getState() const override;

    private:
        Servo_class &m_ser;
        int         m_timerfd;
        bool        m_isWarning;
        std::atomic<int> pending_ {0};
        int         m_eventfd;
};

// Servo Pro register
class SERPSetter : public SetterEventDriven {
    public:
        SERPSetter(ServoPRO_class &serp, int periodSec = 10);
        ~SERPSetter() override;

        void notifyEvent(int val);
    protected:
        virtual int blockAndWaitEvent() override;
        virtual void toggle(int cmd) override;
        virtual bool getState() const override;

    private:
        ServoPRO_class &m_ser;
        int         m_timerfd;
        bool        m_isWarning;
        std::atomic<int> pending_ {0};
        int         m_eventfd;
};

// PWM register
class PWMSetter : public SetterEventDriven {
    public:
        PWMSetter(PWM_class &pwm, int periodSec);
        ~PWMSetter() override;

        void notifyEvent(int val);
    protected:
        virtual int blockAndWaitEvent() override;
        virtual void toggle(int cmd) override;
        virtual bool getState() const override;

    private:
        PWM_class &m_pwm;
        int         m_timerfd;
        bool        m_isWarning;
        std::atomic<int> pending_ {0};
        int         m_eventfd;
};

// Audio register
class AudioSetter : public SetterEventDriven {
    public:
        AudioSetter(Audio_class &audio, int periodSec = 10);
        ~AudioSetter() override;

        void notifyEvent(int val);
    protected:
        virtual int blockAndWaitEvent() override;
        virtual void toggle(int cmd) override;
        virtual bool getState() const override;

    private:
        Audio_class &m_audio;
        int         m_timerfd;
        bool        m_isWarning;
        std::atomic<int> pending_ {0};
        int         m_eventfd;
};
#endif //__SETTER_REGISTER_HPP