#ifndef NASTEROIDS_COMPUTATIONS_H
#define NASTEROIDS_COMPUTATIONS_H

#include <vector>
#include "Asteroid.h"
#include "Planet.h"

double computeDistance(Asteroid a, Body b);

double computeAngleOfInfluence(Asteroid a, Body b);

std::vector<double> computeAttractionForce(Asteroid &a, Body b);

void computeReboundEffect(Asteroid a);

void computePosition(Asteroid &a, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets);

void computeVelocity(Asteroid &a, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets);

std::vector<double> computeAcceleration(Asteroid &a, std::vector<Asteroid *> &asteroids, std::vector<Planet *> &planets);

#endif //NASTEROIDS_COMPUTATIONS_H
