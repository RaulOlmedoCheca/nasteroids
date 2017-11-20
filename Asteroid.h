#ifndef NASTEROIDS_ASTEROID_H
#define NASTEROIDS_ASTEROID_H

#include "Body.h"

class Asteroid : public Body {

private:
    double velocityX;
    double velocityY;

public:

    void setVelocityX(double velocityX);

    void setVelocityY(double velocityY);

    double getVelocityX();

    double getVelocityY();

    Asteroid(double posX, double posY, double mass, double velocityX, double velocityY);

};

#endif //NASTEROIDS_ASTEROID_H
