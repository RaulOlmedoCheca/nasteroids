#include <iostream>
#include "Body.h"

/**
 * Sets the x component of the position of the Object
 * @param posX
 */
void Body::setPosX(double posX) {
    this->posX = posX;
}

/**
 * Sets the y component of the position of the Object
 * @param posY
 */
void Body::setPosY(double posY) {
    this->posY = posY;
}

/**
 * Gets the x component of the position of the Object
 * @return
 */
double Body::getPosX() {
    return posX;
}

/**
 * Gets the y component of the position of the Object
 * @return
 */
double Body::getPosY() {
    return posY;
}

/**
 * Gets the mass of the Object
 * @return
 */
double Body::getMass() {
    return mass;
}

/**
 * Creates a Body object (Asteroid or Planet)
 * @param posX
 * @param posY
 * @param mass
 */
Body::Body(double posX, double posY, double mass) {
    if (posX < 0 || posY < 0 || mass < 0) {
        std::cerr << "Error: negative value in one of the fields" << std::endl;
    } else {
        this->posX = posX;
        this->posY = posY;
        this->mass = mass;
    }

}

/**
 * TODO:
 */
Body::~Body() {
    // TODO: implementamos destructores?
}
