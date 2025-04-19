/************************* Functions of MotorDrive *************************/
// Header Declaration
#include "MotorDrive.h"

// MotorDrive_Config
void MotorDrive_Config(int dutyCycle = 512)
{
    pinMode(PWM_PIN, PWM_OUTPUT); // 设置引脚为 PWM 输出模式
    pwmSetMode(PWM_MODE_MS); // 选择标记空间 (Mark-Space) 模式
    pwmSetRange(PWM_RANGE); // 设置 PWM 范围
    pwmSetClock(384); // 设置 PWM 时钟分频系数（影响 PWM 频率）
    
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