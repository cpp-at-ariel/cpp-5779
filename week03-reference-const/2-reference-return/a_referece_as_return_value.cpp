/**
 * Demonstrates returning references from functions.
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
using namespace std;


int globalnum = 11;

int g1() { 
    return globalnum;
}

int& g2() {
    return globalnum;
}

const int& g3() {
    return globalnum;
}

int& g4() {
	int localnum;
	return localnum;
}


int main() {
    int num1 = g1();
    int num2 = g2();
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

    //int& rnum1 = g1();  // compilation error
    int& rnum2 = g2();    // OK
    //cout << "rnum1 = " << &rnum1 << " " << rnum1 << endl;
    cout << "rnum2 = " << &rnum2 << " " << rnum2 << endl;

    const int& crnum1 = g1();
    const int& crnum2 = g2();
    cout << "crnum1 = " << &crnum1 << " " << crnum1 << endl;
    cout << "crnum2 = " << &crnum2 << " " << crnum2 << endl;

    cout << "globalnum = " << globalnum << endl;
    cout << "g2() = " << g2() << endl;
    //g1() = 13;    // error: expression is not assignable
    g2() = 22;      // changes globalnum
    cout << "globalnum = " << globalnum << endl;
    cout << "g2() = " << g2() << endl;

    //g3() = 33; // compilation error

    cout << "g4() = " << g4() << endl;
	g4() = 14;
    cout << "g4() = " << g4() << endl;
}
