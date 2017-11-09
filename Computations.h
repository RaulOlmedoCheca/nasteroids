#ifndef NASTEROIDS_COMPUTATIONS_H
#define NASTEROIDS_COMPUTATIONS_H

#include "Body.h"
#include "Asteroid.h"
#include "Planet.h"

struct Computations {

public:

    double computeDistance(Asteroid a, Body b);

    double computeAngleOfInfluence(Asteroid a, Body b);

    double* computeAttractionForce(Asteroid a, Body b);

    void computeReboundEffect(Asteroid a);

    void computePosition(Asteroid a, std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets);

    void computeVelocity(Asteroid a, std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets);

    double* computeAcceleration(Asteroid a, std::vector<Asteroid *>& asteroids, std::vector<Planet *>& planets);
};

#endif //NASTEROIDS_COMPUTATIONS_H
