/************************* Functions of Key *************************/
// Header Declaration
#include "Key.h"

// Functions
void Key_Config()
{
	pinMode(KEY1_PIN, INPUT);
	pullUpDnControl(KEY1_PIN, PUD_UP);
    pinMode(KEY2_PIN, INPUT);
    pullUpDnControl(KEY2_PIN, PUD_UP);
}

uint8_t Key_Press_Mode1(int KEY_PIN) {
    // 读取按钮状态
    if (digitalRead(KEY_PIN) == LOW) { // 按下（低电平）
        return KEY_ON;
    }
    else { // 松开（高电平）
        return KEY_OFF;
    }
}

/*********************************** END **********************************/