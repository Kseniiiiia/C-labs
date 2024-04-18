#include "4cycle.h"

#include <iostream>

double pi = 3.1415;
Cycle::Cycle() {
    center = CVector2D{0,0};
    radius = 0;
}

Cycle::Cycle(CVector2D &c, double r) {
    center = c;
    radius = r;
}


double Cycle::square() {
    double res = pi* radius *radius;
    return res;
}

double Cycle::perimetr() {
    double res = 2 * pi * radius;
    return res;
}

double Cycle::mass(){
    return square();
}


CVector2D Cycle::position() {
    return  center;
}


bool Cycle::operator==(const IPhysObject &obj) const {
    double one = const_cast<Cycle &>(*this).mass();
    double two = const_cast<Cycle &>(dynamic_cast<const Cycle &>(obj)).mass();

    if (one == two){
        return true;
    }
    else
        return false;
}



bool Cycle::operator<(const IPhysObject &obj) const {
    double one = const_cast<Cycle &>(*this).mass();
    double two = const_cast<Cycle &>(dynamic_cast<const Cycle &>(obj)).mass();

    if (one < two){
        return true;
    }
    else
        return false;
}


void Cycle::draw() {
    std::cout << "Круг " << classname() << std::endl;
    std::cout << "Кординаты центра " <<  std::endl;
    std::cout << center.x << " " << center.y << std::endl;
    std::cout << "Радиус " << radius << std::endl;
}


void Cycle::initFromDialog() {
    double cx, cy, rad;
    std::cout << "Кординаты центра " <<  std::endl;
    std::cin>> cx >> cy;
    std::cout << "Радиус " << std::endl;
    std::cin >> rad;

    center = CVector2D{cx, cy};
    radius = rad;
}

const char* Cycle::classname() {
    return typeid(*this).name();
}

unsigned int Cycle::size() {
    return sizeof(*this);
}
