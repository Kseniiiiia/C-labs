#include "5Matrix.h"
#include <iostream>

using std::cin;
using std::cout;
int main(){

    Matrix<float, 2, 3> m;
    Matrix<float, 2, 3> m1;
    Matrix<float, 3, 2> m2;

    float x = 5;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            m.set(x, i, j);
            x++;
        }
    }

    float y = 0;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            m1.set(y, i, j);
            y += 10;
        }
    }

    float z = 2;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            m2.set(z, i, j);
        }
    }

    cout << "\nLet's sum matrix m and m1\n";
    Matrix<float, 2, 3> res = m + m1;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            cout << res.get(i, j) << " ";
        }
    }
    cout << "\n";

    cout << "\nLet's multiply matrix m1 and matrix m2\n";
    Matrix<float, 2, 2> res1 = m1 * m2;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << res1.get(i, j) << " ";
        }
    }
    cout << "\n";

    cout << "\nLet's turn to the index [-1][-1] of the matrix m\n";
    try {
        m.get(-1, -1);
    } catch( MyCustomException& e ) {
        cout << e.what() << "\n";
    }

    cout << "Let's try to assign the index [-1][-1] of the matrix m value v\n";
    float v = 6;
    try {
        m.set(v, -1, 0);
    } catch( MyCustomException& s ) {
        cout << s.what() << "\n";
    }

    cout << "Third degree of 5 \n";
    cout << num_degree(5, 3) << "\n";

    cout << "Third degree of 3.14 \n";
    cout << num_degree(3.14, 2) << "\n";
}
