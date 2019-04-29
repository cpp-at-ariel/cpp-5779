#include <iostream>
//using namespace std;
using std::cout;
using std::endl;

class Base
{
public:
	void f(bool i) { cout << "f(bool)" << endl; }
};

class Derived: Base {
public:
	void f(int i) { cout << "f(int)" << endl; }
};

class Derived2: Base {
public:
	using Base::f;
	void f(int i) { cout << "f(int)" << endl; }
};

int main()
{	
	Base b;
	b.f(3);    // imperfect match to Base::f
	b.f(true); // perfect match to Base::f
	cout << "---"<<endl;

	Derived d;
	d.f(3);    // perfect match to Derived::f
	d.f(true); // imperfect match to Base::f and Derived::F
	cout << "---"<<endl;

	Derived2 d2;
	d2.f(3);    // perfect match to Derived::f
	d2.f(true); // perfect match to Base::f
	cout << "---"<<endl;
}
