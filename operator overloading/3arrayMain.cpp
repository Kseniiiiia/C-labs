#include <iostream>
#include "3array.h"
using namespace std;
int main(){

    Array mass(5);
    Array arr(4);
    Array mass_(5);
    Array arr_(4);

    Array res = arr.operator+(mass);
    Array ans = arr_ + mass_;

    for (int i = 0; i < 9; i++){
        cout << ans[i];
    }

    cout << endl;
    for (int i = 0; i < 9; i++){
        cout << res[i];
    }

    cout << endl;
    cout << arr.operator==(mass) << " " << (arr == arr_) << "\n";


}
