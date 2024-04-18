#ifndef PROGRAMMINGC_4FIGURESET_H
#define PROGRAMMINGC_4FIGURESET_H

#include "4cycle.h"
#include "4rectangle.h"

#include <set>

using std::set;
class Figures{
private:
    set<IFigure *> figs;
public:
    void addfigure();
    void display();
    double square_all();
    double perimetr_all();
    CVector2D position_all();
    unsigned int memory_all();
};

#endif //PROGRAMMINGC_4FIGURESET_H
