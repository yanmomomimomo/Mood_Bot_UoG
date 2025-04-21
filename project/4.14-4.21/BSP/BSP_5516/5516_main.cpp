#include "5516_class.hpp"
static int keep_running = 1;

void sigint_handler(int sig)
{
    keep_running = 0;
}

int main(void)
{
    struct gpiod_chip  *chip;
    struct gpiod_line *line;
    int value;

    signal(SIGINT, sigint_handler);

    SYS_Config();

    S5516_class S5516(GPIO_5516, CONSUMER_5516);


    while (keep_running) {
        S5516.GetValue();
    }

    gpiod_line_release(line);
    gpiod_chip_close(chip);
    return EXIT_SUCCESS;
}
