cmake_minimum_required(VERSION 2.6)
project(opencv)

find_package(OpenCV 3)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(opencv main.cpp)
target_link_libraries(opencv ${OpenCV_LIBS})

install(TARGETS opencv RUNTIME DESTINATION bin)
