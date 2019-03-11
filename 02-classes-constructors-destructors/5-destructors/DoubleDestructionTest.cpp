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
        IntList list0(1000);
        list0.fill(99);
        cout << "l0.get(5) = " << list0.get(5) << endl;
        // list0.~IntList();
    }

    {
        IntList l1(2000);
        l1.print();
        l1.fill(999);
        cout << "l1.get(5) = " << l1.get(5) << endl;
        {
            IntList l2 = l1;
            l2.print();
            cout << "l2.get(5) = " << l2.get(5) << endl;
        }
        cout << "l1.get(5) = " << l1.get(5) << endl;
        l1.print();
    }
    return 0;
}
