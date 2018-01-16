cmake_minimum_required(VERSION 2.6)
project(opencv)

#add_definitions(-std=c++11)
#add_compile_options(-std=c++11)
SET(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        ${PROJECT_SOURCE_DIR}/cmake/)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# Enable compile optimizations
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fsee -fomit-frame-pointer -fno-signed-zeros -fno-math-errno -funroll-loops")

# Enable debug flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3  -Wall")


# SSE3 is needed by libviso2 (its a cpu arch attribute)
# If we are on ARM we need to find an alternative
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse -msse2 -msse3")
file(GLOB_RECURSE external_headers external/*.h external/*.hpp)
file(GLOB_RECURSE external_sources external/*.cpp)


set(project_deps a b c d)

find_package(OpenCV 3)

list(APPEND project_lib
  ${OpenCV_LIBRARIES}
)

SET(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        ${PROJECT_SOURCE_DIR}/cmake/)

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(opencv main.cpp)
target_link_libraries(opencv ${OpenCV_LIBS})

install(TARGETS opencv RUNTIME DESTINATION bin)
