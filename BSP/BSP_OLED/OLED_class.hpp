#ifndef __OLED_CLASS_HPP
#define __OLED_CLASS_HPP

#include "OLED.hpp"

extern int i2c_fd;

class OLED_class{
    public:
        OLED_class();
        ~OLED_class();

        bool Border_Show();
        bool Word_Show();
        bool Warning_Show();
        bool Date_upgrade();
        bool TM_upgrade(int TM);

        void OLED_Shootdown();
    private:
        const char* devName_ {nullptr};
        int i2c_fd_ {i2c_fd};

};

#endif // __OLED