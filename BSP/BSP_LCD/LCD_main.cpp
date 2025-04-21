#include "LCD_class.hpp"
#include "faces.hpp"

void Handler_1IN47_LCD(int signo)
{
	// System Exit
	exit(0);
}

int main(void)
{
    SYS_Config();
    // Exception handling:ctrl + c
    signal(SIGINT, Handler_1IN47_LCD);

    LCD_class LCD_1in14(LCD_1IN47_HEIGHT, LCD_1IN47_WIDTH, HORIZONTAL);

    LCD_1in14.LCD_DisplayImage(angry_face);
    sleep(3);
    LCD_1in14.LCD_DisplayImage(think_face);
    sleep(3);
    LCD_1in14.LCD_DisplayImage(sleep_face);
    sleep(3);
    LCD_1in14.LCD_DisplayImage(normal_face);
    sleep(3);
    LCD_1in14.LCD_DisplayImage(happy_face);
    sleep(3);
    LCD_1in14.LCD_DisplayImage(sad_face);

    sleep(5);
    DEV_Exit();

    return 0;
}