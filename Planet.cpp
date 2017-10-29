#include "Planet.h"

/**
 *
 * @param y
 */
void Planet::setM(double y) {
    this->m = m;
}

/**
 *
 * @return
 */
double Planet::getM(void) {
    return m;
}

Planet::Planet(double x, double y, double m) : Point(getX(), getY()) {

}
