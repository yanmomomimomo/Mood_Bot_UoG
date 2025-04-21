cmake_minimum_required(VERSION 3.1.0)
project(MAIN)
set(CMAKE_CXX_STANDARD 17)

# find_package()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SYS_Con/inc)

set(PWM_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/BSP/BSP_PWM)
set(SER_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/BSP/BSP_Servo)
set(LED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/BSP/BSP_LED)
set(QM2_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/BSP/BSP_QM2)
set(5516_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/BSP/BSP_5516)
set(AUD_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/BSP/BSP_Audio)
set(KEY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/BSP/BSP_KEYS)
set(DHT_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/BSP/BSP_DHT11)
set(LCD_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/BSP/BSP_LCD)
set(OLED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/BSP/BSP_OLED)
set(RD_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/BSP/BSP_RD-03)
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/SYS_Con/src)
include_directories(${PWM_DIR})
include_directories(${SER_DIR})
include_directories(${5516_DIR})
include_directories(${AUD_DIR})
include_directories(${KEY_DIR})
include_directories(${DHT_DIR})
include_directories(${LCD_DIR})
include_directories(${OLED_DIR})
include_directories(${RD_DIR})
include_directories(${LED_DIR})
include_directories(${QM2_DIR})

set(Face_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/lib/Face)
set(Fonts_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/lib/Fonts)
set(MH_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/lib/music/happy)
set(MT_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/lib/music/tired)
set(MS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/lib/music/sad)
include_directories(${Face_DIR})
include_directories(${Fonts_DIR})
include_directories(${MH_DIR})
include_directories(${MT_DIR})
include_directories(${MS_DIR})

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)

# Fonts
set(FONTS_FILES
    ${Fonts_DIR}/font12.c
    ${Fonts_DIR}/font16.c
)
# LED
set(LED_FILES
    ${LED_DIR}/Led.cpp
    ${LED_DIR}/Led_register.cpp
)
# PWM
set(PWM_FILES
    ${PWM_DIR}/gpio_pwm.cpp
    ${PWM_DIR}/pwm_register.cpp
)
# Audio
set(AUD_FILES
    ${AUD_DIR}/Audio.cpp
    ${AUD_DIR}/Audio_register.cpp
)
# Servo
set(SER_FILES
    ${SER_DIR}/Servo_register.cpp
    ${SER_DIR}/Servo.cpp
    ${SER_DIR}/ServoPro_register.cpp
    ${SER_DIR}/ServoPro.cpp
)
# KEY
set(KEY_FILES
    ${KEY_DIR}/Keys.cpp
    ${KEY_DIR}/Key_register.cpp
)
# DHT11
set(DHT_FILES
    ${DHT_DIR}/DHT11.cpp
    ${DHT_DIR}/DHT11_register.cpp
)
# QM2
set(QM2_FILES
    ${QM2_DIR}/QM2.cpp
    ${QM2_DIR}/QM2_register.cpp
)
# RD
set(RD_FILES
    ${RD_DIR}/Rd-03_register.cpp
    ${RD_DIR}/Rd-03.cpp
)
# 5516
set(5516_FILES
    ${5516_DIR}/5516.cpp
    ${5516_DIR}/5516_register.cpp
)
# OLED
set(OLED_FILES
    ${OLED_DIR}/OLED_Config.cpp
    ${OLED_DIR}/OLED_register.cpp
    ${OLED_DIR}/OLED.cpp
    ${OLED_DIR}/Frame.cpp
)
# LCD
set(LCD_FILES
    ${LCD_DIR}/LCD_Config.cpp
    ${LCD_DIR}/LCD_register.cpp
    ${LCD_DIR}/LCD.cpp
)
# System
set(SYS_FILES
    ${SYS_DIR}/Sys_Functions.cpp
    ${SYS_DIR}/EventBus.cpp
    ${SYS_DIR}/Setter_EventDriven.cpp
    ${SYS_DIR}/Getter_EventDriven.cpp
    ${SYS_DIR}/I2C_Command.cpp
    ${SYS_DIR}/SPI_Command.cpp
)
# Faces
set(Faces_FILES
    ${Face_DIR}/angry_face.cpp
    ${Face_DIR}/happy_face.cpp
    ${Face_DIR}/normal_face.cpp
    ${Face_DIR}/sad_face.cpp
    ${Face_DIR}/think_face.cpp
    ${Face_DIR}/sleep_face.cpp
)

add_executable(MAIN 
    ${PWM_FILES}
    ${AUD_FILES}
    ${5516_FILES}
    ${SER_FILES}
    ${FONTS_FILES}
    ${Faces_FILES}
    ${QM2_FILES}
    ${KEY_FILES}
    ${DHT_FILES}
    ${LED_FILES}
    ${SYS_FILES}
    ${OLED_FILES}
    ${LCD_FILES}
    ${RD_FILES}
    main.cpp
)

include_directories(${ALSA_INCLUDE_DIRS})
link_directories(${ALSA_LIBRARY_DIRS})
target_link_libraries(MAIN     
    ${SDL2_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    gpiod)
