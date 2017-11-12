# nasteroids

[![Build Status](https://travis-ci.com/RaulOlmedoCheca/nasteroids.svg?token=FAmyHcKt9Zn9dEwKo3Ts&branch=master)](https://travis-ci.com/RaulOlmedoCheca/nasteroids)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/0d6ab79e59ee46b5b4470cfba011a96a)](https://www.codacy.com?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=RaulOlmedoCheca/nasteroids&amp;utm_campaign=Badge_Grade)

Final Project of ARCOS

## TODO:

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
 
 
