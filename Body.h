#ifndef NASTEROIDS_POINT_H
#define NASTEROIDS_POINT_H

class Body {

private:
    double posX;
    double posY;
    double mass;

public:

    void virtual setPosX(double posX);

    void virtual setPosY(double posY);

    double getPosX(void);

    double getPosY(void);

    double getMass(void);

    Body(double posX, double posY, double mass);

};

#endif //NASTEROIDS_POINT_H
