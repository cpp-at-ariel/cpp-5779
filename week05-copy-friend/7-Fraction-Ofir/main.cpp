/**
 * Demo of the Fraction class.
 * 
 * @author Ofir Pele
 * @since 2017
 */

#include<iostream>
#include<math.h>
#include "Fraction.h"

using namespace std;

int main()
{
	Fraction f1(3, 2), f2(4,1), f3(0,1); 	//declare 3 fractions	
									//print the fractions:	
	cout << endl << "fraction f1 is:" << f1 << endl;
	cout << "Fraction f2 is: " << f2 << endl;
	cout << "Fraction f3 is: " << f3 << endl;

	double d1 = f1, d2 = f2, d3 = f3;
	cout << endl << "fraction d1 is:" << d1 << endl;
	cout << "Fraction d2 is: " << d2 << endl;
	cout << "Fraction d3 is: " << d3 << endl;
	cout << "f1 + d1 = " << (f1 + 2) << endl;

	Fraction f4(4, 9);
	cout << endl << "the sqrt of " << f4 << " is: " << sqrt(f4)  << endl;


	//initialize the fractions from user:
	cout << "Enter fraction please:  ";
	cin >> f1;
	cout << "Fraction f1 is: " << f1 << endl;
	cout << "And another one: ";
	cin >> f2;

	//manipulate the operators:
	cout << "Fraction f2 is: " << f2 << endl;
	cout << "f1+f2 is: " << (f1 + f2) << endl;
	cout << "f1-f2 is: " << (f1 - f2) << endl;
	cout << "f1*f2 is: " << (f1*f2) << endl;
	cout << "f1/f2 is: " << (f1 / f2) << endl;
	cout << "f1*f1+2*f1*f2+f2*f2 is:" << (f1*f1 + 2 * f1*f2 + f2*f2) << endl;
	cout << "first is: " << f1 << endl;
	cout << "++first is: " << ++f1 << endl;
	cout << "first++ is: " << f1++ << endl;
	cout << "first is: " << f1;

	return 0;
}
