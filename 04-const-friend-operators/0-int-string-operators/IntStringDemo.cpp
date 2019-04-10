/**
 * Demonstrates operator overloading in C++.
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
#include <vector>
using namespace std;

// int operator*(int a, int b) { return 0; }

string operator* (int n, string s){ 
    string result = s;
    for (int i=1; i<n; ++i)
        result += s;
    return result;
}

string operator* (string s, int n) {
    return "("+n*s+")";
}

bool operator!(string s) {
    return (s.length()==0);
}

string operator+(string a, string b) {
//    return b+a;   // segmentation fault - stack overflow!

    // string result = b;
    // result += a;
    // return result;

    return std::operator+(b,a);
}

/* Compiler error: 
int operator* (int a, int b) {
    return a+b;
}
*/

ostream& operator<< (ostream& os, string s) {
    //os << s;  // segmentation fault
    std::operator<<(os,s);
    return os;
}

// int oper//ator+(const vector<int>& y, int x) {
//     int //sum = x;
//     for //(int i=0; i<y.size(); ++i)
//         sum += y[i];
//     return sum;
// }

int main() {
    int i=5;
    cout << ((i--)-i) << endl;
    return 0;

    string x="abc", y="def";
    
    cout << "3 * y  = " << 3 * y << endl;
    //Equivalent to: 
    // cout << operator*(3,y) << endl;

    cout << "x + y = " << (x+y) << endl;  // defined here: https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01075_source.html
    cout << "3 * (x + y) = " << 3 * (x + y) << endl;
    cout << "3 * x + y = " << 3 * x + y << endl;

    cout << (x * 3) << endl;

    cout << (!x) << endl;

    // x = "";
    if (!x) {
        cout << "x is empty" << endl;
    } else {
        cout << "x is not empty" << endl;
    }
    
    //cout << operator*(x,3) << endl;
    return 0;
}
