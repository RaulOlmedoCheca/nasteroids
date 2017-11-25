#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <vector>
#include <chrono>
#include <iomanip>
#include "Planet.h"
#include "Asteroid.h"
#include "Constants.h"
#include "Computations.h"
#include "omp.h"

bool checkParametersNumber(int numberOfParameters);

int checkInteger(char const *arg);

double checkDouble(char const *arg);

void generateBodies(std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets, unsigned int seed);

void generateInitFile(int num_asteroids, int num_iterations, int num_planets, double pos_ray, unsigned int seed,
                      std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets);

void generateFinalFile(std::vector<Asteroid *> &asteroids);

void destroyerOfWorlds(double pos, std::vector<Asteroid *> &asteroids);

int main(int argc, char const *argv[]) {

    using clk = std::chrono::high_resolution_clock;
    auto t1 = clk::now();

    // Check input parameters
    if (!checkParametersNumber(argc)) {
        return -1;
    }
    // TODO: if all the parameters are 0 print error showing there's nothing to calculate
    const int num_asteroids = checkInteger(argv[1]);
    const int num_iterations = checkInteger(argv[2]);
    const int num_planets = checkInteger(argv[3]);
    const double pos_ray = checkDouble(argv[4]);
    const auto seed = (unsigned int) checkInteger(argv[5]);

    std::vector<Asteroid *> asteroids((unsigned int) num_asteroids);
    std::vector<Planet *> planets((unsigned int) num_planets);

    omp_set_num_threads(4);

    generateBodies(asteroids, planets, seed);

    generateInitFile(num_asteroids, num_iterations, num_planets, pos_ray, seed, asteroids, planets);


    for (int i = 0; i < num_iterations; ++i) {

        for (int j = 0; j < num_asteroids; ++j) {
            std::vector<std::vector<double> > accelerations((unsigned int) num_asteroids, std::vector<double>(2));
            std::vector<double> forces(2);
//#pragma omp parallel for private(forces)
            for (int k = 0; k < num_asteroids; ++k) {
                if (computeDistance(*asteroids[j], (Body) *asteroids[k]) >= MINIMUM_DISTANCE) {
                    forces = computeAttractionForce(*asteroids[j], (Body) *asteroids[k]);
                    accelerations[j][0] += computeAcceleration(*asteroids[j], forces[0]);
                    accelerations[j][1] += computeAcceleration(*asteroids[j], forces[1]);
                    // Apply force negatively for b
                    accelerations[k][0] += computeAcceleration(*asteroids[k], forces[0] * -1);
                    accelerations[k][1] += computeAcceleration(*asteroids[k], forces[1] * -1);
                }

            }

//#pragma omp parallel for private(forces)
            for (int l = 0; l < num_planets; ++l) {
                forces = computeAttractionForce(*asteroids[j], (Body) *planets[l]);
                accelerations[j][0] += computeAcceleration(*asteroids[j], forces[0]);
                accelerations[j][1] += computeAcceleration(*asteroids[j], forces[1]);
            }

            // INFO: critical section! the functions access mem inside
            computeVelocity(*asteroids[j], accelerations[j]);
            computePosition(*asteroids[j]);
            computeReboundEffect(*asteroids[j]);
            destroyerOfWorlds(pos_ray, asteroids);


        }
    }

    generateFinalFile(asteroids);

    auto t2 = clk::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
    std::cout << "Time = " << diff.count() << "ms" << std::endl;

    return 0;


}

/**
 * This function destroys an asteroid in positionY
 * @param position of the ray int pos
 * @param parameters pointer to the array with the asteroids
 */
