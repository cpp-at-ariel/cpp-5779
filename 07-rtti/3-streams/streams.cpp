#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
using namespace std;

struct Complex {
	double re, im;

	Complex(double re, double im): re(re), im(im) {}
};

ostream& operator<< (ostream& os, const Complex& c) {
	os << c.re << "+" << c.im << "i";
	return os;
}

string to_string(const Complex& c) {
	ostringstream s;
	s << c;
	return s.str();
}

int main() {
	// cout << "The result is 2" << endl;
	// cerr << "There is a bug" << endl;

	ostringstream sout;
	Complex c{2,3};
	sout << 1 << " " << c << " ";
	assert(sout.str().compare("1 2+3i ")==0);
	cout << sout.str() << endl;
	ofstream fout("abc.txt");
	fout << 1 << " " << c << endl;

	stringstream sinout("12 aa bcd");
	int i, j; string a; 
	sinout >> i >> a;
	cout << (sinout? "good": "bad") << endl;
	cout << (!sinout? "bad": "good") << endl;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
	cout << "a = " << a << endl;
	cout << sinout.str() << endl;
	sinout << "efg";
	cout << sinout.str() << endl;

	stringstream s3("12 a, bcd\n34 b def\n56 C DFE");
	char buffer[200];
	s3.getline(buffer, 200);
	//cin.getline(buffer, 200, ',');
	cout << "first line is " << buffer << endl;
//	cout << "line1 = " << line1 << endl;

	return 0;
}
