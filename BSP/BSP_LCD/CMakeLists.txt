cmake_minimum_required(VERSION 3.1.0)
project(LCD_EG)
set(CMAKE_CXX_STANDARD 14)

# find_package()
set(FACES ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/Face)
set(FONTS ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/Fonts)
set(LED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LED)
set(KEYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_KEYS)
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SYS_DIR})

# Fonts
set(FONTS_FILES
    ${FONTS}/font12.c
    ${FONTS}/font16.c
)
# Faces
set(FACES_FILES
    ${FACES}/angry_face.cpp
    ${FACES}/think_face.cpp
    ${FACES}/sleep_face.cpp
    ${FACES}/normal_face.cpp
    ${FACES}/happy_face.cpp
    ${FACES}/sad_face.cpp
)
# LED
set(LED_FILES
    ${LED_DIR}/Led.cpp
)
# KEY
set(KEY_FILES
    ${KEYS_DIR}/Keys.cpp

)
# LCD
set(LCD_FILES
    LCD_Config.cpp
    LCD.cpp
    LCD_main.cpp
)
# System
set(SYS_FILES
    ${SYS_DIR}/Sys_Functions.cpp
    ${SYS_DIR}/Setter_EventDriven.cpp
    ${SYS_DIR}/I2C_Command.cpp
    ${SYS_DIR}/SPI_Command.cpp
)

add_executable(LCD_EG 
  ${KEY_FILES}
  ${LCD_FILES}
  ${LED_FILES}
  ${SYS_FILES}
  ${FONTS_FILES}
  ${FACES_FILES}
)

target_link_libraries(LCD_EG gpiod)
