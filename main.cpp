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

Body** generateBodies(int numberOfAsteroids, int numberOfPlanets, unsigned int seed);

double computeDistance(Body a, Body b);

double computeAngleOfInfluence(Body a, Body b);

double computeAcceleration();

double computeAttractionForce(Body a, Body b);

int main(int argc, char const *argv[]) {
    using namespace std;

    // Check input parameters
    if (!checkParameters(argc, argv)) {
        //INFO: commented because it is incomplete
        //return -1;
    }
    const int num_asteroids = stoi(argv[1]);
    const int num_iterations = stoi(argv[2]);
    const int num_planets = stoi(argv[3]);
    //const int pos_ray = stoi(argv[4]);
    const unsigned int seed = (unsigned int) stoi(argv[5]);

    // Get the array that contains the array of asteroids and planets (bodies[0] = *asteroids[], bodies[1] = *planets[])
    Body **bodies = generateBodies(num_asteroids, num_planets, seed);


    for (int i = 0; i < num_iterations; ++i) {
        for (int j = 0; j < num_asteroids; ++j) {
            for (int k = 0; k < num_planets; ++k) {
                computeAttractionForce(bodies[0][j], bodies[1][k]);
            }
        }
    }




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
 * @return
 */
Body** generateBodies(const int numberOfAsteroids, const int numberOfPlanets, const unsigned int seed) {
    // Random distributions
    std::default_random_engine re{seed};
    std::uniform_real_distribution<double> xdist{0.0, std::nextafter(SPACE_WIDTH, std::numeric_limits<double>::max())};
    std::uniform_real_distribution<double> ydist{0.0, std::nextafter(SPACE_HEIGHT, std::numeric_limits<double>::max())};
    std::normal_distribution<double> mdist{MASS, SD_MASS};

    Asteroid *asteroids[numberOfAsteroids];
    Planet *planets[numberOfPlanets];

    for (int i = 0; i < numberOfAsteroids; ++i) {
        asteroids[i] = new Asteroid(xdist(re), ydist(re), mdist(re), 0);
    }

    for (int j = 0; j < numberOfPlanets; ++j) {
        planets[j] = new Planet(xdist(re), ydist(re), mdist(re) * 10);
    }

    /* To access the functions inside an instance of a class
     *
     * Planet *planet = new Planet(22.4, 0, 10.04);
     * planet->getPosX();
     *
     * */

    // INFO: this code snippet may be wrong
    Body **bodies[numberOfAsteroids+numberOfPlanets];
    *bodies[0] = *asteroids;
    *bodies[1] = *planets;

    return *bodies;
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
double computeAngleOfInfluence(Body a, Body b) {
    // INFO: take care of the case of computing two planet's angle of influence ????
    double slope = (a.getPosY() - b.getPosY()) / (a.getPosX() - b.getPosX());
    if (slope < -1 || slope > 1) {
        slope = slope - trunc(slope);
    }
    double alfa = atan(slope);
    return alfa;
}

/**
 * TODO:
 * @param a
 * @param b
 * @return
 */
double computeAttractionForce(Body a, Body b) {
    double distance = computeDistance(a, b);
    double alfa = computeAngleOfInfluence(a, b);

    double forceInXAxis = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * cos(alfa);
    double forceInYAxis = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * sin(alfa);

    /* TODO: Apply the force positively for a and negatively for b, an element wont exert force to himself,
     * take care of the case in which the b Body is a planet */

    return forceInXAxis*forceInYAxis;
}
