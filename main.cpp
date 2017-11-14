#include <iostream>
#include <cmath>
#include <random>
#include "Planet.h"
#include "Asteroid.h"
#include "Constants.h"
#include "Computations.h"

//libraries for file creation
#include <iostream>
#include <fstream> //Stream class to both read and write from/to files

bool checkParametersNumber(int numberOfParameters);

int checkInteger(char const *arg);

double checkDouble(char const *arg);

void generateBodies(std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets, unsigned int seed);

void generateInitFile(const int num_asteroids, const int num_iterations, const int num_planets, double pos_ray, const unsigned int seed, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets);

void generateFinalFile(std::vector<Asteroid *> &asteroids);

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


    generateInitFile(num_asteroids, num_iterations, num_planets, pos_ray, seed, asteroids, planets);

    for (int i = 0; i < num_iterations; ++i) {
        for (int j = 0; j < num_asteroids; ++j) {
            computePosition(*asteroids[j], asteroids, planets);
            computeReboundEffect(*asteroids[j]);
        }
    }

    //after all iteration and when everything is de puta madre
    generateFinalFile(asteroids);

    return 0;
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
        std::cerr << "Invalid argument" << '\n';
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
        std::cerr << "Invalid argument" << '\n';
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

void generateInitFile(const int num_asteroids, const int num_iterations, const int num_planets, double pos_ray, const unsigned int seed, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets){
double x;
double y;
double mass;
std::ofstream outfile_init ("init_conf.txt");
//write arguments in the first line of the file
outfile_init << num_asteroids << " " << num_iterations << " " << num_planets << " " << pos_ray << " " << seed << std::endl;
//write asteroids
for(int i = 0; i < num_asteroids; ++i){  // for (auto &asteroid : asteroids) { & we could skip argument 1
   x = (trunc((asteroids[i]->getPosX())*1000)/1000);
   y = (trunc((asteroids[i]->getPosY())*1000)/1000);
   mass = (trunc((asteroids[i]->getMass())*1000)/1000);
   outfile_init << x << " " << y << " " << mass << std::endl;
}
//write planets
for(int i = 0; i < num_planets; ++i){ // for (auto i : planets) {  & we could skip argument 3
  x = (trunc((planets[i]->getPosX())*1000)/1000);
  y = (trunc((planets[i]->getPosY())*1000)/1000);
  mass = (trunc((planets[i]->getMass())*1000)/1000);
  outfile_init << x << " " << y << " " << mass << std::endl;
}
//write pos_ray position
  x = 0.000; // position x of the pos_ray will always be 0
  y = (round(pos_ray*1000)/1000);
  outfile_init << x << " " << y << std::endl;

 //close the file
 outfile_init.close();
}


void generateFinalFile(std::vector<Asteroid *> &asteroids){
  double x;
  double y;
  double velX;
  double velY;
  std::ofstream outfile_final ("out.tx");
  //write asteroids
  for (auto &asteroid : asteroids) {
     x = (trunc((asteroid->getPosX())*1000)/1000);
     y = (trunc((asteroid->getPosY())*1000)/1000);
     velX = (trunc((asteroid->getVelocityX())*1000)/1000);
     velY = (trunc((asteroid->getVelocityY())*1000)/1000);
     outfile_final << x << " " << y << " " << velX << " " << velY << std::endl;
  }
   //close the file
   outfile_final.close();

}
