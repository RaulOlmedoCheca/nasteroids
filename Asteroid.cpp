#include "Asteroid.h"
#include <iostream>

/**
 * TODO:
 * @param velocityX
 */
void Asteroid::setVelocityX(double velocityX) {
    this->velocityX = velocityX;
}

/**
 * TODO:
 * @param velocityY
 */
void Asteroid::setVelocityY(double velocityY) {
    this->velocityY = velocityY;
}

/**
 * TODO:
 * @return
 */
double Asteroid::getVelocityX() {
    return velocityX;
}

/**
 * TODO:
 * @return
 */
double Asteroid::getVelocityY() {
    return velocityY;
}

/**
 * TODO:
 * @param posX
 * @param posY
 * @param mass
 * @param velocity
 */
Asteroid::Asteroid(double posX, double posY, double mass, double velocityX, double velocityY) : Body(posX, posY, mass) {
    this->velocityX = velocityX;
    this->velocityY = velocityY;
}

//Asteroid::~Asteroid(){std::cout << "Asteroid destroyed by THE MOTHERFUCKING LASER UUUUUUUUUUUUUUUU" << std::endl;}
