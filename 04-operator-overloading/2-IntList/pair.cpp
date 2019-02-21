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
    IntList l0 {1000};
    l0 = 99;
    //equivalent to: l0
    // l0.operator=(99);
    cout << "l0[5] = " << l0[5] << endl;
    //equivalent to: 
    //cout << "l0[5] = " << l0.operator[](5) << endl;

    //cout << "l0[first] = " << l0["first"] << endl;

    l0[5] = 11;
    // equivalent to:
    //l0.operator[](5) = 11;

    cout << "l0[5] = " << l0[5] << endl;

    const IntList clist(10);
    cout << "clist[5] = " << clist[5] << endl;

    l0[3] = 123;
    cout << "l0[abc] = " << l0["abc"] << endl;
    return 0;
}
