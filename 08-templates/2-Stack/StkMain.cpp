#include "Stk.hpp"

#include <string>
#include <iostream>
using namespace std;

int main() {

	/*** A stack of strings ***/

	string str1("Hello ");
	string str2("world !\n");

	Stk<string>  strStk;
	strStk.push(str2);
	strStk.push(str1);

	while(!strStk.isEmpty()) {
		cout << strStk.top();
		strStk.pop();
	}
	
	strStk.push(str2);
	strStk.push(str1);
	// Old C++ style
	for (
		Stk<string>::iterator it= strStk.begin(); 
		it!=strStk.end(); 
		++it) {
		cout << it->size() << " ";
		cout << *it;
	}
	// C++-11 style
	for (const string& val: strStk) {
		cout << val;
	}

	/*** A stack of ints ***/

	int arr[]= {43, 21, -22};
	// Calling templated ctor, old C++ style
	Stk<int> intStk(arr, arr+3);

	// Calling templated ctor, C++-11 style
	Stk<int> intStk2(begin(arr), end(arr));
	for (const auto& val: intStk) {
		cout << val << " ";
	}
	cout << endl;
	for (const auto& val: intStk2) {
		cout << typeid(val).name();
		cout << val << " ";
	}
	cout << endl;

	Stk<int> intStk3 (intStk.begin(), intStk.end());
	
	// Remark: C++-11 allows also to write classes that have {} constructors:
	// Stk<int> intStk3{43, 21, -22};

	cout << intStk2.top() << endl;
	intStk2.top()= 100000;
	cout << intStk2.top() << endl;
	
	return 0;
}
