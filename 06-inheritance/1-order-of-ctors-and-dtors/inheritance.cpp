#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass() { cout << "MyClass:default\n"; }
	MyClass(int x) { cout << "MyClass::int\n"; }
	~MyClass() { cout << "MyClass dtor\n"; }
};

class OtherClass
{
public:
	OtherClass() { cout << "OtherClass:default\n"; }
	OtherClass(int x) { cout << "OtherClass::int\n"; }
	~OtherClass() { cout << "OtherClass dtor\n"; }
};


class Base
{
public:
	Base() : _vari(0) { cout << "Base::default\n"; }
	Base(int i) : _vari(i) { cout << "Base: int\n"; }
	~Base() { cout << "Base dtor\n"; }
private:
	int _vari;
};

class Derived : public Base
{
public:
	Derived(): _otherObj(), _myObj() { cout << "Derived::default\n"; }
	Derived(int i, int j) : _myObj(0), Base(i), _varj(j) { cout << "Derived:: int int\n"; }
	~Derived() { cout << "---\nDerived dtor\n"; }
private:
	int _varj;
	MyClass _myObj;
	OtherClass _otherObj;
};

int main()
{
	cout << "---" << endl;
	Derived d1;
	cout << "---" << endl;
	Derived d2(6, 8);
	cout << "---" << endl;
}