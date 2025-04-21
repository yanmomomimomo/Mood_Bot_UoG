#include "QM2_class.hpp"
#include "SYS.hpp"

static bool keep_running = true;
void sigint_handler(int) { keep_running = false; }

int main()
{
    signal(SIGINT, sigint_handler);

    SYS_Config();
    
    QM2_class QM2_dev(GPIO_QM2, QM2_CONSUMER);

    while (true) {
        QM2_dev.Smoke_check();
    }
    return EXIT_SUCCESS;
}
