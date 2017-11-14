#include <iostream>
#include "Planet.h"
#include "Constants.h"

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
    //TODO: hacer una comprobacion buena aqui
    if ((posX != 0 && posX != SPACE_WIDTH) && (posY != 0 && posY != SPACE_HEIGHT)) {
        std::cerr << "Error: Planet has no component equal to 0" << std::endl;
    }
}
