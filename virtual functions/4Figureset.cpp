#include "4cycle.h"
#include "4rectangle.h"
#include "4Figureset.h"

#include "iostream"
using std::cin;
using std::cout;
using std::endl;


void Figures::addfigure() {
    int f;
    cout << "Какую фигуры добавить? Cycle - 1, Rectangle - 2 " << endl;
    cin >> f;
    while (f != 1 and f!= 2){
        cin >> f;
    }

    if (f == 2){
        Rectangle *obj = new Rectangle;
        obj -> initFromDialog();
        figs.insert(obj);
    }
    else{
        Cycle *obj = new Cycle;
        obj -> initFromDialog();
        figs.insert(obj);
    }
}

void Figures::display() {
    for (auto i : figs){
        i -> draw();
    }
}

double Figures::square_all() {
    double summ = 0;
    for (auto i : figs){
        summ += i -> square();
    }
    return summ;
}


double Figures::perimetr_all() {
    double summ = 0;
    for (auto i : figs){
        summ += i -> perimetr();
    }
    return summ;
}


CVector2D Figures::position_all() {
    CVector2D res{0,0};
    double cx = 0;
    double cy = 0;
    double m = 0;

    for (auto i: figs){
        cx += i -> position().x * i->mass();
        cy += i -> position().y * i->mass();
        m += i -> mass();
    }
    res.x = cx/m;
    res.y = cy/m;
    return res;
}



unsigned int Figures::memory_all() {
    unsigned int ans = 0;
    for (auto i: figs){
        ans += i ->size();
    }
    return ans;
}
