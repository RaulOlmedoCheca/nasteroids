#ifndef NASTEROIDS_COMPUTATIONS_H
#define NASTEROIDS_COMPUTATIONS_H

#include "Body.h"
#include "Asteroid.h"

class Computations {

public:

    double computeDistance(Asteroid a, Body b);

    double computeAngleOfInfluence(Asteroid a, Body b);

    double computeAttractionForce(Asteroid a, Body b);

    void computeReboundEffect(Asteroid a);
};

#endif //NASTEROIDS_COMPUTATIONS_H
