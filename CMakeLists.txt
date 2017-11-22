cmake_minimum_required(VERSION 3.2.2)
project(nasteroids)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS " -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors")
set(SOURCE_FILES_SEQ nasteroids-seq/main.cpp nasteroids-seq/Body.cpp nasteroids-seq/Body.h nasteroids-seq/Planet.h nasteroids-seq/Asteroid.h nasteroids-seq/Planet.cpp nasteroids-seq/Asteroid.cpp nasteroids-seq/Constants.h nasteroids-seq/Computations.h nasteroids-seq/Computations.cpp)
add_executable(nasteroids-seq ${SOURCE_FILES_SEQ})

#FIXME: build the seq without openmp flag and the par one with it
set(CMAKE_CXX_FLAGS " -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors -fopenmp")
set(SOURCE_FILES_PAR nasteroids-par/main.cpp nasteroids-par/Body.cpp nasteroids-par/Body.h nasteroids-par/Planet.h nasteroids-par/Asteroid.h nasteroids-par/Planet.cpp nasteroids-par/Asteroid.cpp nasteroids-par/Constants.h nasteroids-par/Computations.h nasteroids-par/Computations.cpp)
add_executable(nasteroids-par ${SOURCE_FILES_PAR})
