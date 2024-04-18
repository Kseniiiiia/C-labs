#ifndef PROGRAMMINGC_4RECTANGLE_H
#define PROGRAMMINGC_4RECTANGLE_H

#include "4geomclasses.h"
class Rectangle: public IFigure{
private:
    CVector2D start{};
    CVector2D a{};
    CVector2D b{};

public:
    Rectangle();
    Rectangle(CVector2D &, CVector2D &, CVector2D &);

    double sidelenght (CVector2D &);
    double square() override;
    double perimetr() override;
    double mass() override;

    CVector2D position() override;

    bool operator==(const IPhysObject &) const override;
    bool operator<(const IPhysObject &) const override;

    void draw() override;
    void initFromDialog() override;
    const char * classname() override;

    unsigned int size() override;
};

#endif //PROGRAMMINGC_4RECTANGLE_H
