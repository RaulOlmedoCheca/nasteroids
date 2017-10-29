#ifndef NASTEROIDS_POINT_H
#define NASTEROIDS_POINT_H

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

#endif //NASTEROIDS_POINT_H
