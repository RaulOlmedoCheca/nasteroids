#include <iostream>
#include "Planet.h"

void Planet::setPosX(double posX) {
    std::cerr << "Error: the position" << posX << "cannot replace the previous position, planets do not move" << std::endl;
}

void Planet::setPosY(double posY) {
    std::cerr << "Error: the position" << posY << "cannot replace the previous position, planets do not move" << std::endl;

}

/**
 * TODO:
 * @param posX
 * @param posY
 * @param mass
 */
Planet::Planet(double posX, double posY, double mass) : Body(posX, posY, mass) {
    if (posX != 0 || posY != 0) {
        std::cerr << "Error: Planet has no component equal to 0" << std::endl;
    }
}
