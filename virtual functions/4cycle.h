#ifndef PROGRAMMINGC_4CYCLE_H
#define PROGRAMMINGC_4CYCLE_H

#include "4geomclasses.h"
class Cycle: public IFigure{
private:
    CVector2D center{};
    double radius;

public:
    Cycle();
    Cycle(CVector2D &, double );

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

#endif //PROGRAMMINGC_4CYCLE_H
