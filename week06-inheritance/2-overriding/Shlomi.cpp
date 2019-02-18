/**
 * Shows that when calling virtual functions from the constructor,
 * the version of the current class is called.
 */

#include <iostream>
using namespace std;

struct Base {
  Base() { f(); }
  virtual void f(){ cout<<"Base"<<endl;}
};
struct Derived: public Base {
  Derived() { f(); }
  virtual void f(){ cout<<"Derived"<<endl;}
};
int main(){
  Derived d; // would print "Base Derived"
}
