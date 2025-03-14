/************************* Functions of MotorDrive *************************/
// Header Declaration
#include "MotorDrive.h"

// MotorDrive_Config
void MotorDrive_Config(int dutyCycle = 512)
{
    pinMode(PWM_PIN, PWM_OUTPUT); // ��������Ϊ PWM ���ģʽ
    pwmSetMode(PWM_MODE_MS); // ѡ���ǿռ� (Mark-Space) ģʽ
    pwmSetRange(PWM_RANGE); // ���� PWM ��Χ
    pwmSetClock(384); // ���� PWM ʱ�ӷ�Ƶϵ����Ӱ�� PWM Ƶ�ʣ�
    
    std::cout << "Please enter dutycycle:";
    std::cin >> dutyCycle;
    if (dutyCycle < 0 || dutyCycle > PWM_RANGE) {
        std::cout << "DutyCycle is invalid input!" << std::endl;
        return;
    }
    pwmWrite(PWM_PIN, dutyCycle);
    std::cout << "DutyCycle: " << dutyCycle << std::endl;
}
/*********************************** END **********************************/