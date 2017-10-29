#ifndef NASTEROIDS_PLANET_H
#define NASTEROIDS_PLANET_H

#include "Point.h"

class Planet : private Point {
private:
    double m;

public:
    void setM(double y);

    double getM(void);

    Planet(double x, double y, double m) : Point(getX(), getY()) {}

};

#endif //NASTEROIDS_PLANET_H
