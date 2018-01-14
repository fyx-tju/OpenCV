cmake_minimum_required(VERSION 2.6)
project(opencv)

add_executable(opencv main.cpp)

install(TARGETS opencv RUNTIME DESTINATION bin)
