#include <iostream>
#include "3array.h"

Array::Array() {
    n = 1;
    arr = new int[n];
    arr[0] = 0;
}

Array::Array(int n) {
    this->n = n;
    arr = new int[n];
    for (int i = 0; i < n; i++){
        arr[i] = 0;
    }
}

Array::Array(const Array &mass) {
    n = mass.n;
    arr = new int[n];
    for (int i = 0; i<n; i++) {
        arr[i] = mass.arr[i];
    }
}

Array::~Array() {
    delete[] arr;
}


int Array::getsize() {
    return n;
}

bool Array::operator==(Array &m) {

    if (getsize() != m.getsize()){
        return false;
    }
    return true;
}



bool Array::operator!=(Array &m) {

    if (getsize() == m.getsize()){
        return false;
    }
    return true;
}


bool Array::operator<(Array &m) {

    if (getsize() >= m.getsize()){
        return false;
    }
    return true;
}


bool Array::operator>(Array &m) {

    if (getsize() <= m.getsize()){
        return false;
    }
    return true;
}

Array Array::operator+(Array& m) {
     Array rezult(getsize() + m.getsize());
     for(int i = 0; i < getsize(); i++ ){
         rezult[i] = arr[i];
     }

     for(int j = getsize(), k = 0; j < (getsize() + m.getsize()); j++, k++){
         rezult[j] = m[k];
     }
    return rezult;
}

int& Array::operator[]( int i) {
    if(i < 0 || i >= getsize())
        exit(1);
    return arr[i];
}