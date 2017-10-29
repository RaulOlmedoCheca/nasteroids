#include <iostream>
#include <cmath>
#include <random>
#include "Body.h"
#include "Planet.h"

#define GRAVITY 6.674e-5
#define TIME_INTERVAL 0.1
#define MINIMUM_DISTANCE 2.0
#define SPACE_WIDTH 200
#define SPACE_HEIGHT 200
#define RAY_WIDTH 4
#define MASS 1000
#define SD_MASS 50
#define PARAMETERS_REQUIRED 5

// INFO: The Point & distance classes are implemented natively in C++, maybe we could reuse them

double distance(Body a, Body b);

bool checkParameters(int numberOfParameters, char const *parameters[]);

int main(int argc, char const *argv[]) {
    using namespace std;

    /* USEFUL INFO */
    // argv[1] = num_asteroids
    // argv[2] = num_iterations
    // argv[3] = num_planets
    // argv[4] = pos_ray
    // argv[5] = seed

    // Check input
    if (!checkParameters(argc, argv)) {
        //INFO: commented because it is incomplete
        //return -1;
    };

    /* Test, a ver que hacen las locuras estas de distribuciones */
    /**************************************************************/
    unsigned int seed = 45674;
    // Random distributions
    default_random_engine re{seed};
    uniform_real_distribution<double> xdist{0.0, std::nextafter(SPACE_WIDTH, std::numeric_limits<double>::max())};
    uniform_real_distribution<double> ydist{0.0, std::nextafter(SPACE_HEIGHT, std::numeric_limits<double>::max())};
    normal_distribution<double> mdist{MASS, SD_MASS};

    std::cout << xdist(re) << std::endl;
    std::cout << ydist(re) << std::endl;
    std::cout << mdist(re) << std::endl;
    /**************************************************************/

    /*** TEST -see if Planet class inherits from Point the x and y methods  ***/

    auto* planet = new Planet(22.4, 24.0, 10.04);

    planet.getPosX();


    return 0;
}

/**
 * This function returns the distance between the @param a and @param b
 * @param a body object
 * @param b body object
 * @return double distance
 */
double distance(Body a, Body b) {
    return sqrt(pow((a.getX() - b.getX()), 2) + pow((a.getY() - b.getY()), 2));
}

/**
 * This function checks the parameters used in the call to the program
 * @param numberOfParameters int number of parameters
 * @param parameters pointer to the array with the parameters
 * @return false if error, true if none
 */
bool checkParameters(int numberOfParameters, char const *parameters[]) {
    //TODO: handle all possible inputs
    if (numberOfParameters < PARAMETERS_REQUIRED + 1) {
        std::cerr << "Wrong number of parameters\n" << std::endl;
        return false;
    }
    for (int i = 0; i < numberOfParameters; ++i) {
        std::cout << parameters[0] << std::endl;
    }
    return true;

}