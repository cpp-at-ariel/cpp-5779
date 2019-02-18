/**
 * Demonstrates operator overloading in C++.
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
#include <vector>
using namespace std;

string operator* (int n, string s){ 
    string result = s;
    for (int i=1; i<n; ++i)
        result += s;
    return result;
}

string operator+(string a, string b) {
//    return b+a;   // segmentation fault - stack overflow!

    // string result = b;
    // result += a;
    // return result;

    return std::operator+(b,a);
}

string operator* (string s, int n) {
    return "("+n*s+")";
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

int operator+(const vector<int>& y, int x) {
    int sum = x;
    for (int i=0; i<y.size(); ++i)
        sum += y[i];
    return sum;
}

int main() {
    string x="abc", y="def";
    cout << 3 * x << endl;
    cout << "x+y = " << (x+y) << endl;
    //cout << operator*(3,x) << endl;
    cout << 3 * (x + y) << endl;
    cout << 3 * x + y << endl;

    cout << (x * 3) << endl;
    //cout << operator*(x,3) << endl;

    cout << (vector<int>{1,2,3} + 5) << endl;
    //cout << ({1,2,3} + 5) << endl;
    
    return 0;
}
