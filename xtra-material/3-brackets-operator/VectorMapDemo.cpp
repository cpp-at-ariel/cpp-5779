/**
 * Demonstrates brackets operator in STL.
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

ostream& operator<< (ostream& out, const vector<int>& v) {
    out << "[";
    for (int i=0; i<v.size(); ++i) {
        out << v[i] << " ";
    }
    out << "]";
    return out;
}

vector<int> operator+ (const vector<int>& a, const vector<int>& b){ 
    cout << "WARNING! Sum is not implemented yet!" << endl;
    return a;
}


int main() {
    vector<int> v1 {1,2,3};
    cout << "v1 = " << v1 << endl;
    cout << "v1[0] = " << v1[0] << endl;
    v1[0] = 4;
    cout << "v1 = " << v1 << endl;
    cout << "v1[0] = " << v1[0] << endl;

    vector<int> v2 {4,5,6};
    cout << "v1+v2 = " << v1+v2 << endl;


    map<string,int> m1 {{"a",1}, {"b",2}, {"c",3}};
    cout << "m1[a] = " << m1["a"] << endl;
    return 0;
}
