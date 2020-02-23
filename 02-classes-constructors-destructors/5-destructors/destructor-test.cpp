/**
 * Demonstrates what happens when an object is destructed twice.
 * 
 * @author Erel Segal-Halevi
 * @since  2018-03
 */
#include <iostream>
using namespace std;

struct Test {
    int x;
    Test(int x): x(x) {cout<<"c "<<x<< endl;}
    ~Test() {cout<<"d "<<x << endl;}
};

Test f () {
    return Test(99);    
}

void g (Test t) {
}

Test& h() {
    Test t(88);
    return t;
}


int main() {
    cout << "1" << endl;
    //Test list0(5);
    Test* plist = new Test(1000);
    cout << "2" << endl; 
    Test t(555);
    t = f();
    cout << "3" << endl; 
    g(Test(67));
    cout << "4" << endl;
    cout << h().x << endl;
    delete plist;
}
