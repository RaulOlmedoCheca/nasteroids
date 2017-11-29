#include <cmath>
#include "Computations.h"
#include "Constants.h"

/**
 * Calculates the distance between an Asteroid and a Body (either a Planet or another Asteroid)
 * @param Asteroid a
 * @param Body b
 * @return double with the module of the distance
 */
double computeDistance(Asteroid a, Body b) {
    return sqrt(pow((a.getPosX() - b.getPosX()), 2) + pow((a.getPosY() - b.getPosY()), 2));
}

/**
 * This method computes the angle of influence between an Asteroid and a Body (either an Asteroid or a Body)
 * by computing the slope and then applying the arctangent to it.
 * @param Asteroid a
 * @param Body b
 * @return double with the angle of influence of the two bodies
 */
double computeAngleOfInfluence(Asteroid a, Body b) {
    double slope = (a.getPosY() - b.getPosY()) / (a.getPosX() - b.getPosX());
    if (std::isinf(slope)) {
        return atan(slope);
    }
    if (slope < -1 || slope > 1) {
        slope = slope - trunc(slope);
    }
    return atan(slope);
}

/**
 * This methods calculates the attraction force exerted between an Asteroid and
 * a Body (either a Planet or an Asteroid)
 * @param Asteroid a
 * @param Body b
 * @return
 */
std::vector<double> computeAttractionForce(Asteroid a, Body b) {
    double distance = computeDistance(a, b);
    double alfa = computeAngleOfInfluence(a, b);

    std::vector<double> forces(2);

    forces[0] = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * cos(alfa);
    forces[1] = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * sin(alfa);

    if (forces[0] > MAXIMUM_FORCE) {
        forces[0] = MAXIMUM_FORCE;
    }
    if (forces[1] > MAXIMUM_FORCE) {
        forces[1] = MAXIMUM_FORCE;
    }

    return forces;
}

/**
 * This method checks if the Asteroid is out of bounds with respect to the size
 * of the map and changes its position and velocity according to it
 * @param Asteroid a (passed by reference)
 */
void computeReboundEffect(Asteroid &a) {
    double posX = a.getPosX();
    double posY = a.getPosY();

    if (posX <= 0) {
        a.setPosX(2);
        a.setVelocityX(a.getVelocityX() * -1);
    }
    if (posX >= SPACE_WIDTH) {
        a.setPosX(SPACE_WIDTH - 2);
        a.setVelocityX(a.getVelocityX() * -1);
    }
    if (posY <= 0) {
        a.setPosY(2);
        a.setVelocityX(a.getVelocityY() * -1);
    }
    if (posY >= SPACE_HEIGHT) {
        a.setPosY(SPACE_HEIGHT - 2);
        a.setVelocityX(a.getVelocityY() * -1);
    }
}

/**
 * Computes the position of the @param a regarding the vector with the Asteroids @param asteroids and
 * the vector with the Planets @param planets
 * @param a
 * @param asteroids
 * @param planets
 */
void computePosition(Asteroid &a) {
    a.setPosX(a.getPosX() + a.getVelocityX() * TIME_INTERVAL);
    a.setPosY(a.getPosY() + a.getVelocityY() * TIME_INTERVAL);
}

/**
 * This method calculates the velocity based on the vector with the accelerations passed to it
 * @param Asteroid a
 * @param Vector accelerations containing the two components of
 * the acceleration ([0] for x axis, [1] for y axis)
 */
void computeVelocity(Asteroid &a, std::vector<double> accelerations) {
    a.setVelocityX(a.getVelocityX() + accelerations[0] * TIME_INTERVAL);
    a.setVelocityY(a.getVelocityY() + accelerations[1] * TIME_INTERVAL);
}

/**
 * This function computes the acceleration of the Asteroid using the value of the force exerted to it
 * @param Asteroid a
 * @param Vector force with the two components of the forces exerted to it ([0] for x axis, [1] for y axis)
 * @return
 */
double computeAcceleration(Asteroid a, double force) {
    return force / a.getMass();
}
