#ifndef PROGRAMMINGC_6MAIN_H
#define PROGRAMMINGC_6MAIN_H
#include <iostream>
#include <ostream>
#include <cmath>
using std::cout;

template <typename T>
class Complex {
private:
    T real;
    T imaginary;
public:
    Complex(T a, T b) {
        real = a;
        imaginary = b;
    };

    T get_real() {
        return real;
    }

    T get_imaginary() {
        return imaginary;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& num){
        os << num.real << " " << num.imaginary << "\n";
        return os;
    };
};


// 2
template <typename T, typename P>
bool any_of(T first, T last, P predicate) {
    for (T i = first; i != last; i++) {
        if (predicate(*i) == true) {
            return true;
        }
    }
    return false;
}


// 6
template <typename T, typename P>
bool is_partitioned(T first, T last, P predicate) {
    //find the first one which doesn't correspond to pred
    for (T i = first; i != last; i++) {
        if (predicate(*i) == false) {
            break;
        }
    }

    if (first == last) {
        return true;
    }

    first++;
    for (T i = first; i != last; i++) {
        if (predicate(*i) == true) {
            return false;
        }
    }
    return true;
}

// 7
template <typename T, typename P, typename V>
T find_not(T begin, T end, P predicate, V value) {
    for (T i = begin; i != end; i++) {
        if (!predicate(*i, value)) {
            return i;
        }
    }
    return end;
}


// Predicates
//gives remainder 5 when divided by 10
template <typename T>
bool remainder_five(T value) {
    if (value % 10 == 5) {
        return true;
    } else {
        return false;
    }
}

//check if the number is positive
template <typename T>
bool is_positive(T value) {
    if (value > 0) {
        return true;
    } else {
        return false;
    }
}

//check if the number to the power of three more than 125
template <typename T>
bool num_in_pow3_more125(Complex<T> num) {
    if (pow(num.get_real() + num.get_imaginary(), 3) > 125) {
        return true;
    } else {
        return false;
    }
}

//comparison predicate for normal numbers
template <typename T>
bool compare_normal(T first, T second) {
    if (first == second) {
        return true;
    } else {
        return false;
    }
}


//comparison predicate for complex numbers
template<typename T>
bool compare_complex(Complex<T> first, Complex<T> second) {
    if (first.get_real() == second.get_real() && first.get_imaginary() == second.get_imaginary()) {
        return true;
    } else {
        return false;
    }
}

#endif //PROGRAMMINGC_6MAIN_H
