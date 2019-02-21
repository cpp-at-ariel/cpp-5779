/**
 * Header file for the Complex class.
 * 
 * @author Ofir Pele
 * @since 2017
 */

#pragma once

#include <iostream>
using namespace std;

class Complex {

private:

    double _re;
    double _im;

public:

    //-------------------------------------
    // Ctors & Destructor
    //-------------------------------------
    // Ctor works also as a conversion from double and
    // also as a default ctor.
    Complex (const double& re= 0.0,
             const double& im= 0.0)
        : _re(re), _im(im) {
    }
    //-------------------------------------

	//-------------------------------------
	// getters
	//-------------------------------------
	double re() const {
		return _re;
	}

	double im() const {
		return _im;
	}
	//-------------------------------------
	
    //-------------------------------------
    // operators
    //-------------------------------------

    //----------------------------------------
    // binary operators
    //----------------------------------------
    Complex& operator+=(const Complex& other) {
        _re+= other._re;
        _im+= other._im;
        return *this;
    }

    // const Complex operator+(const Complex& other) const {
    //     return Complex(_re + other._re, _im + other._im);
    // }

    Complex& operator-=(const Complex& other) {
        _re-= other._re;
        _im-= other._im;
        return *this;
    }

    const Complex operator-(const Complex& other) const {
        return Complex(_re - other._re, _im - other._im);
    }

    Complex& operator*=(const Complex& other) {
        double new_re = _re*other._re - _im*other._im;
        double new_im = _re*other._im + _im*other._re; 
        _re = new_re;
        _im = new_im;
		// version with bug
		// _im= _re*other._im + _im*other._re; 
		// _re= _re*other._re - _im*other._im;
		return *this;
    }
    //----------------------------------------

    /*
    operator double() const {
        return todouble();
    }
    */

    //----------------------------------
    // unary operator
    //----------------------------------
    // the const on the return type is to
    // avoid -c1= c10 from working
    const Complex operator-() const {
        return Complex(-_re , -_im);
    }

    // Logical NOT
    bool operator!() const {
        return _re==0 && _im==0;
    }

    // prefix increment:
    Complex& operator++() {
        _re++;
        return *this;
    }

    // postfix increment:
    const Complex operator++(int flag_for_postfix_increment) {
        Complex copy = *this;
        _re++;
        return copy;
    }
    

    // Bitwise NOT
    // bool operator~() const {
    //     return _re==0 && _im==0;
    // }


    /* Works, but unexpected - don't do it 
    ostream& operator<< (ostream& os) const {
        os << "(" << _re << "+" << _im << "i)";
        return os;
    }
    */
    
    //----------------------------------
    // friend global IO operators
    //----------------------------------
    friend ostream& operator<< (ostream& os, const Complex& c);
    friend istream& operator>> (istream& is, Complex& c);
    //-------------------------------------

    //-------------------------------------
    // friend global binary operators
    //-------------------------------------
    friend const Complex operator+ (const Complex& c1, const Complex& c2);
    friend const Complex operator* (const Complex& c1, const Complex& c2);
    friend bool operator==(const Complex& c1, const Complex& c2);
    friend bool operator!=(const Complex& c1, const Complex& c2);
}; // end of class Complex

//----------------------------------------
// friend global IO operators
//----------------------------------------
inline ostream& operator<< (ostream& os, const Complex& c) {
    // return (os << c._re << '+' << c._im << 'i');
    // equivalent to:
    os << c._re << '+' << c._im << 'i';
    return os;
}

//----------------------------------------

//----------------------------------------
// friend global binary operators
//----------------------------------------
inline const Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1._re + c2._re, c1._im + c2._im);
}




inline const Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex (c1._re * c2._re - c1._im * c2._im,
                    c1._re * c2._im + c1._im * c2._re);
}

inline bool operator==(const Complex& c1, const Complex& c2) {
    // this implementation can cause problems with
    // double precision (== for doubles)
    return ((c1._re==c2._re)&&(c1._im==c2._im));
}

inline bool operator!=(const Complex& c1, const Complex& c2) {
    return (!(c1==c2));
}


