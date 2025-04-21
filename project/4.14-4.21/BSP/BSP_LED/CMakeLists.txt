cmake_minimum_required(VERSION 3.1.0)
project(LED_EG)
set(CMAKE_CXX_STANDARD 14)

# find_package()
set(LED_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../BSP_LED)
set(SYS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../SYS_Con/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${LED_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../BSP_OLED)

set(LED_FILES
    Led_main.cpp
    Led.cpp
)
set(SYS_FILES
    ${SYS_DIR}/Sys_Functions.cpp
    ${SYS_DIR}/EventDriven.cpp
)

add_executable(LED_EG 
  ${LED_FILES}
  ${SYS_FILES}
)

target_link_libraries(LED_EG gpiod)
