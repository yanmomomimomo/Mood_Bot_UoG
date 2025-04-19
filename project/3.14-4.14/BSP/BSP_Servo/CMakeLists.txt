cmake_minimum_required(VERSION 3.1.0)
project(SER_EG)
set(CMAKE_CXX_STANDARD 14)

# find_package()
set(LED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LED)
set(KEY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_KEYS)
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con)
set(PWM_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_PWM)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SYS_DIR})

# LED
set(LED_FILES
    ${LED_DIR}/Led.cpp
)
#KEY
set(KEY_FILES
    ${KEY_DIR}/Keys.cpp
)
# PWM
set(PWM_FILES
    ${PWM_DIR}/gpio_pwm.cpp
)
# SERVO
set(SER_FILES
    Servo.cpp
    Servo_main.cpp
)
# System
set(SYS_FILES
    ${SYS_DIR}/Sys_Functions.cpp
    ${SYS_DIR}/EventDriven.cpp
    ${SYS_DIR}/Setter_EventDriven.cpp
)

# 添加可执行文件
add_executable(SER_EG 
  ${KEY_FILES}
  ${LED_FILES}
  ${PWM_FILES}
  ${SYS_FILES}
  ${SER_FILES}
)

target_link_libraries(SER_EG gpiod)
