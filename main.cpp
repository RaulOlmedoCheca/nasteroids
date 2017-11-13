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

bool checkParameters(int numberOfParameters, char const *parameters[]);

void generateBodies(std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets, unsigned int seed);

void generateInitFile(const int num_asteroids, const int num_iterations, const int num_planets, double pos_ray, const unsigned int seed, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets);

void generateFinalFile(std::vector<Asteroid *> &asteroids);

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
    double pos_ray = stod(argv[4]);
    const unsigned int seed = (unsigned int) stoi(argv[5]);

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
 * @param parameters pointer to the array with the parameters
 * @return false if error, true if none
 */
bool checkParameters(int numberOfParameters, char const *parameters[]) {
    //TODO: handle all possible inputs
    if (numberOfParameters < PARAMETERS_REQUIRED + 1) {
        std::cerr << "nasteroids-par: Wrong arguments.\n
                      Correct use:\n
                      nasteroids-par num_asteroids num_iterations num_planets pos_ray seed\n" << std::endl;
        return false;
    }
    for (int i = 0; i < numberOfParameters; ++i) {
        std::cout << parameters[1] << std::endl;
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

void generateInitFile(const int num_asteroids, const int num_iterations, const int num_planets, double pos_ray, const unsigned int seed, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets){
double x;
double y;
double mass;
std::ofstream outfile_init ("init_conf.txt");
//write arguments in the first line of the file
outfile_init << num_asteroids << " " << num_iterations << " " << num_planets << " " << pos_ray << " " << seed << std::endl;
//write asteroids
for(int i = 0; i < num_asteroids; ++i){  // for (auto i : asteroid) { & we could skip argument 1
   x = (round(asteroid[i]->getPosX()*1000)/1000);
   y = (round(asteroid[i]->getPosY()*1000)/1000);
   mass = (round(asteroid[i]->getMass()*1000)/1000);
   outfile_init << x << " " << y << " " << mass << std::endl;
}
//write planets
for(int i = 0; i < num_planets; ++i){ // for (auto i : planet) {  & we could skip argument 3
  x = (round(planet[i]->getPosX()*1000)/1000);
  y = (round(planet[i]->getPosY()*1000)/1000);
  mass = (round(planet[i]->getMass()*1000)/1000);
  outfile_init << x << " " << y << " " << mass << std::endl;
}
//write laser position
  x = 0.000; // position x of the laser will always be 0
  y = (round(laser*1000)/1000);
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
  for (auto i : asteroid) { // for(int i = 0; i < num_asteroids; ++i){
     x = (round(asteroid[i]->getPosX()*1000)/1000);
     y = (round(asteroid[i]->getPosY()*1000)/1000);
     velX = (round(asteroid[i]->getVelocityX()*1000)/1000);
     velY = (round(asteroid[i]->getVelocityY()*1000)/1000);
     outfile_final << x << " " << y << " " << velX << " " << velY << std::endl;
  }
   //close the file
   outfile_final.close();

}
