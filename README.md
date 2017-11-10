# nasteroids

[![Build Status](https://travis-ci.com/RaulOlmedoCheca/nasteroids.svg?token=FAmyHcKt9Zn9dEwKo3Ts&branch=master)](https://travis-ci.com/RaulOlmedoCheca/nasteroids)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/0d6ab79e59ee46b5b4470cfba011a96a)](https://www.codacy.com?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=RaulOlmedoCheca/nasteroids&amp;utm_campaign=Badge_Grade)

Final Project of ARCOS

## TODO:
+ Posibles objetos: 
    + Body
    + Asteroid
    + Planet
    + Ray
    
``Asteroid.cpp``

(4, 4) * TODO:

(12, 4) * TODO:

(20, 4) * TODO:

``Body.cpp``

(5, 4) * TODO:

(13, 4) * TODO:

(21, 4) * TODO:

(29, 4) * TODO:

(37, 4) * TODO:

(45, 4) * TODO:

(62, 4) * TODO:

(65, 8) // TODO: implementamos destructores?

``Body.h``

(25, 17) ~Body(); // TODO: implementamos destructores?

``CMakeLists.txt``

(5, 32) #set(CMAKE_BUILD_TYPE Release) INFO: uncomment this to test performance, leave it commented otherwise

``main.cpp``

(18, 4) // INFO: The Point & distance classes are implemented natively in C++, maybe we could reuse them

(37, 11) //INFO: commented because it is incomplete

(45, 47) unsigned int seed = std::stoi(argv[5]); //FIXME: cast to unsigned int instead of int

(60, 7) //TODO: handle all possible inputs

(73, 4) * TODO:

(95, 8) /* ERROR: This way of creating an object has the scope of the function, we want to create it globally to

(117, 4) * TODO:

(141, 8) // INFO: do we create a variable for the mass in each object?

(142, 8) // INFO: maybe we should add an acceleration or force exerted field to the asteroid instead of the velocity

(146, 8) /* TODO: Apply the force positively for a and negatively for b, an element wont exert force to himself,

``Planet.cpp``

(5, 4) * TODO:

``Planet.h``

(9, 8) // TODO: override setters to avoid changing the position to a planet
***
## Documentation

### Parameters of the program: 
**num_asteroids:** is an integer number, greater or equal than 0, which indicates the number of asteroids 
that will be simulated.

**num iterations:** is an integer number, greater or equal than 0, which indicates the number of iterations (time steps) 
that will be simulated.

**num_planets:** is an integer number, greater or equal than 0, which indicates the number of planets that will be included
at the border of the space.

**pos_ray:** is a double precision floating point number, which indicates the exact position of the ray in the 
space (y coordinate).

**seed:** is a positive integer number that serves as seed for the generator functions for random numbers.

### Calling the program 
`nasteroids-seq num\_asteroids num\_iterations num\_planets pos\_ray seed`

### Generated output
`init_config.txt` containing:

+ Input parameters separated by a space in the same order in which they were introduced (without including the name 
of the program).

+ For each asteroid first, planet and ray, their position must be stored (x and y), as well as their mass
(only for asteroids). Each element must be written in a line wit their parameters separated by spaces. When printing 
floating point numbers, 3 decimals must be printed.

```cpp
 // Random distributions
 default_random_engine re{seed};
 uniform_real_distribution<double> xdist{0.0, std::nextafter(width, std::numeric_limits<double>::max())};
 uniform_real_distribution<double> ydist{0.0, std::nextafter(height, std::numeric_limits<double>::max())};
 normal_distribution<double> mdist{mass, sdm};
 ```
 
 
