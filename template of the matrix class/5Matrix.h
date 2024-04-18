#ifndef PROGRAMMINGC_5MATRIX_H
#define PROGRAMMINGC_5MATRIX_H
#include <ostream>
#include <stdexcept>
#include <iostream>

using std::cout;

class MyCustomException : public std::exception{
public:
    const char * what() const noexcept override{
        return "Invalid matrix index";
    }
};

template <class T, size_t n, size_t m>
class Matrix{
private:
    T arr[n][m];

public:
    Matrix(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                arr[i][j] = 0;
            }
        }
    };

    Matrix<T,n,n> operator*(const Matrix<T,m,n> &);
    Matrix<T,n,m> operator*(T);
    Matrix<T,n,m> operator+(const Matrix<T,n,m> &);
    Matrix<T,n,m> operator-(const Matrix<T,n,m> &);

    bool operator==(Matrix<T,n,m> &);
    bool operator!=(Matrix<T,n,m> &);


    T get( int i, int j ) const{
        if ( i < 0 || j < 0 ||  i > n - 1 || j > m - 1) {
            throw MyCustomException();
        }
        return arr[i][j];
    }

    void set( T & v, int i, int j ) {
        if (i < 0 || j < 0 || i > n - 1 || j > m - 1) {
            throw MyCustomException();
        }
        arr[i][j] = v;
    }

};

template<class T, size_t n, size_t m>
Matrix<T,n,n> Matrix<T, n, m>::operator*(const Matrix<T,m,n> &matrix) {
    Matrix<T,n,n> result;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                T r = result.get(i,j)+arr[i][k]*matrix.get(k, j);
                result.set(r, i, j);
            }
        }
    }
    return result;

}
template<class T, size_t n, size_t m>
Matrix<T,n,m> Matrix<T, n, m>::operator+(const Matrix<T,n,m> &matrix) {
    Matrix<T,n,m> result;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            result.arr[i][j] = arr[i][j] + matrix.arr[i][j];
        }
    }
    return result;
}

template<class T, size_t n, size_t m>
Matrix<T,n,m> Matrix<T, n, m>::operator-(const Matrix<T,n,m> &matrix) {
    Matrix<T,n,m> result;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            result.arr[i][j] = arr[i][j] - matrix.arr[i][j];
        }
    }
    return result;
}


template<class T, size_t n, size_t m>
Matrix<T,n,m> Matrix<T, n, m>::operator*(T q) {
    Matrix<T,n,m> result;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            result.arr[i][j] = arr[i][j] * q;
        }
    }
    return result;
}


template<class T, size_t n, size_t m>
bool Matrix<T, n, m>::operator==(Matrix<T,n,m> &matrix) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != matrix.arr[i][j]){
                return false;
            }
        }
    }
    return true;
}

template<class T, size_t n, size_t m>
bool Matrix<T, n, m>::operator!=(Matrix<T,n,m> &matrix) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != matrix.arr[i][j]){
                return true;
            }
        }
    }
    return false;
}


template<typename T>
T num_degree(T num, int n) {
    T result = 1;
    for (int i = 0; i < n; ++i) {
        result *= num;
    }
    return result;
}

#endif //PROGRAMMINGC_5MATRIX_H
