#include "DHT11_class.hpp"

static volatile int keep_running = 1;
static void int_handler(int signo) {
    (void)signo;
    keep_running = 0;
}


int main(void) {
    signal(SIGINT, int_handler);

    SYS_Config();
    DHT11_class DHT11(DHT_GPIO, DHT_CONSUME);
    
    while (keep_running) {
        int value = DHT11.MT_check();
        if (value != -1) {
            // 打印带一位小数
            std::cout<<value<<std::endl;
        } else {
            fprintf(stderr, "读取失败\n");
        }
        sleep(2);
    }
    gpiod_chip_close(chip0);
    printf("程序已退出\n");
    return 0;
}
