#include <cmath>
#include "Computations.h"
#include "Constants.h"

/**
 * This function returns the distance between the @param a and @param b
 * @param a body object
 * @param b body object
 * @return double distance
 */
double Computations::computeDistance(Asteroid a, Body b) {
    return sqrt(pow((a.getPosX() - b.getPosX()), 2) + pow((a.getPosY() - b.getPosY()), 2));
}

/**
 * TODO:
 * @param a
 * @param b
 * @return
 */
double Computations::computeAngleOfInfluence(Asteroid a, Body b) {
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
double Computations::computeAttractionForce(Asteroid a, Body b) {
    double distance = computeDistance(a, b);
    double alfa = computeAngleOfInfluence(a, b);

    double forceInXAxis = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * cos(alfa);
    double forceInYAxis = ((GRAVITY * a.getMass() * b.getMass()) / pow(distance, 2)) * sin(alfa);

    /*** THIS IS IMPORTANT ***/
    /* TODO: Apply the force positively for a and negatively for b, an element wont exert force to himself,
     * take care of the case in which the b Body is a planet */

    return forceInXAxis * forceInYAxis;
}

/**
 * TODO:
 * @param a
 */
void Computations::computeReboundEffect(Asteroid a) {
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