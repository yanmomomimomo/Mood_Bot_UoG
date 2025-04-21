cmake_minimum_required(VERSION 3.1.0)
project(PWM_EG)
set(CMAKE_CXX_STANDARD 14)

# find_package()
set(LED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LED)
set(KEY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_KEYS)
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con/src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SYS_DIR})

# LED
set(LED_FILES
    ${LED_DIR}/Led.cpp
)
#KEY
set(KEY_FILES
    ${KEY_DIR}/Keys.cpp
)
#KEY
set(PWM_FILES
    gpio_pwm.cpp
)
# System
set(SYS_FILES
    ${SYS_DIR}/Sys_Functions.cpp
    ${SYS_DIR}/EventDriven.cpp
    ${SYS_DIR}/Setter_EventDriven.cpp
)

add_executable(PWM_EG 
  ${KEY_FILES}
  ${LED_FILES}
  ${PWM_FILES}
  ${SYS_FILES}
  pwm_main.cpp
)

target_link_libraries(PWM_EG gpiod)
