#include <iostream>
#include <math.h>

#define GRAVITY 6.674e-5;
#define TIME_INTERVAL 0.1;
#define MINIMUM_DISTANCE 2.0;
#define SPACE_WIDTH 200;
#define SPACE_HEIGHT 200;
#define RAY_WIDTH 4;
#define MASS 1000;
#define SD_MASS 50

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

void Point::setX(double x) {
  this->x = x;
}

void Point::setY(double y) {
  this->y = y;
}

double Point::getX(void) {
  return x;
}

double Point::getY(void) {
  return y;
}

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

double distance(Point a, Point b);

int main(int argc, char const *argv[]) {
  using namespace std;

  return 0;
}

double distance(Point a, Point b) {
  return Math.sqrt(pow((a.x - b.x),2) + pow((a.y - b.y),2));
}
