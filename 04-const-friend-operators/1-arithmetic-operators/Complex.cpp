/**
 * Implementation of the Complex class.
 * 
 * @author Ofir Pele
 * @since 2017
 */

#include "Complex.hpp"
using namespace std;

//----------------------------------------
// friend global binary operators
//----------------------------------------

const Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex (c1._re * c2._re - c1._im * c2._im,
                    c1._re * c2._im + c1._im * c2._re);
}

bool operator==(const Complex& c1, const Complex& c2) {
    // this implementation can cause problems with
    // double precision (== for doubles)
    return ((c1._re==c2._re)&&(c1._im==c2._im));
}

bool operator!=(const Complex& c1, const Complex& c2) {
    // return ( (c1._re!=c2._re) || (c1._im!=c2._im) );
    // return (!(c1==c2));
    return ( abs(c1._re-c2._re)>0.0001 || abs(c1._im-c2._im)>0.0001 );
}

bool operator^(const Complex& c1, const Complex& c2) {
    return ( (c1._re!=c2._re) || (c1._im!=c2._im) );
    // return (!(c1==c2));
}


const Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1._re - c2._re, c1._im - c2._im);
}


//----------------------------------------
// friend global IO operators
//----------------------------------------
ostream& operator<< (ostream& os, const Complex& c) {
    return (os << c._re << '+' << c._im << 'i');
    // equivalent to:
    // os << c._re << '+' << c._im << 'i';
    // return os;
}


static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
    char actualChar;
    input >> actualChar;
    if (!input) return input;

    if (actualChar!=expectedChar) 
        // failbit is for format error
        input.setstate(ios::failbit);
    return input;
}

istream& operator>> (istream& input, Complex& c) {

    //---------------------------------------------
    // Does not check format
    //---------------------------------------------
    // char ch;
    // return (input >> c._re >> ch >> c._im >> ch);
    //---------------------------------------------

    //---------------------------------------------
    // Checks format, with rewind on failure.
    //---------------------------------------------
    double new_re, new_im;

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if ( (!(input >> new_re))                 ||
         (!getAndCheckNextCharIs(input,'+')) ||
         (!(input >> new_im))                 ||
         (!(getAndCheckNextCharIs(input,'i'))) ) {

        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear(); // clear error so seekg will work
        input.seekg(startPosition); // rewind
        input.clear(errorState); // set back the error flag
    } else {
        c._re = new_re;
        c._im = new_im;
    }

    return input;
    //---------------------------------------------
}
