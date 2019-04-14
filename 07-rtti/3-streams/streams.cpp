#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <thread>
#include <chrono>

using namespace std;

struct Complex {
	double re, im;

	Complex(double re, double im): re(re), im(im) {}
};

ostream& operator<< (ostream& os, const Complex& c) {
	os << c.re << "+" << c.im << "i";
	return os;
}

istream& operator>> (istream& is, Complex& c) {
	char d;
	is >> c.re >> d >> c.im >> d;
	return is;
}

string to_string(const Complex& c) {
	ostringstream s;
	s << c;
	return s.str();
}

int main() {
	// cout << "The result is 2 " << endl;
	// cerr << "There is a bug ";
	// clog << "There is a log ";
	// this_thread::sleep_for(chrono::seconds(3));
	// return 0;

	ostringstream sout;
	Complex c{2,3};
	sout << 1 << " " << c << " ";
	assert(sout.str().compare("1 2+3i ")==0);
	cout << sout.str() << endl;

	ofstream fout("abc.txt");
	fout << 1 << " " << c << endl;

	ifstream fin("abc.txt");
	int k1;
	Complex c1{0,0};
	fin >> k1 >> c1;
	cout << " k1=" << k1 << " c1=" << c1 <<endl; 


	stringstream sinout("12 aa bcd");
	int i, j; string a; 
	sinout >> i >> a >> j;
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
