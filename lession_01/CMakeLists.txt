# Minimum CMake version required to process this file.
# Version 3.10 introduced support for CXX_STANDARD as a target property.
cmake_minimum_required(VERSION 3.10)

# Project name - also sets CMAKE_PROJECT_NAME and influences default binary names.
project(lesson_01)

# Enforce C++20. CMake will pass /std:c++20 (MSVC) or -std=c++20 (GCC/Clang).
set(CMAKE_CXX_STANDARD 20)

# Point CMake to the OpenCV installation directory so find_package can locate
# OpenCVConfig.cmake. Adjust this path if OpenCV is installed elsewhere.
set(OpenCV_DIR "C:/opencv/build/install")

# Locate the OpenCV package. REQUIRED causes a fatal error if not found.
# Sets variables: OpenCV_INCLUDE_DIRS, OpenCV_LIBS, OpenCV_VERSION, etc.
find_package(OpenCV REQUIRED)

# Add the OpenCV headers to the compiler's include search path.
include_directories(${OpenCV_INCLUDE_DIRS})

# Define the build target: an executable named 'lesson_01' built from main.cpp.
add_executable(lesson_01 main.cpp)

# Link the executable against all OpenCV component libraries found above
# (e.g. opencv_core, opencv_highgui, opencv_imgproc, etc.).
target_link_libraries(lesson_01 ${OpenCV_LIBS})
