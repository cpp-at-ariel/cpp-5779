/**
 * Demonstrates what happens when an object is destructed twice.
 * 
 * @author Erel Segal-Halevi
 * @since  2018-03
 */
#include "units/IntList.hpp"

#include <iostream>
using namespace std;

struct Test {
    Test(int x) {cout<<"c"<<endl;}
    ~Test() {cout<<"d"<<endl;}
};

int main() {
    cout << "1" << endl;
    //Test list0(5);
    Test* plist = new Test(1000);
    cout << "2" << endl; 
    delete plist;
}
