/**
 * Hard output question.
 * Author: Ofir Pele.
 * Since: 2017
 */

#include <iostream>
using namespace std;

class A {
public:
	A() { cout << "A1" << endl; }
	A(const A& a) { cout << "A2" << endl; }
	~A() { cout << "A3" << endl; }

	virtual void f() { cout << "A4" << endl; }
	virtual void g() { h(); cout << "A5" << endl; }
	void h() { cout << "A6" << endl; }
};

class B : public A {
public:
	A a;

	B() { cout << "B1" << endl; }
	B(const B& b) { cout << "B2" << endl; }
	virtual ~B() { cout << "B3" << endl; }

	void f() { cout << "B4" << endl; }
	void h() { cout << "B5" << endl; }
	virtual void i() { cout << "B6" << endl; }
};

class C : public B {
public:
	B b;

	C() { cout << "C1" << endl; }
	~C() { cout << "C2" << endl; }

	void f() { cout << "C3" << endl; }
	virtual void h() { cout << "C4" << endl; }
	virtual void i() { cout << "C5" << endl; }
	B j() { cout << "C6" << endl; return b; }
};

int main() {
	//--Part A.1
	A *ptrAtoB = new B();
	cout << "---------------\n";
	//--Part A.2
	B *ptrBtoC = new C();
	cout << "---------------\n";

	//--Part B.1
	ptrAtoB->h();
	cout << "---------------\n";
	//--Part B.2
	ptrBtoC->h();
	cout << "---------------\n";

	//--Part C.1
	ptrAtoB->f();
	cout << "---------------\n";
	//--Part C.2
	ptrBtoC->f();
	cout << "---------------\n";

	//--Part D 
	ptrAtoB->g();
	cout << "---------------\n";

	//--Part E
	C *c = dynamic_cast<C*>(ptrBtoC);
	c->j();
	cout << "---------------\n";

	//--Part F.1
	delete ptrBtoC;
	cout << "---------------\n";
	//--Part F.2
	delete ptrAtoB;
	cout << "---------------\n";

	return 0;
}

