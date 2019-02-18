#include "units/Point.hpp"
#include "units/Line.hpp"
#include <iostream>
using namespace std;


int main() {
    Point p1;
    Line l1;
    cout << "l1=" << l1.to_string() << endl;
    l1.set(1,2,3,4);
    cout << "l1=" << l1.to_string() << endl;
    Line l2(5,6,7,8);
    cout << "l2=" << l2.to_string() << endl;
    return 0;
}
