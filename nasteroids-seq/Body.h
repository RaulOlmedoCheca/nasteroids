#ifndef NASTEROIDS_POINT_H
#define NASTEROIDS_POINT_H

class Body {

private:
    double posX;
    double posY;
    double mass;

public:

    virtual void setPosX(double posX);

    virtual void setPosY(double posY);

    double getPosX();

    double getPosY();

    double getMass();

    Body(double posX, double posY, double mass);

};

#endif //NASTEROIDS_POINT_H
