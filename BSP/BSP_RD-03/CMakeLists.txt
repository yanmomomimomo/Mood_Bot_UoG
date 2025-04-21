cmake_minimum_required(VERSION 3.1.0)
project(RD_EG)
set(CMAKE_CXX_STANDARD 14)

# find_package()
# find_package()
set(DHT_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_DHT11)
set(5516_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_5516)
set(LCD_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LCD)
set(KEY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_KEYS)
set(LED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LED)
set(QM2_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_QM2)
set(FAC_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/Face)
set(FONTS  ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/Fonts)
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SYS_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${LED_DIR})
include_directories(${KEY_DIR})
include_directories(${LCD_DIR})
include_directories(${DHT_DIR})
include_directories(${FAC_DIR})
include_directories(${5516_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../BSP_OLED)
include_directories(${QM2_DIR})

# Fonts
set(FONTS_FILES
    ${FONTS}/font12.c
    ${FONTS}/font16.c
)

# RD-03
set(RD_FILES
    Rd-03.cpp
    Rd-03_register.cpp
    Rd-03_main.cpp
)
# LCD
set(LCD_FILES
    ${LCD_DIR}/LCD_Config.cpp
    ${LCD_DIR}/LCD.cpp
)
# LED
set(LED_FILES
    ${LED_DIR}/Led.cpp
    ${LED_DIR}/Led_register.cpp
)
#KEY
set(KEY_FILES
    ${KEY_DIR}/Keys.cpp
    ${KEY_DIR}/Key_register.cpp
)
# 5516
set(5516_FILES
    ${5516_DIR}/5516.cpp
    ${5516_DIR}/5516_register.cpp
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

add_executable(RD_EG 
  ${KEY_FILES}
  ${LCD_FILES}
  ${LED_FILES}
  ${SYS_FILES}
  ${5516_FILES}
  ${FONTS_FILES}
  ${RD_FILES}
)

target_link_libraries(RD_EG gpiod)
