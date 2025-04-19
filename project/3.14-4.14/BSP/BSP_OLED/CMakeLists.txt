cmake_minimum_required(VERSION 3.1.0)
project(OLED_EG)
set(CMAKE_CXX_STANDARD 14)

# find_package()
set(FONT_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../Fonts)
set(LED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LED)
set(KEYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_KEYS)
set(LCD_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LCD)
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SYS_DIR})

# LED
set(LED_FILES
    ${LED_DIR}/Led.cpp
)
# KEY
set(KEY_FILES
    ${KEYS_DIR}/Keys.cpp

)
# # LCD
# set(LCD_FILES
#     ${LCD_DIR}/LCD.cpp
# )
# OLED
set(OLED_FILES
    Frame.cpp
    OLED.cpp
    OLED_main.cpp
    OLED_Config.cpp
)
# System
set(SYS_FILES
    ${SYS_DIR}/Sys_Functions.cpp
    ${SYS_DIR}/Setter_EventDriven.cpp
    ${SYS_DIR}/I2C_Command.cpp
)
# Fonts_FILES
set(Fonts_FILES
    ${FONT_DIR}/font12.c
    ${FONT_DIR}/font16.c
)

# 添加可执行文件
add_executable(OLED_EG 
    ${Fonts_FILES}
    ${KEY_FILES}
    ${LCD_FILES}
    ${LED_FILES}
    ${SYS_FILES}
    ${OLED_FILES}
)

target_link_libraries(OLED_EG gpiod)
