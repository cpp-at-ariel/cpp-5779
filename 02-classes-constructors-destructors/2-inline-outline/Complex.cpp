/**
 * Demonstrates inline and outline method implementation
 */

#include <iostream>
using namespace std;

class Complex {
    double re, im;

public:
    Complex() {  re = im  = 0; }    // inline constructor
    Complex(double re, double im);  // "outline" constructor

    string to_string() {           // inline method  
        return std::to_string(re)+"+"+std::to_string(im)+"i";
    }
    Complex sum(Complex b);        // "outline" method
};


// "outline" constructor implementation:
Complex::Complex(double re, double im) {  
    (*this).re = re;
    this->im = im; 
}   

// "outline" method implementation:
Complex Complex::sum(Complex b) {  
    return Complex(re+b.re, im+b.im);
}


int main() {
    Complex a(1,2);
    cout << "a = " << a.to_string() << endl;

    Complex b(3,4);
    cout << "b = " << b.to_string() << endl;

    Complex c = a.sum(b);
    cout << "c = " << c.to_string() << endl;
}
