/**
 * Demonstrates how to access the internal types of template classes.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */


#include <iostream>
#include <vector>
using namespace std;

template <typename T> class array {
public:
	using TT=T;
};

int main() {
	array<int> a1;
	array<string> a2;
	cout << typeid(decltype(a1)::TT).name() << endl;
	cout << typeid(decltype(a2)::TT).name() << endl;

	vector<int> v1;
	vector<string> v2;
	cout << typeid(decltype(v1)::value_type).name() << endl;
	cout << typeid(decltype(v2)::value_type).name() << endl;
}

