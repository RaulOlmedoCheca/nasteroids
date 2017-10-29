#include <iostream>
#include <cmath>
#include "Point.h"

#define GRAVITY 6.674e-5;
#define TIME_INTERVAL 0.1;
#define MINIMUM_DISTANCE 2.0;
#define SPACE_WIDTH 200;
#define SPACE_HEIGHT 200;
#define RAY_WIDTH 4;
#define MASS 1000;
#define SD_MASS 50

// INFO: The Point class is implemented in C, maybe we could reuse it

double distance(Point a, Point b);

int main(/*int argc, char const *argv[]*/) {
    using namespace std;

    return 0;
}

/**
 * This function returns the distance between the @param a and @param b
 * @param a point object
 * @param b point object
 * @return double
 */
double distance(Point a, Point b) {
    return sqrt(pow((a.getX() - b.getX()), 2) + pow((a.getY() - b.getY()), 2));
}