void destroyerOfWorlds(double pos, std::vector<Asteroid *> &asteroids) {
    for (unsigned int j = 0; j < asteroids.size(); ++j) {
        if (asteroids[j]->getPosY() < pos + (RAY_WIDTH / 2) && asteroids[j]->getPosY() > pos - (RAY_WIDTH / 2)) {
            asteroids.erase(asteroids.begin() + j);
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
        std::cerr << "seq: Wrong arguments.\nCorrect use:\n"
                  << "seq num_asteroids num_iterations num_planets pos_ray seed" << std::endl;
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
        if (std::stoi(arg) < 0) {
            std::cerr << "seq: Wrong arguments.\nCorrect use:\n"
                      << "seq num_asteroids num_iterations num_planets pos_ray seed" << std::endl;
            std::exit(-1);
        }
        return std::stoi(arg);
    }
    catch (...) {
        std::cerr << "seq: Wrong arguments.\nCorrect use:\n"
                  << "seq num_asteroids num_iterations num_planets pos_ray seed" << std::endl;
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
        if (std::stod(arg) < 0) {
            std::cerr << "seq: Wrong arguments.\nCorrect use:\n"
                      << "seq num_asteroids num_iterations num_planets pos_ray seed" << std::endl;
            std::exit(-1);
        }
        return std::stod(arg);
    }
    catch (...) {
        std::cerr << "seq: Wrong arguments.\nCorrect use:\n"
                  << "seq num_asteroids num_iterations num_planets pos_ray seed" << std::endl;
        std::exit(-1);
    }
}

/**
 * Generate the bodies according to the parameters given as input on the program
 * @param asteroids
 * @param planets
 * @param seed
 */
void generateBodies(std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets, unsigned int seed) {
    // Random distributions
    std::default_random_engine re{seed};
    std::uniform_real_distribution<double> xdist{0.0,
                                                 std::nextafter(SPACE_WIDTH, std::numeric_limits<double>::max())};
    std::uniform_real_distribution<double> ydist{0.0,
                                                 std::nextafter(SPACE_HEIGHT, std::numeric_limits<double>::max())};
    std::normal_distribution<double> mdist{MASS, SD_MASS};


#pragma omp parallel for ordered
    for (unsigned int i = 0; i < asteroids.size(); ++i) {
#pragma omp ordered
        asteroids[i] = new Asteroid(xdist(re), ydist(re), mdist(re), 0, 0);
    }
    int determineAxis = 0;
#pragma omp parallel for ordered
    for (unsigned int j = 0; j < planets.size(); ++j) {
#pragma omp ordered
        switch (determineAxis) {
            case 0:
                planets[j] = new Planet(0, ydist(re), mdist(re) * 10);
                determineAxis++;
                break;
            case 1:
                planets[j] = new Planet(xdist(re), 0, mdist(re) * 10);
                determineAxis++;
                break;
            case 2:
                planets[j] = new Planet(SPACE_WIDTH, ydist(re), mdist(re) * 10);
                determineAxis++;
                break;
            case 3:
                planets[j] = new Planet(xdist(re), SPACE_HEIGHT, mdist(re) * 10);
                determineAxis = 0;
                break;
            default:
                std::cerr << "Something went really wrong" << std::endl;
        }

    }


}

/**
 * TODO:
 * Generate a text file with the initial arguments, as well as the position and mass of the planets, asteroids and ray
 * @param num_asteroids
 * @param num_iterations
 * @param num_planets
 * @param pos_ray
 * @param seed
 * @param asteroids
 * @param planets
 */
void generateInitFile(const int num_asteroids, const int num_iterations, const int num_planets, double pos_ray,
                      const unsigned int seed, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets) {
    //declare the initial variables to use as well as the output file
    double x;
    double y;
    double mass;
    std::ofstream outfile_init("init_conf.txt");
    // Write arguments in the first line of the file
    outfile_init << std::fixed << std::setprecision(3) << num_asteroids << " " << num_iterations << " "
                 << num_planets
                 << " " << pos_ray << " " << seed
                 << std::endl;
    // Write asteroids
    for (int i = 0; i < num_asteroids; ++i) {  // for (auto &asteroid : asteroids) { & we could skip argument 1
        //we will make sure we store 3 decimals in the file by multyplying by 1000, rounding, and dividing by 1000
        x = (round((asteroids[i]->getPosX()) * 1000) / 1000);
        y = (round((asteroids[i]->getPosY()) * 1000) / 1000);
        mass = (round((asteroids[i]->getMass()) * 1000) / 1000);
        //write the data on the file
        outfile_init << std::fixed << std::setprecision(3) << x << " " << y << " " << mass << std::endl;
    }
    // Write planets
    for (int i = 0; i < num_planets; ++i) { // for (auto i : planets) {  & we could skip argument 3
        //we will make sure we store 3 decimals in the file by multyplying by 1000, rounding, and dividing by 1000
        x = (round((planets[i]->getPosX()) * 1000) / 1000);
        y = (round((planets[i]->getPosY()) * 1000) / 1000);
        mass = (round((planets[i]->getMass()) * 1000) / 1000);
        //write the data on the file
        outfile_init << std::fixed << std::setprecision(3) << x << " " << y << " " << mass << std::endl;
    }
    // Write pos_ray position
    x = 0.000; // Position x of the pos_ray will always be 0 (with 3 decimals)
    //we will make sure we store 3 decimals in the file by multyplying by 1000, rounding, and dividing by 1000
    y = (round(pos_ray * 1000) / 1000);
    //write the data on the file
    outfile_init << std::fixed << std::setprecision(3) << x << " " << y << std::endl;

    // Close the file
    outfile_init.close();
}

/**
 * TODO:
 * Generate a text file with the results of our iterations (including positions, velocities and mass) for the asteroids left
 * @param asteroids
 */
void generateFinalFile(std::vector<Asteroid *> &asteroids) {
    //declare the variable we will use as well as the output file
    double x;
    double y;
    double velX;
    double velY;
    double massFinal;
    std::ofstream outfile_final("out.txt");

    // We will go through the asteroids vector and store for each position the position, velocity, and mass
    for (auto &asteroid : asteroids) {
        // In order to get a 3 decimal precision, we will multyply by 1000, round, and then divide by 1000
        x = (round((asteroid->getPosX()) * 1000) / 1000);
        y = (round((asteroid->getPosY()) * 1000) / 1000);
        velX = (round((asteroid->getVelocityX()) * 1000) / 1000);
        velY = (round((asteroid->getVelocityY()) * 1000) / 1000);
        massFinal = (round((asteroid->getMass()) * 1000) / 1000);
        // Then, just write the contents on the final output file
        outfile_final << std::fixed << std::setprecision(3) << x << " " << y << " " << velX << " " << velY << " "
                      << massFinal << std::endl;
    }
    // Close the file
    outfile_final.close();
}
