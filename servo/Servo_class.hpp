#ifndef SERVO_CLASS_HPP_INCLUDED
#define SERVO_CLASS_HPP_INCLUDED

#include "Servo.hpp"
#include <gpiod.h>
#include <string>

extern gpiod_chip *chip0;

class Servo_class {
public:
    // ���캯��
    Servo_class(const char* chip_path = GPIO_CHIP);

    // ��������
    ~Servo_class();

    // ��ʼ�� GPIO������ GPIO ���ŵı�ţ������Ƿ�ɹ�
    bool Servo_init();

    // ���� PWM �����ռ�ձ�Ϊ�ٷֱȣ�0-100��
    void set_pwm_output(int pin, int duty_cycle_percent);

    // ֹͣ��� PWM ���

    void Servo_disable(int pin);

    // �ͷ���Դ
    void release_gpio();

    void set_pwm_pulse_ms(int pin, float pulse_ms);
    void Servo_up(int pin);
    void Servo_down(int pin);


private:
    gpiod_chip* chip_;  // GPIO chip ����
    std::mutex pwm_mutex_;  // ���� PWM ������������ֹ��������
    std::map<int, std::thread> pwm_threads_;  // ���ڴ洢ÿ�����ŵ� PWM �߳�
    std::map<int, bool> pwm_running_;  // ��¼ÿ�����ŵ� PWM ״̬

    std::map<int, gpiod_line*> gpio_lines_;  // �洢����� GPIO ����

    // ��ȡ GPIO ���Ŷ���
    gpiod_line* get_gpio_line(int pin);

    // ���õ��� PWM �������
    void set_pwm_for_pin(int pin, int duty_cycle_percent);
};


#endif // SERVO_CLASS_HPP_INCLUDED
