cmake_minimum_required(VERSION 3.10)
project(camera_detection)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找必要的库
find_package(OpenCV REQUIRED)

# 包含目录
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/../src
    ${CMAKE_SOURCE_DIR}/../3rdparty
    ${CMAKE_SOURCE_DIR}/../3rdparty/TNN/include
    ${CMAKE_SOURCE_DIR}/../3rdparty/base-utils
    ${CMAKE_SOURCE_DIR}/../3rdparty/base-utils/base_utils/include
    /usr/local/include
    /usr/include
    /usr/include/libcamera
)

# 链接目录
link_directories(
    ${CMAKE_SOURCE_DIR}/../build
    ${CMAKE_SOURCE_DIR}/../3rdparty/TNN/lib
    ${CMAKE_SOURCE_DIR}/../build/3rdparty/TNN
    /usr/local/lib
    /usr/lib
)

# 添加可执行文件
add_executable(camera_detection camera_detection.cpp)

# 链接库
target_link_libraries(camera_detection
    ${OpenCV_LIBS}
    cam2opencv
    dmcv
    ${CMAKE_SOURCE_DIR}/../build/3rdparty/TNN/libTNN.so
    camera
    camera-base
    pthread
) 