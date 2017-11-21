#include <cmath>
#include "Computations.h"
#include "Constants.h"

/**
 * Returns the distance between the @param a and @param b
 * @param a body object
 * @param b body object
 * @return distance
 */
double computeDistance(Asteroid a, Body b) {
    return sqrt(pow((a.getPosX() - b.getPosX()), 2) + pow((a.getPosY() - b.getPosY()), 2));
}

/**
 * Returns the angle of influence between @param a and @param b
 * @param a
 * @param b
 * @return angle of influence
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
 * Returns the attraction force exerted between @param a and @param b
 * @param a
 * @param b
 * @return vector with the two components of the force with [0] being the x axis and [1] being the y axis
 */
std::vector<double> computeAttractionForce(Asteroid &a, Body b) {
    double distance = computeDistance(a, b);
    double alfa = computeAngleOfInfluence(a, b);

    std::vector<double> forces(2);

    forces[0] = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * cos(alfa);
    forces[1] = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * sin(alfa);

    return forces;
}

/**
 * Applies the rebound effect to the @param a once checked if necessary
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

/**
 * Computes the position of the @param a regarding the vector with the Asteroids @param asteroids and
 * the vector with the Planets @param planets
 * @param a
 * @param asteroids
 * @param planets
 */
void computePosition(Asteroid &a, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets) {
    computeVelocity(a, asteroids, planets);

    a.setPosX(a.getPosX() + a.getVelocityX() * TIME_INTERVAL);
    a.setPosY(a.getPosY() + a.getVelocityY() * TIME_INTERVAL);
}

/**
 * Computes the velocity of the @param a regarding the vector with the Asteroids @param asteroids and
 * the vector with the Planets @param planets storing it in @param a fields
 * @param a
 * @param asteroids
 * @param planets
 */
void computeVelocity(Asteroid &a, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets) {
    double accelerationX = (computeAcceleration(a, asteroids, planets))[0];
    double accelerationY = (computeAcceleration(a, asteroids, planets))[1];

    a.setVelocityX(a.getVelocityX() + accelerationX * TIME_INTERVAL);
    a.setVelocityY(a.getVelocityY() + accelerationY * TIME_INTERVAL);
}

/**
 * Computes the acceleration of the @param a regarding the vector with the Asteroids @param asteroids and
 * the vector with the Planets @param planets
 * @param a
 * @param asteroids
 * @param planets
 * @return vector with the two components of the acceleration with [0] being the x axis and [1] being the y axis
 */
std::vector<double>
computeAcceleration(Asteroid &a, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets) {
    std::vector<double> accelerations(2);

    for (auto &asteroid : asteroids) {
        if (computeDistance(a, *asteroid) > MINIMUM_DISTANCE) {
            // CHECK: "Slicing object from type 'Asteroid' to 'Body' discards 16 bytes of state", aun asi parece que no peta
            accelerations[0] += (computeAttractionForce(a, *asteroid))[0] / a.getMass();
            accelerations[1] += (computeAttractionForce(a, *asteroid))[1] / a.getMass();

            // INFO: Apply negatively the force to the other asteroid involved
            /*** THIS IS IMPORTANT ***/
            /* TODO: Apply the force positively for a and negatively for b
             * TODO: take care of the case in which the b Body is a planet */

            asteroid->setVelocityX(asteroid->getVelocityX() + computeAttractionForce(a, *asteroid)[0] * -1 / asteroid->getMass() * TIME_INTERVAL);
            asteroid->setVelocityY(asteroid->getVelocityY() + computeAttractionForce(a, *asteroid)[1] * -1 / asteroid->getMass() * TIME_INTERVAL);
        }
    }

    for (auto &planet : planets) {
        accelerations[0] += (computeAttractionForce(a, *planet))[0] / a.getMass();
        accelerations[1] += (computeAttractionForce(a, *planet))[1] / a.getMass();
    }

    return accelerations;
}
