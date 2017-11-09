#include <iostream>
#include <cmath>
#include <random>
#include "Planet.h"
#include "Asteroid.h"
#include "Constants.h"

/******/
double computeDistance(Asteroid a, Body b);

double computeAngleOfInfluence(Asteroid a, Body b);

double* computeAttractionForce(Asteroid a, Body b);

void computeReboundEffect(Asteroid a);

void computePosition(Asteroid a, std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets);

void computeVelocity(Asteroid a, std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets);

double* computeAcceleration(Asteroid a, std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets);
/******/

bool checkParameters(int numberOfParameters, char const *parameters[]);

void generateBodies(std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets, unsigned int seed);

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

    std::vector<Asteroid *> asteroids((unsigned long) num_asteroids);
    std::vector<Planet *> planets((unsigned long) num_planets);

    generateBodies(asteroids, planets, seed);

    for (int i = 0; i < num_iterations; ++i) {
        for (int j = 0; j < num_asteroids; ++j) {
            computePosition(*asteroids[j], asteroids, planets);
            computeReboundEffect(*asteroids[j]);
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

    for (auto &asteroid : asteroids) {
        asteroid = new Asteroid(xdist(re), ydist(re), mdist(re), 0, 0);
    }

    for (auto &planet : planets) {
        planet = new Planet(xdist(re), ydist(re), mdist(re) * 10);
    }

}

/********/
/**
 * This function returns the distance between the @param a and @param b
 * @param a body object
 * @param b body object
 * @return double distance
 */
double computeDistance(Asteroid a, Body b) {
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
 * TODO:
 * @param a
 * @param b
 * @return
 */
double* computeAttractionForce(Asteroid a, Body b) {
    double distance = computeDistance(a, b);
    double alfa = computeAngleOfInfluence(a, b);

    auto* forces = new double[2];

    forces[0] = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * cos(alfa);
    forces[1] = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * sin(alfa);

    /*** THIS IS IMPORTANT ***/
    /* TODO: Apply the force positively for a and negatively for b, an element wont exert force to himself,
     * take care of the case in which the b Body is a planet */

    return forces;
}

/**
 * TODO:
 * @param a
 */
void computeReboundEffect(Asteroid a) {
    double posX = a.getPosX();
    double posY = a.getPosY();

    if (posX <= 0) {
        a.setPosX(posX - 2);
        a.setVelocityX(a.getVelocityX() * -1);

    } else if (posX >= SPACE_WIDTH) {
        a.setPosX(SPACE_WIDTH - 2);
        a.setVelocityX(a.getVelocityX() * -1);

    } else if (posY <= 0) {
        a.setPosY(posY - 2);
        a.setVelocityX(a.getVelocityY() * -1);

    } else if (posY >= SPACE_HEIGHT) {
        a.setPosY(SPACE_HEIGHT - 2);
        a.setVelocityX(a.getVelocityY() * -1);

    } else {
        // The asteroid is not in a border, do nothing
    }
}

void computePosition(Asteroid a, std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets){
    computeVelocity(a, asteroids, planets);

    a.setPosX(a.getPosX() + a.getVelocityX() * TIME_INTERVAL);
    a.setPosY(a.getPosY() + a.getVelocityY() * TIME_INTERVAL);
}

void computeVelocity(Asteroid a, std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets){
    // TODO: compute the acceleration
    double accelerationX = (computeAcceleration(a, asteroids, planets))[0];
    double accelerationY = (computeAcceleration(a, asteroids, planets))[1];

    a.setVelocityX(a.getVelocityX() + accelerationX * TIME_INTERVAL);
    a.setVelocityY(a.getVelocityY() + accelerationY * TIME_INTERVAL);
}

double* computeAcceleration(Asteroid a, std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets){
    auto* accelerations = new double[2];

    for (auto &asteroid : asteroids) {
        // FIXME:
        accelerations[0] += (computeAttractionForce(a, *asteroid))[0] / a.getMass();
    }

    for (auto &planet : planets) {
        // FIXME:
        accelerations[1] += (computeAttractionForce(a, *planet))[1] / a.getMass();
    }

    return accelerations;
}
/********/

