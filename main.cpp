#include <iostream>
#include <cmath>
#include <random>
#include "Planet.h"
#include "Asteroid.h"
#include "Constants.h"
#include "Computations.h"

bool checkParametersNumber(int numberOfParameters);

int checkInteger(char const *arg);

double checkDouble(char const *arg);

void generateBodies(std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets, unsigned int seed);

int main(int argc, char const *argv[]) {
    // Check input parameters
    if(!checkParametersNumber(argc)){
      return -1;
    }

    const int num_asteroids = checkInteger(argv[1]);
    const int num_iterations = checkInteger(argv[2]);
    const int num_planets = checkInteger(argv[3]);
    const double pos_ray = checkDouble(argv[4]);
    const unsigned int seed = (unsigned int) checkInteger(argv[5]);

    std::vector<Asteroid *> asteroids((unsigned long) num_asteroids);
    std::vector<Planet *> planets((unsigned long) num_planets); 

    generateBodies(asteroids, planets, seed);

    for (int i = 0; i < num_iterations; ++i) {
        for (int j = 0; j < num_asteroids; ++j) {
            computePosition(*asteroids[j], asteroids, planets);
            computeReboundEffect(*asteroids[j]);
	    cout << "Position of asteroid: " << j << " " << asteroids[j].getPosX() << " " << asteroids[j].getPosY() << endl;
            destroyerOfWorlds(pos_ray, asteroids);
        }
    }

    for (int i = 0; i < num_iterations; ++i) {
        for (int j = 0; j < num_asteroids; ++j) {
	    cout << "Position of asteroid: " << j << " " << asteroids[j].getPosX() << " " << asteroids[j].getPosY() << endl;
        }
    }

    return 0;
}

/**
 * This function destroys an asteroid in positionY
 * @param position of the ray int pos
 * @param parameters pointer to the array with the asteroids
 */
void destroyerOfWorlds(float pos, vector<Asteroid *> asteroids){ 
  for(int i=0; i<asteroids.size(); i++){
    if(asteroids[i].getPosY() < pos + (RAY_WIDTH/2) && androids[i].getPosY() > pos - (RAY_WIDTH/2)){
	asteroids[i].erase(asteroids[i].begin() + i);
    }
  }
}

/**
 * This function checks the parameters used in the call to the program
 * @param numberOfParameters int number of parameters
 * @return false if error, true if none
 */
bool checkParametersNumber(int numberOfParameters) {
    if (numberOfParameters < PARAMETERS_REQUIRED + 1) {
        std::cerr << "nasteroids-seq: Wrong arguments.\nCorrect use:\n"
        << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << std::endl;
        return false;
    }
    return true;
}

/**
 * This function checks expected integer arguments 
 * @param arg char const* argument integer value
 * @return integer value, exits with error code -1 if error
 */
int checkInteger(char const *arg) {
  try {
    return std::stoi(arg);
  }
  catch (...) {
    std::cerr << "Invalid argument"<<'\n';
    std::exit(-1);
  }
}

/**
 * This function checks expected double arguments 
 * @param arg char const* argument double value
 * @return value in double, exits with error code -1 if error
 */
double checkDouble(char const *arg) {
  try {
    return std::stod(arg);
  }
  catch (...) {
    std::cerr << "Invalid argument"<<'\n';
    std::exit(-1);
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
