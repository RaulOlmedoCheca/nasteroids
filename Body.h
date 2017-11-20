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

    double getPosX(void);

    double getPosY(void);

    double getMass(void);

    Body(double posX, double posY, double mass);

    ~Body();

};

#endif //NASTEROIDS_POINT_H
