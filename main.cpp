#include <iostream>
#include <cmath>
#include <random>
#include "Planet.h"
#include "Asteroid.h"
#include "Constants.h"
#include "Computations.h"

bool checkParameters(int numberOfParameters, char const *parameters[]);

void generateBodies(std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets, unsigned int seed);

int main(int argc, char const *argv[]) {
    using namespace std;

    // Check input parameters
    if (!checkParameters(argc, argv)) {
        //INFO: commented because it is incomplete
        //return -1;
    }
    int num_asteroids = stoi(argv[1]);
    const int num_iterations = stoi(argv[2]);
    int num_planets = stoi(argv[3]);
    float pos_ray = stof(argv[4]);
    const unsigned int seed = (unsigned int) stoi(argv[5]);

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
