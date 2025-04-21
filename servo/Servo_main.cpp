#include <iostream>
#include <csignal>
#include "Servo.hpp"

Servo_class servo;

void handle_signal(int signal) {
    std::cout << "Caught signal " << signal << ", stopping Servo and cleaning up GPIO." << std::endl;
    servo.release_gpio();  // �ͷ����� GPIO ��Դ
    exit(0);  // �˳�����
}

int main() {
    signal(SIGINT, handle_signal);  // �����ж��ź�
    signal(SIGTERM, handle_signal); // ������ֹ�ź�

    if (!gpio.init()) {  // ��ʼ�� GPIO
        return 1;
    }


    //����˶�����
    servo.Servo_down(Servo1);
    sleep(1);
    servo.Servo_up(Servo1);
    servo.release_gpio();  // �ͷ� GPIO ����

    return 0;
}
