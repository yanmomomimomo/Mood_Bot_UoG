#include "LCD_class.hpp"
#include "../../lib/Face/faces.hpp"

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

    // LCD_1in14.LCD_DrawPixel(50, 80, 0xF800);  // 点亮左上角一个红色像素
    // for (int x = 0; x < 10; x++) {
    //     LCD_1in14.LCD_DrawPixel(x, 0, 0xF800);  // 应出现红色横线
    // }
    // LCD_1in14.Test_FillScreen(0xF800);  // 红
    // sleep(1);
    // LCD_1in14.Test_FillScreen(0x07E0);  // 绿
    // sleep(1);
    // LCD_1in14.Test_FillScreen(0x001F);  // 蓝
    // sleep(1);
    // LCD_1in14.Test_FillScreen(0x0000);  // 黑
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