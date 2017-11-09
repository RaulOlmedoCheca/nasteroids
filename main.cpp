#include <iostream>
#include <cmath>
#include <random>
#include "Body.h"
#include "Planet.h"
#include "Asteroid.h"
#include "Constants.h"

bool checkParameters(int numberOfParameters, char const *parameters[]);

void generateBodies(std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets, unsigned int seed);

void applyReboundEffect(Asteroid a);

int main(int argc, char const *argv[]) {
    using namespace std;

    // Check input parameters
    if (!checkParameters(argc, argv)) {
        //INFO: commented because it is incomplete
        //return -1;
    }
    const int num_asteroids = stoi(argv[1]);
    //const int num_iterations = stoi(argv[2]);
    const int num_planets = stoi(argv[3]);
    //const int pos_ray = stoi(argv[4]);
    const unsigned int seed = (unsigned int) stoi(argv[5]);

    std::vector<Asteroid *> asteroids((unsigned long) num_asteroids);
    std::vector<Planet *> planets((unsigned long) num_planets);

    generateBodies(asteroids, planets, seed);

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
 * @param asteroids
 * @param planets
 * @param seed
 */
void generateBodies(std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets, unsigned int seed){
    // Random distributions
    std::default_random_engine re{seed};
    std::uniform_real_distribution<double> xdist{0.0, std::nextafter(SPACE_WIDTH, std::numeric_limits<double>::max())};
    std::uniform_real_distribution<double> ydist{0.0, std::nextafter(SPACE_HEIGHT, std::numeric_limits<double>::max())};
    std::normal_distribution<double> mdist{MASS, SD_MASS};

    for (unsigned long i = 0; i < asteroids.size(); ++i) {
        asteroids[i] = new Asteroid(xdist(re), ydist(re), mdist(re), 0);
    }

    for (unsigned long j = 0; j < planets.size(); ++j) {
        planets[j] = new Planet(xdist(re), ydist(re), mdist(re) * 10);
    }

}

/**
 *
 * @param a
 */
void applyReboundEffect(Asteroid a){
    //a.set
}
