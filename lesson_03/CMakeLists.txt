cmake_minimum_required(VERSION 3.10)
project(lesson_03)

set(CMAKE_CXX_STANDARD 20)

set(OpenCV_DIR "C:/opencv/build/install")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(lesson_03 main.cpp)

target_link_libraries(lesson_03 ${OpenCV_LIBS})