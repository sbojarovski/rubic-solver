cmake_minimum_required(VERSION 3.3)
project(rubic-solver)

find_package( OpenCV REQUIRED )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(rubic-solver ${SOURCE_FILES})
target_link_libraries( rubic-solver ${OpenCV_LIBS} )