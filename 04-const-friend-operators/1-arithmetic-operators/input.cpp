/**
 * A demo of output formatting
 * @author Erel Segal-Halevi
 * @since  2019-03
 */

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;



int main() {
    int i=9999;
    cout << i << endl;
    istringstream input("abc");
    if (input) cout <<"input is OK"<<endl; else cout << "input is wrong"<<endl;
    input >> i;
    if (input) cout <<"input is OK"<<endl; else cout << "input is wrong"<<endl;
    cout << i << endl;
}
