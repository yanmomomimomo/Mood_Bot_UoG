cmake_minimum_required(VERSION 3.1.0)
project(QM2_EG)
set(CMAKE_CXX_STANDARD 17)

# find_package()
set(KEY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_KEYS)
set(LED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LED)
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${LED_DIR})
include_directories(${KEY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../BSP_OLED)

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
# QM2
set(QM2_FILES
    QM2.cpp
    QM2_main.cpp
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

add_executable(QM2_EG 
  ${KEY_FILES}
  ${LED_FILES}
  ${SYS_FILES}
  ${QM2_FILES}
)

target_link_libraries(QM2_EG gpiod)
