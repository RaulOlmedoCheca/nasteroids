#ifndef NASTEROIDS_PLANET_H
#define NASTEROIDS_PLANET_H

#include "Body.h"

class Planet : public Body {

public:
    // TODO: override setters to avoid changing the position to a planet

    Planet(double posX, double posY, double mass);

};

#endif //NASTEROIDS_PLANET_H
