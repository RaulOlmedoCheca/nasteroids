#include <iostream>
#include "Planet.h"

/**
 *
 * @param posX
 * @param posY
 * @param mass
 */
Planet::Planet(double posX, double posY, double mass) : Body(posX, posY, mass) {
    if (posX != 0 && posY != 0) {
        std::cerr << "Error: Planet has no component equal to 0" << std::endl;
    }
}
