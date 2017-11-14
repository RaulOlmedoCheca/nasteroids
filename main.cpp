#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include "Planet.h"
#include "Asteroid.h"
#include "Constants.h"
#include "Computations.h"

bool checkParametersNumber(int numberOfParameters);

int checkInteger(char const *arg);

double checkDouble(char const *arg);

void generateBodies(std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets, unsigned int seed);

void destroyerOfWorlds(double pos, std::vector<Asteroid *> asteroids);

int main(int argc, char const *argv[]) {
    // Check input parameters
    if (!checkParametersNumber(argc)) {
        return -1;
    }

    const int num_asteroids = checkInteger(argv[1]);
    const int num_iterations = checkInteger(argv[2]);
    const int num_planets = checkInteger(argv[3]);
    const double pos_ray = checkDouble(argv[4]);
    const auto seed = (unsigned int) checkInteger(argv[5]);

    std::vector<Asteroid *> asteroids((unsigned long) num_asteroids);
    std::vector<Planet *> planets((unsigned long) num_planets); 

    generateBodies(asteroids, planets, seed);

    for (int i = 0; i < num_iterations; ++i) {
        for (int j = 0; j < num_asteroids; ++j) {
            computePosition(*asteroids[j], asteroids, planets);
            computeReboundEffect(*asteroids[j]);
	    destroyerOfWorlds(pos_ray, asteroids);
        }
    }

    for (int k = 0; k < num_planets; ++k) {
        std::cout << "Planets: " << planets[k]->getPosX() << " " << planets[k]->getPosY() << std::endl;
    }
  
    for (int l = 0; l < num_asteroids; ++l) {
        std::cout << "Position of asteroid: " << l << " " << asteroids[l]->getPosX() << " " << asteroids[l]->getPosY() << std::endl;
    } 
   
    return 0;
}

/**
 * This function destroys an asteroid in positionY
 * @param position of the ray int pos
 * @param parameters pointer to the array with the asteroids
 */
void destroyerOfWorlds(double pos, std::vector<Asteroid *> asteroids){ 
  for(unsigned int i=0; i<asteroids.size(); i++){
    if(asteroids[i]->getPosY() < pos + (RAY_WIDTH/2) && asteroids[i]->getPosY() > pos - (RAY_WIDTH/2)){
	asteroids.erase(asteroids.begin() + i);
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
	if(std::stoi(arg) < 0) {
            std::cerr << "nasteroids-seq: Wrong arguments.\nCorrect use:\n"
                      << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << std::endl;
	    std::exit(-1);
	}
	return std::stoi(arg);
    }
    catch (...) {
        std::cerr << "nasteroids-seq: Wrong arguments.\nCorrect use:\n"
                  << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << std::endl;
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
	if(std::stod(arg) < 0) {
            std::cerr << "nasteroids-seq: Wrong arguments.\nCorrect use:\n"
                      << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << std::endl;
	    std::exit(-1);
	}
        return std::stod(arg);
    }
    catch (...) {
        std::cerr << "nasteroids-seq: Wrong arguments.\nCorrect use:\n"
                  << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << std::endl;
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
    int determineAxis = 0;
    for (auto &planet : planets) {
        // TODO: Revisar que los planetas esten bien generados de acuerdo con el paper
        switch (determineAxis) {
            case 0:
                planet = new Planet(xdist(re), 0, mdist(re) * 10);
                determineAxis++;
                break;
            case 1:
                planet = new Planet(SPACE_WIDTH, ydist(re), mdist(re) * 10);
                determineAxis++;
                break;
            case 2:
                planet = new Planet(xdist(re), SPACE_HEIGHT, mdist(re) * 10);
                determineAxis++;
                break;
            case 3:
                planet = new Planet(0, ydist(re), mdist(re) * 10);
                determineAxis = 0;
                break;
            default:
                std::cerr << "Something went really wrong" << std::endl;
        }

    }

}
