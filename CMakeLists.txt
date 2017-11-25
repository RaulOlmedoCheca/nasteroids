cmake_minimum_required(VERSION 3.2.2)
project(nasteroids)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_BUILD_TYPE Release) #INFO: uncomment for performance testing

add_subdirectory(par)
add_subdirectory(seq)