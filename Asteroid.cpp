#include "Asteroid.h"

/**
 *
 * @param velocity
 */
void Asteroid::setVelocity(double velocity) {
    this->velocity = velocity;
}

/**
 *
 * @return
 */
double Asteroid::getVelocity() {
    return velocity;
}

/**
 *
 * @param posX
 * @param posY
 * @param mass
 * @param velocity
 */
Asteroid::Asteroid(double posX, double posY, double mass, double velocity) : Body(posX, posY, mass) {
    this->velocity = velocity;
}
