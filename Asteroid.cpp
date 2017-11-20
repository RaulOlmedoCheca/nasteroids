#include "Asteroid.h"

/**
 * Sets the x component of the velocity of the Asteroid object
 * @param velocityX
 */
void Asteroid::setVelocityX(double velocityX) {
    this->velocityX = velocityX;
}

/**
 * Sets the y component of the velocity of the Asteroid object
 * @param velocityY
 */
void Asteroid::setVelocityY(double velocityY) {
    this->velocityY = velocityY;
}

/**
 * Gets the x component of the velocity of the Asteroid object
 * @return
 */
double Asteroid::getVelocityX() {
    return velocityX;
}

/**
 * Gets the y component of the velocity of the Asteroid object
 * @return
 */
double Asteroid::getVelocityY() {
    return velocityY;
}

/**
 * Creates an Asteroid object
 * @param posX
 * @param posY
 * @param mass
 * @param velocity
 */
Asteroid::Asteroid(double posX, double posY, double mass, double velocityX, double velocityY) : Body(posX, posY, mass) {
    this->velocityX = velocityX;
    this->velocityY = velocityY;
}
