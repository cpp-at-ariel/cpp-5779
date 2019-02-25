#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{	
	{
		double d=12.45;
		double& dr = d;
		cout << "typeid(d) = " << typeid(d).name() << endl;
		cout << "typeid(&d) = " << typeid(&d).name() << endl;
		cout << "typeid(dr) = " << typeid(dr).name() << endl;
		int i = (int)d;
		int& ir = i;
		cout << "typeid(i) = " << typeid(i).name() << endl;
		cout << "typeid(&i) = " << typeid(&i).name() << endl;
		cout << "typeid(ir) = " << typeid(ir).name() << endl;
	}

	{
		Base1* bp1 = new Base1;
		cout << "typeid(bp1) = " << typeid(bp1).name() << endl;
		cout << "typeid(*bp1) = " << typeid(*bp1).name() << endl;

		bp1 = new Derived1;
		cout << "typeid(bp1) = " << typeid(bp1).name() << endl;
		cout << "typeid(*bp1) = " << typeid(*bp1).name() << endl;
		
		Base2* bp2 = new Base2;
		cout << "typeid(bp2) = " << typeid(bp2).name() << endl;
		cout << "typeid(*bp2) = " << typeid(*bp2).name() << endl;

		bp2 = new Derived2;
		cout << "typeid(bp2) = " << typeid(bp2).name() << endl;
		cout << "typeid(*bp2) = " << typeid(*bp2).name() << endl;
		
	}
}
