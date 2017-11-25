#ifndef NASTEROIDS_PLANET_H
#define NASTEROIDS_PLANET_H

#include "Body.h"

class Planet : public Body {

public:

    void setPosX(double posX) override;

    void setPosY(double posY) override;

    Planet(double posX, double posY, double mass);

};

#endif //NASTEROIDS_PLANET_H
