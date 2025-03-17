cmake_minimum_required(VERSION 3.30)
project(Mood_Bot_UoG)

set(CMAKE_CXX_STANDARD 14)

# OpenCV
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(Mood_Bot_UoG
    FacialRecog/Main.cpp)
target_link_libraries(Mood_Bot_UoG ${OpenCV_LIBS})
