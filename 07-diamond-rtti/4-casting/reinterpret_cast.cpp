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
	double d=1.234;
	void print() { cout << d << endl; }
};


int main()
{	
	Base* b11 = new Base;
	Derived* d11 = (Derived*)b11;
	cout << d11->i << " " << d11->c << endl;
	//return 0;
	{
		double d=12.45;
		// int j = reinterpret_cast<int>(d);  // compile error
		// cout << i << " " << j << endl;

		//double f = reinterpret_cast<double>(i);   // compile error
		//cout << e << " " << f << endl;

		double* dp = &d;
		int* ip = (int*)dp;
		int* jp = reinterpret_cast<int*>(dp);
		cout << *ip << " " << *jp << endl;        // garbage garbage

		double& dr = d;
		int& ir = (int&)d;
		int& jr = reinterpret_cast<int&>(d);
		cout << ir << " " << jr << endl;        // garbage garbage
		cout << "---" << endl;
	}

	{
		Base b;
		Derived d;
		//d = reinterpret_cast<Derived>(b); // compile error
		//b = reinterpret_cast<Base>(d); //compile error

		Base* bp;
		Derived* dp;
		Unrelated* up;

		bp = reinterpret_cast<Base*>(new Derived);
		bp->print();  // OK
		bp = reinterpret_cast<Base*>(new Unrelated);
		bp->print();  // garbage

		cout << "---" << endl;

		dp = reinterpret_cast<Derived*>(bp);  //  same garbage
		dp->print();
		dp = reinterpret_cast<Derived*>(new Base);  //  555 garbage
		dp->print();
		dp = reinterpret_cast<Derived*>(new Unrelated);  // garbage
		dp->print();
		cout << "---" << endl;

		up = reinterpret_cast<Unrelated*>(new Base); // garbage
		up->print();
		up = reinterpret_cast<Unrelated*>(new Derived); // garbage
		up->print();
	}
}
