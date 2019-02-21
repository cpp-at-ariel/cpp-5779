/**
 * @author Ofir Pele
 * @since 2017
 */

#include "Complex.hpp"

#include <fstream>
#include <iostream>
using namespace std;
#include <assert.h>

int main(int argc, char **argv) {
    cout << "Complex Demo" << endl;

    Complex c1(1,2), c2(3), c3;
    cout << "c1 = " << c1 << endl << "c2 = " << c2 << endl << "c3 = " << c3 << endl << endl;    
    cout << (c1 += c2) << endl;
    cout << (c1 += Complex(5,6) += Complex(6,5)) << endl;
    //c1 += c2 += c2;
    cout << "c1 = " << c1 << endl << "c2 = " << c2 << endl << "c3 = " << c3 << endl << endl;
    c1.operator+=(c2); // equivalent to c1+=c2;

    cout << "c1 = " << c1 << endl;
    // Equivalent to:
    // cout << "c1 = ";
    // cout << c1;
    // cout << endl;
    // c1 << cout;

    cout << "-c1 = " << -c1 << endl;
    cout << "c1 = " << c1 << endl;
    //-c1 = Complex(5,6);
    cout << "-c1 = " << -c1 << endl;

    cout << "c1++ = " << c1++ << endl;
    cout << "++c1 = " << ++c1 << endl;

    // cout << "c1+c2 = " << (c1+c2) << endl;
    // cout << "c1+c2 = " << operator+(c1,c2) << endl << endl;

    // Complex c5 = c1 + c2;
    // cout << "c5 = " << c5 << endl << endl;

    // Complex c6= 42 + c1;
    // Complex c7= c1 + 42.0;
    // Complex c8= 3.0 + 2.0;
    // cout << "c6 = " << c6 << endl << "c7 = " << c7 << endl << "c8 = " << c8 << endl << endl;

    // cout << "c1 + c2*c8 = " << c1 + c2*c8 << endl << endl;
   
    // cout << "-(c1 + c2*c8)  = " << -(c1 + c2*c8) << endl << endl;
   
    // cout << "(c1+=2.0) = " << (c1+=2.0) << endl << "(c1+=c2) = " << (c1+=c2) << endl << endl;
    // cout << "(c1*=2.0) = " << (c1*=2.0) << endl << "(c1*=c2) = " << (c1*=c2) << endl << endl;

    // cout << "(c1==c2) = " << (c1==c2) << endl;
    // cout << "(c1!=c2) = " << (c1!=c2) << endl;

    // cout << "!c1 = " << (!c1) << endl;
    // cout << "!c2 = " << (!c2) << endl;
    // cout << "!c3 = " << (!c3) << endl;

    // //double d1 = c1;
    // //cout << "d1 = " << d1 << endl;

    // cout << endl;
    
    // Complex c9(4.0,-2.2);
    // Complex c10= c9;
    // Complex c11= c10;
    // Complex c12= c11;
    // Complex c13= c9;
    // cout << "(c9==c10) = " << (c9==c10) << endl;

    // cout << "c9*c10 = " << c9*c10 << endl;
    // c9*=c9;
    // cout << "c9 = "     << c9 << endl;
    // cout << "c10*c10 = "  << (c10*c10) << endl;
    // cout << "(c11*=c12) = " << (c11*=c12) << endl;
    // cout << "(c13*=c13) = " << (c13*=c13) << endl << endl;

    // // won't compile as we return const
    // //-c9= c10;
    // //cout << "c9 = "     << c9 << endl;
    // //cout << "c10 = "     << c10 << endl;
    // //(c1+c2)= c3;
    // //(c1*c2)= c3;

    // c3= c1 * c2;
    // assert (c1*c2==c3);

    cout << "c1 is now " << c1<<endl;
    cout << "Enter a complex number: ";
    cin >> c1;
    cout << endl << "You entered " << c1<<endl;


    // if (argc!=2) {
    //     cerr << "Usage: " << argv[0] << " filename" << endl;
    //     return 1;
    // }
   


    fstream fin(argv[1]);
    if (!fin) {
         cerr << "File " << argv[1] << " not open" << endl;
         return 1;
    }

    fin >> c1;
    // if (!fin) {
    //     if (fin.bad()) {
    //         cout << "Fatal error with stream, quiting" << endl;
    //         return 1;
    //     }
    //     cout << "Error in format. You inserted: " << endl;
    //     char c;
    //     fin.clear();
    //     while (fin >> c) {
    //         cout << c;
    //     }
    //     cout << endl;
    //     return 1;
    // }
   
    // cout << "You inserted: " << c1 << endl;
    return 0;

}
