/**
 * Rational - a class that represents a ratioanl number -
 * a ratio between two integers (long ints).
 * 
 * 1. This rational should be represented using two integer values (long int): the numerator
 * (MONE) and the denominator (MECHANE) of the ratio. 
 * 2. The denominator cannot be zero.
 * 3. The numerator and the denominator should be coprime (MISPARIM ZARIM):
 * their greatest common divisor is 1.
 * 4. The zero element of this field is zero, and it should only be represented
 * with numerator of 0 and denominator of 1. If you reach some other
 * representation that equals 0 (like 0/5 or -0/1) change the representation to
 * 0/1 using private function fixZero().
 * The zero element is the value created by the default constructor (meaning
 * when calling constructor without any arguments) or by the constructor when
 * sending a long int argument of 0.
 * 5. For both add and mul we should remember to make sure the end
 * representation of the ratio has coprime numerator and denominator (TZIMTZUM
 * SHVARIM). For that purpose we should use the greatestCommonDivisor function
 * (private static function) and the makeRepresentationCoprime() private
 * non-static function to take care of it at the end of add and mul functions.
 * 6. If the rational value is positive, both the numerator and the denominator
 * in the representation should be positive.
 * 7. If the ratioanl value is negative, the numerator should be negative and
 * the denominator should be positive. For this, use the fixNegativity()
 * private function.
 * 8. If Rational(const long int& numerator, const long int& denominator)
 * constructor gets a zero denominator, it should fail with an assert.
 */
#pragma once

#include "myassert.hpp"

#include <cstdlib>
#include <cmath>
#include <string>

class Rational {
public:
	
	/**
	 * Constructors getting a long int or default which is set to 0
	 */
	Rational(const long int& value);
	
	/**
	 * Constructors getting numerator and denominator
	 */
	Rational(const long int& numerator, const long int& denominator);
	
	/**
	 * Constructors by string "numerator/denominator"
	 */
	Rational(const std::string& str);
	
	/**
	 * Returns the numerator
	 */
	const long int getNumerator() const;
	
	/**
	 * Returns the denominator
	 */
	const long int getDenominator() const;
	
	/*
	 * Returns true if the Rationals are equal and false otherwise
	 */
	const bool operator==(const Rational& other) const;
	
	const bool operator!=(const Rational& other) const;

	/**
	 * Returns the multiplication of this Rational and other
	 * Multiplication should be calculated in the way we calculate
	 * multiplication of 2 ratios (separately for the numerator and for the
	 * denominator).
	 */
	const Rational operator*(const Rational& other) const;

	/**
	 * Returns the sum of this Rational and other
	 */
	const Rational operator+(const Rational& other) const;
	
private:
	long int _numerator;
	long int _denominator;

	void _fixZero();

	void _fixNegativity();

	void _makeRepresentationCoprime();

	static const long int _greatestCommonDivisor(const long int& a, const long int& b);

};
