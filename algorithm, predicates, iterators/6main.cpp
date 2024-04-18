#include "6.h"

#include <iostream>
#include <vector>

using std::cin;
using std::cout;


int main() {
    std::vector<int> test1 = {11, 67, 2, 10, 6};
    std::vector<int> test3 = {23, 23, 23, 23};
    cout << any_of(test1.begin(), test1.end(), remainder_five<int>) << "\n";
    cout << any_of(test1.begin(), test1.end(), is_positive<int>) << "\n";
    cout << is_partitioned(test1.begin(), test1.end(), remainder_five<int>) << "\n";
    std::vector<int>::const_iterator i1 = find_not(test1.begin(), test1.end(), compare_normal<int>, 11);
    if (i1 != test1.end()){
        cout << *i1 << "\n";
    }

    std::vector<int>::const_iterator i3 = find_not(test3.begin(), test3.end(), compare_normal<int>, 23);
    if (i3 != test3.end()){
        cout << *i3 << "\n";
    }
    cout << "\n";

    std::vector<Complex<float>> test2 = {Complex<float>(5, 11),
                                         Complex<float>(15, 12),
                                         Complex<float>(5, 11),
                                         Complex<float>(62, 71),
                                         Complex<float>(10, 3)};

    std::vector<Complex<float>> test4 = {Complex<float>(8, 9),Complex<float>(8, 9), Complex<float>(7, 9)};

    cout << any_of(test2.begin(), test2.end(), num_in_pow3_more125<float>) << "\n";
    cout << is_partitioned(test2.begin(), test2.end(), num_in_pow3_more125<float>) << "\n";

    std::vector<Complex<float>>::const_iterator i2 = find_not(test2.begin(), test2.end(), compare_complex<float>, Complex<float>(5, 11));
    if (i2 != test2.end()) {
        cout << *i2;
    }


    std::vector<Complex<float>>::const_iterator i4 = find_not(test4.begin(), test4.end(), compare_complex<float>, Complex<float>(8, 9));
    if (i4 != test4.end()) {
        cout << *i4;
    }

}
