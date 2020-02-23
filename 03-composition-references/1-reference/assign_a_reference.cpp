/**
 * Demonstrates assigning values to references in C++.
 * @author Erel Segal-Halevi
 * @since 2018-02
 */

#include <iostream>
using namespace std;

void test(const int& x) {
    
}

int main() {
    test(1);
    // under the hood:
    // const int& x = 1;

    int* p1;
    //int& r1; // compile error

    const int num = 1, num2 = 999;

    cout << "Pointer:" << endl;
    int* pnum = &num;
    cout << "pnum = " << pnum << " " << *pnum << " " << num << endl;
    (*pnum) = 2;
    cout << "pnum = " << pnum << " " << *pnum << " " << num << endl;
    pnum = &num2;
    cout << "pnum = " << pnum << " " << *pnum << " " << num << endl << endl;

    cout << "Reference:" << endl;
    int& rnum = num;
    cout << "rnum = " << &rnum << " " << rnum << " " << num << endl;
    rnum = 3;     // Here a reference is like a pointer
    cout << "rnum = " << &rnum << " " << rnum << " " << num << endl;
    rnum = num2;  // Here a reference is unlike a pointer
    cout << "rnum = " << &rnum << " " << rnum << " " << num << endl << endl;
    
    // num = 4;
    // cout << "rnum = " << &rnum << " " << rnum << " " << num << endl << endl;

    // References and rvalues:
    //int& rnum2 = 10+num; // error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    //rnum2 = 7;


    cout << "Const Reference:" << endl;
    // const references and rvalues:
    // const int* pnum1 = &10;
    const int& crnum1 = 10;  // unlike a pointer
    // crnum1 = 7;            // error: variable 'crnum1' declared const here

    cout << "crnum1 = " << &crnum1 << " " << crnum1 << endl;

    const int& crnum2 = 10;
    cout << "crnum2 = " << &crnum2 << " " << crnum2 << endl << endl;
}
