#include "OLED.hpp"

extern int i2c_fd;

class OLED_class{
    public:
        OLED_class();
        ~OLED_class();

        bool Border_Show();
        bool Word_Show();
        bool Warning_Show();
    private:
        const char* devName_ {nullptr};
        int i2c_fd_ {i2c_fd};

};