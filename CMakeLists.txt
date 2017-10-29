cmake_minimum_required(VERSION 3.2.2)
project(nasteroids)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors")

set(SOURCE_FILES main.cpp Point.cpp Point.h)
add_executable(nasteroids ${SOURCE_FILES})