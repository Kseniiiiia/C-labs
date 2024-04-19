#ifndef PROGRAMMINGC_3ARRAY_H
#define PROGRAMMINGC_3ARRAY_H

class Array{
private:
    int n;
    int *arr;

public:
    Array();   //  конструктор по умолчанию
    Array(const Array &);  // копирования
    Array(int);  //  констуктор максимальной глубины
    ~Array();  //  деструктор

    Array operator+(Array &);

    bool operator==(Array &);
    bool operator!=(Array &);
    bool operator>(Array &);
    bool operator<(Array &);
    int& operator[](int );

    int getsize();
};
#endif //PROGRAMMINGC_3ARRAY_H
