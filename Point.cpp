#include "Point.h"

/**
 * Sets the horizontal component of the point
 * @param x horizontal component
 */
void Point::setX(double x) {
    this->x = x;
}

/**
 * Sets the vertical component of the point
 * @param y vertical component
 */
void Point::setY(double y) {
    this->y = y;
}

/**
 * Returns the horizontal component of the point
 * @return x
 */
double Point::getX(void) {
    return x;
}

/**
 * Returns the vertical component of the point
 * @return y
 */
double Point::getY(void) {
    return y;
}

/**
 * This constructor generates a Point object from two points of the space
 * @param x horizontal component
 * @param y vertical component
 */
Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}