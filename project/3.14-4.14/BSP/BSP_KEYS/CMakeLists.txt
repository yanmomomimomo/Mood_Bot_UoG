cmake_minimum_required(VERSION 3.1.0)
project(KEY_EG)
set(CMAKE_CXX_STANDARD 17)

# find_package()
set(LED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LED)
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SYS_DIR})

# LED
set(LED_FILES
    ${LED_DIR}/Led.cpp
    ${LED_DIR}/Led_register.cpp
)
#KEY
set(KEY_FILES
    Keys.cpp
    Key_register.cpp
)
# System
set(SYS_FILES
    ${SYS_DIR}/Sys_Functions.cpp
    ${SYS_DIR}/EventBus.cpp
    ${SYS_DIR}/Setter_EventDriven.cpp
    ${SYS_DIR}/Getter_EventDriven.cpp
)

# 添加可执行文件
add_executable(KEY_EG 
  ${KEY_FILES}
  ${LED_FILES}
  ${SYS_FILES}
  Key_main.cpp
)

target_link_libraries(KEY_EG gpiod)
