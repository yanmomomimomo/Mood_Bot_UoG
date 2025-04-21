#include "SYS.hpp"

std::atomic<bool> keepRunning{true};
void sigint_handler(int) {
    keepRunning.store(false);
}

int main(){
    SYS_Config();

    try {

        // Setter init
        OLED_class OLED;
        OLEDSetter oledSetter(OLED, 5);
        LCD_class LCD_1in14(LCD_1IN47_HEIGHT, LCD_1IN47_WIDTH, HORIZONTAL);
        LCDSetter lcdSetter(LCD_1in14, 10);
        Servo_class Ser1(GPIO_Servo1, SER1_CONSUMER, SER1_UANGLE, SER1_COUNT);
        SERSetter Ser1_S(Ser1, 10);
        ServoPRO_class Ser2(GPIO_Servo2, SER2_CONSUMER);
        SERPSetter Ser2_S(Ser2, 10);
        PWM_class PWM1(PWMGROUP1);
        PWMSetter PWM1_S(PWM1, 10);
        PWM_class PWM2(PWMGROUP2);
        PWMSetter PWM2_S(PWM2, 10);
        Audio_class Audio(50);
        AudioSetter Audio_S(Audio, 10);
        
        // Getter init
        Key_class key1(GPIO_KEY2, CONSUMER_KEY2);
        QM2_class QM2(GPIO_QM2, QM2_CONSUMER);
        DHT11_class DHT(DHT_GPIO, DHT_CONSUME);
        S5516_class S5516(GPIO_5516, CONSUMER_5516);
        RD_class RD_03(RD_GPIO, RD_CONSUMER);
        Camera_class Camera(1);

        // Bus init
        EventBus BUS;

        // Event subscribe
        BUS.subscribe("QM", [&](int val){ 
            oledSetter.notifyEvent(OLED_WARNING); 
            lcdSetter.notifyEvent(sad);
        });
        
        BUS.subscribe("DHT", [&](int value){
            oledSetter.notifyEvent(value);
          });

        BUS.subscribe("5516", [&](int val){ 
            lcdSetter.notifyEvent(sleeping);
        });

        BUS.subscribe("RD", [&](int val){ 
            lcdSetter.notifyEvent(sleeping);
        });

        BUS.subscribe("Key", [&](int val){ 
            Audio_S.notifyEvent(0);
            PWM1_S.notifyEvent(Clockwise);
            PWM2_S.notifyEvent(Clockwise);
        });

        BUS.subscribe("camera", [&](int val){ 
            // std::cout<<val<<std::endl;
            Ser1_S.notifyEvent((val) % 10);
            Ser2_S.notifyEvent((val / 10) % 10);
            lcdSetter.notifyEvent((val / 100) % 10);
            Audio_S.notifyEvent((val / 100) % 10);
            PWM1_S.notifyEvent((val / 100) % 10);
            PWM2_S.notifyEvent((val / 100) % 10);
        });

        // Getter register
        CameraGetter Camera_G(Camera, BUS, "camera");
        QM2Getter QM2_G(QM2, BUS, "QM");
        DHTGetter DHT_G(DHT, BUS, "DHT");
        S5516Getter S5516_G(S5516, BUS, "5516");
        RDGetter RD_G(RD_03, BUS, "RD");
        KeyGetter Key_G(key1, BUS, "Key");
        
        // start();
        lcdSetter.start();
        oledSetter.start();
        Ser1_S.start();
        Ser2_S.start();
        PWM1_S.start();
        PWM2_S.start();
        Audio_S.start();

        QM2_G.start();
        QM2_G.startWatcher(); 
        DHT_G.start();
        DHT_G.startWatcher();
        S5516_G.start();
        S5516_G.startWatcher();
        RD_G.start();
        RD_G.startWatcher();
        Key_G.start();
        Camera_G.start();
        Camera_G.startWatcher();

        while (keepRunning.load()) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        gpiod_chip_close(chip0);
        return 1;
    }
    
    gpiod_chip_close(chip0);
    
    return 1;
}