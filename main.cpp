#include <iostream>
#include <cmath>
#include <random>
#include "Body.h"
#include "Planet.h"
#include "Asteroid.h"

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

bool checkParameters(int numberOfParameters, char const *parameters[]);

void generateBodies(int numberOfAsteroids, int numberOfPlanets, unsigned int seed);

double computeDistance(Body a, Body b);

double computeAngleOfInfluence(Asteroid a, Body b);

double computeAcceleration();

std::tuple<double, double> computeAttractionForce(Asteroid a, Body b);

int main(int argc, char const *argv[]) {
    using namespace std;

    // Check input parameters
    if (!checkParameters(argc, argv)) {
        //INFO: commented because it is incomplete
        //return -1;
    }

    int num_asteroids = std::stoi(argv[1]);
    int num_iterations = std::stoi(argv[2]);
    int num_planets = std::stoi(argv[3]);
    int pos_array = std::stoi(argv[4]);
    unsigned int seed = std::stoi(argv[5]); //FIXME: cast to unsigned int instead of int

    generateBodies(num_asteroids, num_planets, seed);


    return 0;
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

/**
 * TODO:
 * @param numberOfAsteroids
 * @param numberOfPlanets
 * @param seed
 */
void generateBodies(int numberOfAsteroids, int numberOfPlanets, unsigned int seed) {
    // Random distributions
    std::default_random_engine re{seed};
    std::uniform_real_distribution<double> xdist{0.0, std::nextafter(SPACE_WIDTH, std::numeric_limits<double>::max())};
    std::uniform_real_distribution<double> ydist{0.0, std::nextafter(SPACE_HEIGHT, std::numeric_limits<double>::max())};
    std::normal_distribution<double> mdist{MASS, SD_MASS};

    for (int i = 0; i < numberOfAsteroids; ++i) {
        // Instantiate the object getting xdist(re), ydist(re) and mdist(re)
    }

    for (int j = 0; j < numberOfPlanets; ++j) {
        // Instantiate the object getting the planets on the maps sides (the mass is multiplied by 10)
    }

    /*** TEST -see if Planet class inherits from Body the getPosX and getPosY methods-  ***/

    /* ERROR: This way of creating an object has the scope of the function, we want to create it globally to
     * be able to use them in other functions */
    Planet *planet = new Planet(22.4, 0, 10.04);

    planet->getPosX();

    Asteroid *asteroid = new Asteroid(50.45, 24.0, 10.04, 0);

    asteroid->setPosX(23.89);
}

/**
 * This function returns the distance between the @param a and @param b
 * @param a body object
 * @param b body object
 * @return double distance
 */
double computeDistance(Body a, Body b) {
    return sqrt(pow((a.getPosX() - b.getPosX()), 2) + pow((a.getPosY() - b.getPosY()), 2));
}

/**
 * TODO:
 * @param a
 * @param b
 * @return
 */
double computeAngleOfInfluence(Asteroid a, Body b) {
    double slope = (a.getPosY() - b.getPosY()) / (a.getPosX() - b.getPosX());
    if (slope < -1 || slope > 1) {
        slope = slope - trunc(slope);
    }
    double alfa = atan(slope);
    return alfa;
}

/**
 *
 * @param a
 * @param b
 * @return
 */
std::tuple<double, double> computeAttractionForce(Asteroid a, Body b) {
    double distance = computeDistance(a, b);
    double alfa = computeAngleOfInfluence(a, b);

    // INFO: do we create a variable for the mass in each object?
    // INFO: maybe we should add an acceleration or force exerted field to the asteroid instead of the velocity
    double forceInXAxis = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * cos(alfa);
    double forceInYAxis = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * sin(alfa);

    /* TODO: Apply the force positively for a and negatively for b, an element wont exert force to himself,
     * take care of the case in which the b Body is a planet */

    return std::make_tuple(forceInXAxis, forceInYAxis);
}
