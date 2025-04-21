#ifndef __RD_03_CLASS_HPP
#define __RD_03_CLASS_HPP

#include "Rd-03.hpp"

class RD_class{
    public:
        RD_class(uint8_t offset, const std::string &consumer);
        ~RD_class();
        
        int GetValue();
    
    private:
        gpiod_chip* chip_ {chip0};      
        gpiod_line* line_ {nullptr};      
        uint8_t offset_ {0};           
        std::string consumer_ {nullptr};  
        uint16_t min_dist_cm {50}; 
        uint16_t max_dist_cm {300}; 
        uint16_t delay_s     {5};    
    };

#endif // __RD_03_CLASS_HPP
