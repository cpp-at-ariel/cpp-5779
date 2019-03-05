/**
 * Demonstrates when destructors are called.
 * 
 * @author Erel Segal-Halevi
 * @since  2018-03
 */
#include "units/IntList.hpp"

#include <iostream>
using namespace std;

int main() {
    cout << "{" << endl;
    {
        IntList l(1000);
        l.fill(99);
        cout << "l.get(0) = " << l.get(0) << endl;
    }
    // cout << "l.get(0) = " << l.get(0) << endl;  // l is undefined  here
    cout << "}" << endl;

    cout << "before if" << endl;
    if (3>2) 
        IntList l(1000);
    cout << "after if" << endl;


    cout << "{" << endl;
    IntList* p;
    {
        IntList l(1000);
        l.fill(99);
        cout << "l.get(5) = " << l.get(5) << endl;
        // p = &l;
        p = new IntList(999);
        p->fill(88);
        cout << "p->get(5) = " << p->get(5) << endl;
    }
    cout << "}" << endl;
    cout << "p->get(5) = " << p->get(5) << endl;  // Segmentation fault
    delete p;
    cout << "after delete" << endl;
    return 0;
}
