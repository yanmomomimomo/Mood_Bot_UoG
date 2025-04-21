#include "Rd-03_class.hpp"
#include "SYS.hpp"

 int main(void) {
    SYS_Config();
    RD_class RD(RD_GPIO, RD_CONSUMER);
     
    while (1) {
        RD.GetValue();
        sleep(1);
    }

    return 0;
 }
 