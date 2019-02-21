#include <iostream>
using namespace std;


struct Base1 {
	int i=111;
	void print() { cout << i << endl; }
};
struct Derived1: public Base1 {
	char c='a';
	void print() { cout << i << " " << c << endl; }
};
struct Base2 {
	double i=222;
	virtual void print() { cout << i << endl; }
};
struct Derived2: public Base2 {
	char c='b';
	void print() { cout << i << " " << c << endl; }
};


int main()
{	
	{
		double d=12.45;
		int i = (int)d;
		//int j = dynamic_cast<int>(d);  // compile error
		//cout << i << " " << j << endl;

		//double f = dynamic_cast<double>(i); // compile  error: 'double' is not a reference or pointer
		//cout << e << " " << f << endl;

		double* dp = &d;
		//int* jp = dynamic_cast<int*>(dp); // compile error:  'int' is not a class.
		//cout << *ip << " " << endl;        // garbage
	}

	{
		// Dynamic cast with pointers

		Base1* bp1;
		Derived1* dp1;
		Base2* bp2;
		Derived2* dp2;

		bp1 = dynamic_cast<Base1*>(new Derived1);    // OK, like static_cast
		cout << "bp1 = " << bp1 << endl;
		bp1->print();
		//dp1 = dynamic_cast<Derived1*>(new Base1);    // compile error: 'Base1' is not polymorphic
		//cout << "dp1 = " << dp1 << endl;
		//dp1->print();
		bp2 = dynamic_cast<Base2*>(new Derived2);    // OK, like static_cast
		cout << "bp2 = " << bp2 << endl;
		bp2->print();
		dp2 = dynamic_cast<Derived2*>(new Base2);    // OK, returns null
		cout << "dp2 = " << dp2 << endl;
		//dp2->print();   // segmentation fault

		bp1 = dynamic_cast<Base1*>(new Base2);    // OK, returns null
		cout << "bp1 = " << bp1 << endl;
		dp1 = dynamic_cast<Derived1*>(new Base2);    // OK, returns null
		cout << "dp1 = " << dp2 << endl;

		// How to implement instanceof in C++?
		Base2* bp2a = new Derived2;
		Base2* bp2b = new Base2;

		if (Derived2* dp2a = dynamic_cast<Derived2*>(bp2a)) {
			cout << "bp2a points to a Derived2! " << endl;
		} else {
			cout << "bp2a does NOT point to a Derived2! " << endl;
		}
		if (Derived2* dp2b = dynamic_cast<Derived2*>(bp2b)) {
			cout << "bp2b points to a Derived2! " << endl;
		} else {
			cout << "bp2b does NOT point to a Derived2! " << endl;
		}
	}


	/*{
		Base1* bp1a = new Derived1;
		Base1* bp1b = new Base1;

		if (Derived1* dp1a = dynamic_cast<Derived1*>(bp1a)) {
			cout << "bp1a points to a Derived1! " << endl;
		} else {
			cout << "bp1a does NOT point to a Derived1! " << endl;
		}
	}*/

	{
		// Dynamic cast with references

		
		Base1& bp1 = dynamic_cast<Base1&>(*new Derived1);    // OK, like static_cast
		bp1.print();
		// Derived1& dp1 = dynamic_cast<Derived1&>(*new Base1);    // compile error: 'Base1' is not polymorphic
		Base2& bp2 = dynamic_cast<Base2&>(*new Derived2);    // OK, like static_cast
		bp2.print();

		//Derived2& dp2 = dynamic_cast<Derived2&>(*new Base2);    // Runtime error: std::bad_cast
		//dp2.print();

		// bp1 = dynamic_cast<Base1*>(new Base2);    // OK, returns null
		// cout << "bp1 = " << bp1 << endl;
		// dp1 = dynamic_cast<Derived1*>(new Base2);    // OK, returns null
		// cout << "dp1 = " << dp2 << endl;

		// How to implement instanceof in C++?
		Base2& bp2a = *new Derived2;
		Base2& bp2b = *new Base2;

		try {
			Derived2& dp2a = dynamic_cast<Derived2&>(bp2a);
			cout << "bp2a references a Derived2! " << endl;
		} catch (bad_cast e) {
			cout << "bp2a does NOT reference a Derived2! " << endl;
		}
		try {
			Derived2& dp2b = dynamic_cast<Derived2&>(bp2b);
			cout << "bp2b references a Derived2! " << endl;
		} catch (bad_cast e) {
			cout << "bp2b does NOT reference a Derived2! " << endl;
		}
	}
}
