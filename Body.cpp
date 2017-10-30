#include <iostream>
#include "Body.h"

/**
 * TODO:
 * @param posX
 */
void Body::setPosX(double posX) {
    this->posX = posX;
}

/**
 * TODO:
 * @param posY
 */
void Body::setPosY(double posY) {
    this->posY = posY;
}

/**
 * TODO:
 * @return
 */
double Body::getPosX() {
    return posX;
}

/**
 * TODO:
 * @return
 */
double Body::getPosY() {
    return posY;
}

/**
 * TODO:
 * @return
 */
double Body::getMass() {
    return mass;
}

/**
 * TODO:
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
 *
 */
Body::~Body() {
    // TODO: implementamos destructores?
}
