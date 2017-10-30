#ifndef NASTEROIDS_ASTEROID_H
#define NASTEROIDS_ASTEROID_H

#include "Body.h"

class Asteroid : public Body {

private:
    double velocity;

public:

    void setVelocity(double velocity);

    double getVelocity();

    Asteroid(double posX, double posY, double mass, double velocity);

};

#endif //NASTEROIDS_ASTEROID_H
