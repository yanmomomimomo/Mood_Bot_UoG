#ifndef __5516_CLASS_HPP
#define __5516_CLASS_HPP

#include "5516.hpp"

class S5516_class{
    public:
        S5516_class(uint8_t offset, const std::string &consumer);
        ~S5516_class();
        
        int GetValue();
    
    private:
        gpiod_chip* chip_ {chip0};      
        gpiod_line* line_ {nullptr};      
        uint8_t offset_ {0};           
        std::string consumer_ {nullptr};  
    };

#endif // __5516_CLASS_HPP