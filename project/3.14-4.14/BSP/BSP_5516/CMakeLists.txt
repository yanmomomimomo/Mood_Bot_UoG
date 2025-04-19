cmake_minimum_required(VERSION 3.1.0)
project(5516_EG)
set(CMAKE_CXX_STANDARD 17)

# find_package()
set(KEY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_KEYS)
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
    ${KEY_DIR}Keys.cpp
    ${KEY_DIR}Key_register.cpp
)
# 5516
set(KEY_FILES
    5516.cpp
    5516_main.cpp
)
# System
set(SYS_FILES
    ${SYS_DIR}/Sys_Functions.cpp
    ${SYS_DIR}/Setter_EventDriven.cpp
    ${SYS_DIR}/Getter_EventDriven.cpp
)

# 添加可执行文件
add_executable(5516_EG 
  ${KEY_FILES}
  ${LED_FILES}
  ${SYS_FILES}
)

target_link_libraries(5516_EG gpiod)
