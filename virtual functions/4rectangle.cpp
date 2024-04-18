#include "4rectangle.h"
#include <iostream>
#include <cmath>

//конструктор по умолчанию
Rectangle::Rectangle() {
    start = CVector2D{0,0};
    a = CVector2D{0,0};
    b = CVector2D{0, 0};
}

//Конструктор с дпнными векторами
Rectangle::Rectangle(CVector2D &st, CVector2D &x, CVector2D &y) {
    start = st;
    a = x;
    b = y;
}

//Длина стороны
double Rectangle::sidelenght(CVector2D &slen) {
    double len = sqrt(pow(slen.x, 2) + pow(slen.y, 2));
    return len;
}

//Площадь
double Rectangle::square() {
    double res = a.x * b.y;
    return res;
}

//Периметр
double Rectangle::perimetr() {
    double res = 2* (sidelenght(a) + sidelenght(b));
    return res;
}

//масса
double Rectangle::mass() {
    return square();
}

//центр масс
CVector2D Rectangle::position() {
    CVector2D *vec = new CVector2D;
    vec->x = (a.x + b.x)/2 + start.x;
    vec->y = (a.y + b.y)/2 + start.y;
    return *vec;
}


bool Rectangle::operator==(const IPhysObject &obj) const {
    double first = const_cast<Rectangle &>(*this).mass();
    double second = const_cast<Rectangle &>(dynamic_cast<const Rectangle &>(obj)).mass();

    if (first == second){
        return true;
    }
    else{
        return false;
    }
}


bool Rectangle::operator<(const IPhysObject &obj) const {
    double first = const_cast<Rectangle &>(*this).mass();
    double second = const_cast<Rectangle &>(dynamic_cast<const Rectangle &>(obj)).mass();

    if (first < second){
        return true;
    }
    else{
        return false;
    }
}


//Нарисовать
void Rectangle::initFromDialog() {
    double sx, sy, ax, ay, bx, by;
    std::cout << "Введите кординаты векторов прямоугольника" << std::endl;
    std::cout << "Кординаты вектора смещения для стартовой точки " << std::endl;
    std::cin >> sx >> sy;

    std::cout << "Кординаты вектора первой стороны " << std::endl;
    std::cin >> ay;
    ax = 0;
    std::cout << std::endl;

    std::cout << "Кординаты вектора второй стороны " << std::endl;
    std::cin >> bx;
    by = 0;
    std::cout << std::endl;

    start = CVector2D{sx,sy};
    a = CVector2D{ax, ay};
    b = CVector2D{bx, by};
}

const char* Rectangle::classname() {
    return typeid(*this).name();
}

unsigned int Rectangle::size(){
    return sizeof(*this);
}





























