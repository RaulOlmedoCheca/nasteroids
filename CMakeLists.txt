cmake_minimum_required(VERSION 3.2.2)
project(nasteroids)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release) #INFO: uncomment this to test performance, leave it commented otherwise
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors")

set(SOURCE_FILES main.cpp Body.cpp Body.h Planet.h Asteroid.h Planet.cpp Asteroid.cpp Constants.h Computations.h Computations.cpp)
add_executable(nasteroids ${SOURCE_FILES})
