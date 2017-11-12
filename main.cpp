#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include "Planet.h"
#include "Asteroid.h"
#include "Constants.h"
#include "Computations.h"

bool checkParameters(int numberOfParameters, char const *parameters[]);

int checkInteger(char const *arg);

float checkFloat(char const *arg);

void generateBodies(std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets, unsigned int seed);

int main(int argc, char const *argv[]) {
    // Check input parameters
    if(!checkParameters(argc, argv)){
      return -1;
    }

    const int num_asteroids = checkInteger(argv[1]);
    const int num_iterations = checkInteger(argv[2]);
    const int num_planets = checkInteger(argv[3]);
    const float pos_ray = checkFloat(argv[4]);
    const unsigned int seed = (unsigned int) checkInteger(argv[5]);

    std::vector<Asteroid *> asteroids((unsigned long) num_asteroids);
    std::vector<Planet *> planets((unsigned long) num_planets);

    generateBodies(asteroids, planets, seed);

    for (int i = 0; i < num_iterations; ++i) {
        for (int j = 0; j < num_asteroids; ++j) {
            computePosition(*asteroids[j], asteroids, planets);
            computeReboundEffect(*asteroids[j]);
        }
    }

    std::cout << "Testing..." << '\n';
    std::cout << num_planets << '\n';
    std::cout << num_iterations << '\n';
    std::cout << pos_ray << '\n';
    std::cout << seed << '\n';

    return 0;
}

/**
 * This function checks the parameters used in the call to the program
 * @param numberOfParameters int number of parameters
 * @param parameters pointer to the array with the parameters
 * @return false if error, true if none
 */
bool checkParametersNumber(int numberOfParameters, char const *parameters[]) {
    if (numberOfParameters < PARAMETERS_REQUIRED + 1) {
        std::cerr << parameters[0] << ": Wrong arguments.\nCorrect use:\n" << parameters[0]
        << "num_asteroids num_iterations num_planets pos_ray seed" << std::endl;
        return false;
    }
    return true;
}

int checkInteger(char const *arg) {
  try {
    return std::stoi(arg);
  }
  catch (...) {
    std::cerr << "Invalid argument"<<'\n';
    return -1;
  }
}

float checkFloat(char const *arg) {
  try {
    return std::stof(arg);
  }
  catch (...) {
    std::cerr << "Invalid argument"<<'\n';
    return -1;
  }
}

/**
 * TODO:
 * @param asteroids
 * @param planets
 * @param seed
 */
void generateBodies(std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets, unsigned int seed) {
    // Random distributions
    std::default_random_engine re{seed};
    std::uniform_real_distribution<double> xdist{0.0, std::nextafter(SPACE_WIDTH, std::numeric_limits<double>::max())};
    std::uniform_real_distribution<double> ydist{0.0, std::nextafter(SPACE_HEIGHT, std::numeric_limits<double>::max())};
    std::normal_distribution<double> mdist{MASS, SD_MASS};

    for (auto &asteroid : asteroids) {
        asteroid = new Asteroid(xdist(re), ydist(re), mdist(re), 0, 0);
    }

    // ERROR: the planet generated is not on an axis
    for (auto &planet : planets) {
        planet = new Planet(xdist(re), ydist(re), mdist(re) * 10);
    }

}
