set(CMAKE_CXX_FLAGS " -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors")
set(SOURCE_FILES_SEQ main.cpp Body.cpp Body.h Planet.h Asteroid.h Planet.cpp Asteroid.cpp Constants.h Computations.h Computations.cpp)
add_executable(nasteroids-seq ${SOURCE_FILES_SEQ})