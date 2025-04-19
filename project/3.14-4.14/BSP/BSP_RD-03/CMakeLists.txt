cmake_minimum_required(VERSION 3.1.0)
project(RD_EG)
set(CMAKE_CXX_STANDARD 14)

# find_package()
set(LCD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LCD)
set(FONTS ${CMAKE_CURRENT_SOURCE_DIR}/../Fonts)
set(LED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LED)
set(KEYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_KEYS)
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SYS_DIR})

# Fonts
set(FONTS_FILES
    ${FONTS}/font12.c
    ${FONTS}/font16.c
)
# LED
set(LED_FILES
    ${LED_DIR}/Led.cpp
)
# KEY
set(KEY_FILES
    ${KEYS_DIR}/Keys.cpp
)
# RD-03
set(RD_FILES
    Rd-03.cpp
    Rd-03_main.cpp
)
# LCD
set(LCD_FILES
    ${LCD_DIR}/LCD_Config.cpp
    ${LCD_DIR}/LCD.cpp
)
# System
set(SYS_FILES
    ${SYS_DIR}/Sys_Functions.cpp
    ${SYS_DIR}/EventDriven.cpp
    ${SYS_DIR}/Setter_EventDriven.cpp
    ${SYS_DIR}/I2C_Command.cpp
    ${SYS_DIR}/SPI_Command.cpp
)

# 添加可执行文件
add_executable(RD_EG 
  ${KEY_FILES}
  ${LCD_FILES}
  ${LED_FILES}
  ${SYS_FILES}
  ${FONTS_FILES}
  ${RD_FILES}
)

target_link_libraries(RD_EG gpiod)
