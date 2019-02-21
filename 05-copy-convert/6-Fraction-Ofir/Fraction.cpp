/**
 * Implementation of the Fraction class.
 * 
 * @author Ofir Pele
 * @since 2017
 */


#include "Fraction.h"
#include <iostream>
#include <cmath>

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//implementation of friend functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

istream& operator >> (istream & is, Fraction& frac)
{
	char divSign;
	is >> frac.nom >> divSign >> frac.den;
	if (frac.den == 0)
		frac.den = 1;
	frac.reduce();
	return is;
}

ostream& operator<<(ostream& os, const Fraction& frac)
{
	return os << frac.nom << '/' << frac.den;
}

Fraction operator+ (const Fraction& f1, const Fraction& f2)
{
	int nn = f1.nom * f2.den +
		f1.den * f2.nom;
	int dd = f1.den * f2.den;
	return Fraction(nn, dd);
}

Fraction operator- (const Fraction& f1,
	const Fraction& f2)
{
	int nn = f1.nom * f2.den -
		f1.den * f2.nom;
	int dd = f1.den * f2.den;
	return Fraction(nn, dd);
}

Fraction operator* (const Fraction& f1,
	const Fraction& f2)
{
	int nn = f1.nom * f2.nom;
	int dd = f1.den * f2.den;
	return Fraction(nn, dd);
}

Fraction operator/ (const Fraction& f1,
	const Fraction& f2)
{
	int nn = f1.nom * f2.den;
	int dd = f1.den * f2.nom;
	return Fraction(nn, dd);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//implementation of class Fraction
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Fraction& Fraction :: operator++()
{
	nom += den;
	reduce();
	return *this;
}

Fraction Fraction :: operator++(int)
{
	int nn = nom;
	int dd = den;
	nom += den;
	reduce();
	return Fraction(nn, dd);
}

int Fraction::gcd(int i, int j)
{
	if (i == 0 || j == 0)
		return i + j;
	while ((i %= j))  //(i%j)!=0
	{
		//swap the values	
		int t = i;
		i = j;
		j = t;
	}
	return j;
}

void Fraction::reduce()
{
	//find the greatest common divider
	int g = gcd(nom, den);
	//reduce the fraction
	nom /= g;
	den /= g;
}

/*
Fraction sqrt(const Fraction& f) {
	return Fraction(std::sqrt(f.nom),std::sqrt(f.den));
}
*/