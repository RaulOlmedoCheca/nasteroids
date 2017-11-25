set(CMAKE_CXX_FLAGS " -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors -fopenmp")
set(SOURCE_FILES_PAR main.cpp Body.cpp Body.h Planet.h Asteroid.h Planet.cpp Asteroid.cpp Constants.h Computations.h Computations.cpp)
add_executable(nasteroids-par ${SOURCE_FILES_PAR})
