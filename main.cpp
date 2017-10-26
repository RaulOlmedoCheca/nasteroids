#include <iostream>
#include <cmath>

#define GRAVITY 6.674e-5;
#define TIME_INTERVAL 0.1;
#define MINIMUM_DISTANCE 2.0;
#define SPACE_WIDTH 200;
#define SPACE_HEIGHT 200;
#define RAY_WIDTH 4;
#define MASS 1000;
#define SD_MASS 50

// INFO: The Point class is implemented in C, maybe we could reuse it
class Point {
private:
    double x;
    double y;

public:
    void setX(double x);

    void setY(double y);

    double getX(void);

    double getY(void);

    Point(double x, double y);
};

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


double distance(Point a, Point b);

int main(int argc, char const *argv[]) {
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
