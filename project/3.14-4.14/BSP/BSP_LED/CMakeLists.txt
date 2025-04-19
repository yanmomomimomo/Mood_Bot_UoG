cmake_minimum_required(VERSION 3.1.0)
project(LED_EG)
set(CMAKE_CXX_STANDARD 14)

# find_package()
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SYS_DIR})

# 设置源文件列表
set(LED_FILES
    Led_main.cpp
    Led.cpp
)
set(SYS_FILES
    ${SYS_DIR}/Sys_Functions.cpp
    ${SYS_DIR}/EventDriven.cpp
)

# 添加可执行文件
add_executable(LED_EG 
  ${LED_FILES}
  ${SYS_FILES}
)

target_link_libraries(LED_EG gpiod)
