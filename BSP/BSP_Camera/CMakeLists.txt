cmake_minimum_required(VERSION 3.5)
project(Detector)

add_compile_options(-fPIC) # fix Bug: can not be used when making a shared object
set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -pthread")
#set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    # -DCMAKE_BUILD_TYPE=Debug
    # -DCMAKE_BUILD_TYPE=Release
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type (default Debug)" FORCE)
endif ()

# opencv set
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} ./src/)
#MESSAGE(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")

# base_utils
######################################################
set(BASE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/3rdparty/base-utils) # 设置base-utils所在的根目录
add_subdirectory(${BASE_ROOT}/base_utils/ base_build) # 添加子目录到build中
include_directories(${BASE_ROOT}/base_utils/include)
include_directories(${BASE_ROOT}/base_utils/src)
MESSAGE(STATUS "BASE_ROOT = ${BASE_ROOT}")


# TNN set
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake buil ds it for you.
# Gradle automatically packages shared libraries with your APK.
# build for platform
# set(TNN_BUILD_SHARED OFF CACHE BOOL "" FORCE)
if (CMAKE_SYSTEM_NAME MATCHES "Android")
    set(TNN_OPENCL_ENABLE ON CACHE BOOL "" FORCE)
    set(TNN_ARM_ENABLE ON CACHE BOOL "" FORCE)
    set(TNN_BUILD_SHARED OFF CACHE BOOL "" FORCE)
    set(TNN_OPENMP_ENABLE ON CACHE BOOL "" FORCE)  # Multi-Thread
    #set(TNN_HUAWEI_NPU_ENABLE OFF CACHE BOOL "" FORCE)
    add_definitions(-DTNN_OPENCL_ENABLE)           # for OpenCL GPU
    add_definitions(-DTNN_ARM_ENABLE)              # for Android CPU
    add_definitions(-DDEBUG_ANDROID_ON)            # for Android Log
    add_definitions(-DPLATFORM_ANDROID)
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(TNN_OPENCL_ENABLE ON CACHE BOOL "" FORCE)
    set(TNN_CPU_ENABLE ON CACHE BOOL "" FORCE)
    set(TNN_X86_ENABLE OFF CACHE BOOL "" FORCE)
    set(TNN_QUANTIZATION_ENABLE OFF CACHE BOOL "" FORCE)
    set(TNN_OPENMP_ENABLE ON CACHE BOOL "" FORCE)  # Multi-Thread
    add_definitions(-DTNN_OPENCL_ENABLE)           # for OpenCL GPU
    add_definitions(-DDEBUG_ON)                    # for WIN/Linux Log
    add_definitions(-DDEBUG_LOG_ON)                # for WIN/Linux Log
    add_definitions(-DDEBUG_IMSHOW_OFF)            # for OpenCV show
    add_definitions(-DPLATFORM_LINUX)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(TNN_OPENCL_ENABLE ON CACHE BOOL "" FORCE)
    set(TNN_CPU_ENABLE ON CACHE BOOL "" FORCE)
    set(TNN_X86_ENABLE ON CACHE BOOL "" FORCE)
    set(TNN_QUANTIZATION_ENABLE OFF CACHE BOOL "" FORCE)
    set(TNN_OPENMP_ENABLE ON CACHE BOOL "" FORCE)  # Multi-Thread
    add_definitions(-DTNN_OPENCL_ENABLE)           # for OpenCL GPU
    add_definitions(-DDEBUG_ON)                    # for WIN/Linux Log
    add_definitions(-DDEBUG_LOG_ON)                # for WIN/Linux Log
    add_definitions(-DDEBUG_IMSHOW_OFF)            # for OpenCV show
    add_definitions(-DPLATFORM_WINDOWS)
endif ()

#######################################
set(TNN_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/3rdparty/TNN)
include_directories(${TNN_ROOT}/include)
include_directories(${TNN_ROOT}/third_party/opencl/include)

# add_subdirectory(${TNN_ROOT}) # 添加外部项目文件夹
add_subdirectory(
    /home/MootBot/MoodBot_Product/lib/3rdparty/TNN
    ${CMAKE_BINARY_DIR}/TNN_build
)

set(TNN -Wl,--whole-archive TNN -Wl,--no-whole-archive)# set TNN library
MESSAGE(STATUS "TNN_ROOT = ${TNN_ROOT}")


# Detector
########################################
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#############################################
set(SRC_LIST
        Camera.cpp
        object_detection.cpp
        classification.cpp
        Interpreter.cpp)
add_library(dmcv SHARED ${SRC_LIST})
target_link_libraries(dmcv ${OpenCV_LIBS} base_utils)
MESSAGE(STATUS "DIR_SRCS = ${SRC_LIST}")

add_executable(Detector main.cpp)
target_link_libraries(Detector dmcv ${TNN} -lpthread)


