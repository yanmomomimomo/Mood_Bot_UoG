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
    // ��ȡ��ť״̬
    if (digitalRead(KEY_PIN) == LOW) { // ���£��͵�ƽ��
        return KEY_ON;
    }
    else { // �ɿ����ߵ�ƽ��
        return KEY_OFF;
    }
}

/*********************************** END **********************************/