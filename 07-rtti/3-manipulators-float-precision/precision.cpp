/**
 * A demo of output formatting and IO manipulators
 * 
 * @author Erel Segal-Halevi
 * @since  2019-03
 */

#include <iostream>
#include <iomanip>
using namespace std;

void printxyz() {
    cout << "  ";
    double x = 1.66, y=5./3., z=y*3.;
    cout << x << " " << y << " " << z << endl;
}

void printsmallnums() {
    cout << "  ";
    for(float value = -0.6; value <= 0.6; value += 0.2)
        cout << value << " ";
    cout << endl;
}


void printlargenums() {
    cout << "  ";
    for(float value = -666.0; value <= 666.0; value += 222.0)
        cout << value << " ";
    cout << endl;
}



int main() {
    double huge1 = 1e302;
    double huge2 = huge1 + 99999999999999;
    cout << huge2-huge1 << endl;

    cout << true << boolalpha << " " << true << endl;


    cout << 1234.5678 << endl;
    cout << 12345678. << endl;

    cout << setprecision(4)
         << 1234.5678 << endl
         << 12345678. << endl;

    cout << setprecision(100)  << 1234.5678 << endl << 12345678. << endl;

    cout << "default: " << endl; 
    printsmallnums(); printlargenums(); printxyz();
    for (int i=0; i<10; ++i) {
        cout << "precision(" << i << "): " << endl << setprecision(i); 
        printsmallnums(); printlargenums(); printxyz();
    }
}
