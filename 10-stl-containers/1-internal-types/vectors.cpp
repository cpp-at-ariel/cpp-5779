#include <cassert>
#include <iostream>
#include <vector>
#include <array>
using namespace std;



int main() {
	int i{5};
	cout << i << endl;
	int j{};
	cout << j << endl;
	int k;
	cout << k << endl;
	return 0;

	vector<int> v1 {1,2,3};
	cout << v1.size() << " " << v1.capacity() << endl;
	v1.emplace_back(4);
	cout << v1.size() << " " << v1.capacity() << endl;
	// for (int i=0; i<100000; ++i) {
	// 	cout << "i=" << i << endl;
	// 	//cout << "&=" << &v1[i] << endl;
	// 	cout << v1.at(i) << endl;
	// }

	int a1[3] = {1,2,3};
	for (int i=0; i<100000; ++i) {
		cout << "i=" << i << endl;
		cout << "&=" << &a1[i] << endl;
		cout << a1[i] << endl;
		//cout << a1.at(i) << endl; // won't compile
	}

	array<int,3> ar = {1,2,3};
	for (int i=0; i<100000; ++i) {
		cout << "i=" << i << endl;
		cout << "&=" << &ar[i] << endl;
		cout << ar.at(i) << endl;
	}

	return 0;
}
