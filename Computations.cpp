#include <cmath>
#include "Computations.h"
#include "Constants.h"

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
std::vector<double> computeAttractionForce(Asteroid &a, Body b) {
    double distance = computeDistance(a, b);
    double alfa = computeAngleOfInfluence(a, b);

    std::vector<double> forces(2);
    // CHECK: vector forces[i]
    forces[0] = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * cos(alfa);
    forces[1] = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * sin(alfa);

    /*** THIS IS IMPORTANT ***/
    /* TODO: Apply the force positively for a and negatively for b
     * CHECK: an element wont exert force to himself
     * TODO: take care of the case in which the b Body is a planet */

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

/**
 * TODO:
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
 * TODO:
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
 * TODO:
 * @param a
 * @param asteroids
 * @param planets
 * @return
 */
std::vector<double> computeAcceleration(Asteroid &a, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets) {
    std::vector<double> accelerations(2);

    for (auto &asteroid : asteroids) {
        if (computeDistance(a, *asteroid) > MINIMUM_DISTANCE) {
            // CHECK: "Slicing object from type 'Asteroid' to 'Body' discards 16 bytes of state", aun asi parece que no peta
            accelerations[0] += (computeAttractionForce(a, *asteroid))[0] / a.getMass();
            accelerations[1] += (computeAttractionForce(a, *asteroid))[1] / a.getMass();
        }
    }

    for (auto &planet : planets) {
        if (computeDistance(a, *planet) > MINIMUM_DISTANCE) {
            accelerations[0] += (computeAttractionForce(a, *planet))[0] / a.getMass();
            accelerations[1] += (computeAttractionForce(a, *planet))[1] / a.getMass();
        }
    }

    return accelerations;
}
