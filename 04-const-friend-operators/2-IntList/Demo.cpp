/**
 * Demonstrates assignment and brackets operators.
 * 
 * @author Erel Segal-Halevi
 * @since  2018-04
 */
#include "units/IntList.hpp"

#include <iostream>
using namespace std;

int main() {
    IntList list0 {1000};
    list0 = 99;
    //equivalent to: list0
    // list0.operator=(99);
    cout << "list0[5] = " << list0[5] << endl;
    //equivalent to: 
    //cout << "list0[5] = " << list0.operator[](5) << endl;

    //cout << "list0[first] = " << list0["first"] << endl;

    list0[5] = 11;
    // equivalent to:
    //list0.operator[](5) = 11;

    cout << "list0[5] = " << list0[5] << endl;

    const IntList clist(10);
    cout << "clist[5] = " << clist[5] << endl;

    list0[0] = 123;
    list0[999] = 456;
    cout << "list0[first] = " << list0["first"] << endl;
    cout << "list0[last] = " << list0["last"] << endl;

    return 0;
}
