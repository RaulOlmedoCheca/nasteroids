#include "Planet.h"

Planet::Planet(double posX, double posY, double mass) : Body(posX, posY, mass) {
    setPosX(posX);
    setPosY(posY);
}

