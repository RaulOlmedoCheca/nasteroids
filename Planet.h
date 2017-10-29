#ifndef NASTEROIDS_PLANET_H
#define NASTEROIDS_PLANET_H

#include "Body.h"

class Planet : public Body {
private:

public:

    Planet(double posX, double posY, double mass) : Body(getPosX(), getPosY(), getMass()) {}

};

#endif //NASTEROIDS_PLANET_H
