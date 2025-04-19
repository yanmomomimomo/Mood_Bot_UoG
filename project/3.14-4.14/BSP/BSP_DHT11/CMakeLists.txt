cmake_minimum_required(VERSION 3.1.0)
project(DHT_EG)
set(CMAKE_CXX_STANDARD 14)

# find_package()
set(KEY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_KEYS)
set(LED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LED)
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SYS_DIR})

# LED
set(LED_FILES
    ${LED_DIR}/Led.cpp
)
#KEY
set(KEY_FILES
    ${KEY_DIR}/Keys.cpp

)
# DHT
set(DHT_FILES
    DHT11_main.cpp
    DHT11.cpp

)
# System
set(SYS_FILES
    ${SYS_DIR}/Sys_Functions.cpp
    ${SYS_DIR}/Setter_EventDriven.cpp
)

# 添加可执行文件
add_executable(DHT_EG 
  ${KEY_FILES}
  ${LED_FILES}
  ${SYS_FILES}
  ${DHT_FILES}
)

target_link_libraries(DHT_EG gpiod)
