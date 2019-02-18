#include <iostream>
using namespace std;


struct Base {
	int i=555;
	void print() { cout << i << endl; }
};

struct Derived: public Base {
	char c='a';
	void print() { cout << i << " " << c << endl; }
};

struct Unrelated {
	double d=666.0;
	void print() { cout << d << endl; }
};


int main()
{	
	{
		double d=12.45;
		int i = (int)d;
		int j = static_cast<int>(d);
		cout << i << " " << j << endl;

		double e = (double)i;
		double f = static_cast<double>(i);
		cout << e << " " << f << endl;

		double* dp = &d;
		int* ip = (int*)dp;
		//int* jp = static_cast<int*>(dp); // compiler error: "static_cast from 'double *' to 'int *' is not allowed"
		cout << *ip << " " << endl;        // garbage
	}

	{
		Base b;
		Derived d;
		//d = static_cast<Derived>(b); // compile error
		b = static_cast<Base>(d); // OK

		Base* bp;
		Derived* dp;
		Unrelated* up;

		bp = static_cast<Base*>(new Derived);
		//bp = static_cast<Base*>(new Unrelated);  // compile error
		bp->print();

		dp = static_cast<Derived*>(bp);  //  OK
		dp->print();
		dp = static_cast<Derived*>(new Base);  //  Garbage
		dp->print();
		//dp = static_cast<Derived*>(new Unrelated);  // compile error

		//up = static_cast<Unrelated*>(new Base); // compile error
		//up = static_cast<Unrelated*>(new Derived); // compile error
	}
}
