#include "Point.hpp"

#include <iostream>
using namespace std;


int main() {
    Point array1[5];
    //sizeof(array1)/sizeof(array1[0]);
    cout << "array1[3] = " << array1[3].to_string() << endl;

    Point array2[5] {1, 2, 3, 4, 5};
    cout << "array2[1] = " << array2[1].to_string() << endl;
    cout << "array2[3] = " << array2[3].to_string() << endl;

    Point array3[5] {{1,2} , {2,3} , {3,4}};
    cout << "array3[1] = " << array3[1].to_string() << endl;
    cout << "array3[3] = " << array3[3].to_string() << endl;

    Point array4[3] { 1 , {2,3} };
    cout << "array4[0] = " << array4[0].to_string() << endl;
    cout << "array4[1] = " << array4[1].to_string() << endl;

    return 0;
}
