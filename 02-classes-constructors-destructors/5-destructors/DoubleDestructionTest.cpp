/**
 * Demonstrates what happens when an object is destructed twice.
 * 
 * @author Erel Segal-Halevi
 * @since  2018-03
 */
#include "units/IntList.hpp"

#include <iostream>
using namespace std;

int main() {
    {
        IntList l0(1000);
        l0.fill(99);
        cout << "l0.get(5) = " << l0.get(5) << endl;
        //l0.~IntList();
    }

    {
        IntList l1(2000);
        l1.fill(999);
        cout << "l1.get(5) = " << l1.get(5) << endl;
        {
            IntList l2 = l1;
            cout << "l2.get(5) = " << l2.get(5) << endl;
        }
        cout << "l1.get(5) = " << l1.get(5) << endl;
    }
    return 0;
}
