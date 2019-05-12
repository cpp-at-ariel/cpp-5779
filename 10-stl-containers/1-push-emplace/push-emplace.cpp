/**
 * Demonstrates the difference between push_back and emplace
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <vector>
using namespace std;

struct MyClass {
	MyClass(int a) { cout << "ctor("<<a<<")"<<endl;}
	MyClass(int a,int b) { cout << "ctor("<<a<<","<<b<<")"<<endl;}
	MyClass(const MyClass& other) { cout << "copy-ctor"<<endl;}
	MyClass& operator=(const MyClass& other) { cout << "operator="<<endl; return *this;}
};


int main() {
	vector<MyClass> v1;
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl;
	v1.reserve(4);
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl;
	cout << "push_back" << endl;
	v1.push_back(MyClass(2));
	v1.push_back(MyClass(2,4));
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl;
	cout << "emplace_back" << endl;
	v1.emplace_back(3);
	v1.emplace_back(3,5);
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl;

	// cout << "push_back above capacity: " << endl;
	// v1.push_back(9);
	cout << "emplace_back above capacity: " << endl;
	v1.emplace_back(9);
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl;
}
