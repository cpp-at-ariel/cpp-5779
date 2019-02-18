/**
 * Demonstrates assigning values to references in C++.
 * @author Erel Segal-Halevi
 * @since 2018-02
 */

#include <iostream>
using namespace std;

int main() {
    int* p1;
    //int& r1; // compile error

    int num = 1;

    // Pointer:
    int* pnum = &num;
    cout << "pnum = " << pnum << " " << *pnum << " " << num << endl;
    (*pnum) = 2;
    cout << "pnum = " << pnum << " " << *pnum << " " << num << endl;

    // Reference:
    int& rnum = num;
    cout << "rnum = " << &rnum << " " << rnum << " " << num << endl;
    rnum = 3;
    cout << "rnum = " << &rnum << " " << rnum << " " << num << endl;

    // References and rvalues:
    //int& rnum2 = 10; // error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    //rnum2 = 7;

    // const references and rvalues:
    const int& crnum1 = 10;
    //crnum1 = 7;          // error: variable 'crnum1' declared const here

    cout << "crnum1 = " << &crnum1 << " " << crnum1 << endl;

    // Segmentation fault:
    int* nullnumptr = nullptr;
    int& nullnumref = *nullnumptr;
    cout << nullnumptr << endl << &nullnumref << endl << (*nullnumptr) << endl << nullnumref << endl; // segmentation fault
}
