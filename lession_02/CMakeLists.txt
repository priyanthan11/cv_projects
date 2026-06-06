# Minimum CMake version required to process this file.
# Version 3.10 introduced support for CXX_STANDARD as a target property.
cmake_minimum_required(VERSION 3.10)

# Project name - also sets CMAKE_PROJECT_NAME and influences default binary names.
project(lesson_02)

# Enforce C++20. CMake passes /std:c++20 (MSVC) or -std=c++20 (GCC/Clang).
set(CMAKE_CXX_STANDARD 20)

# Tell CMake where to find OpenCVConfig.cmake so find_package can locate
# the headers and libraries. Adjust this path if OpenCV is installed elsewhere.
set(OpenCV_DIR "C:/opencv/build/install")

# Locate OpenCV. REQUIRED causes a fatal error if the package is not found.
# After this call the following variables are set:
#   OpenCV_INCLUDE_DIRS - paths to OpenCV headers
#   OpenCV_LIBS         - list of all OpenCV library targets to link against
#   OpenCV_VERSION      - version string of the found package
find_package(OpenCV REQUIRED)

# Add the OpenCV headers to the compiler's include search path.
include_directories(${OpenCV_INCLUDE_DIRS})

# Define the executable target built from a single translation unit.
add_executable(lesson_02 main.cpp)

# Link against all OpenCV component libraries (core, imgcodecs, imgproc,
# highgui, etc.) discovered by find_package above.
target_link_libraries(lesson_02 ${OpenCV_LIBS})
