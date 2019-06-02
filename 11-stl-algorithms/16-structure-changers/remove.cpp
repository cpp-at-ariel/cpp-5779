/**
 * Demonstrates STL remove algorithm.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>
#include <array>
#include "output_containers.hpp"
using namespace std;



int main() {
	vector<int> v {11,8,4,6,11,9,3,5,11,6};
	vector<int> v2 = v;
	cout << "v: " << v << endl;
	auto new_end = remove(begin(v), end(v), 11);
	cout << "v after remove 11: " << v << endl;
	v.erase(new_end, end(v));
	cout << "v after erase: " << v << endl<<endl;

	vector<int> v3;
	remove_copy(begin(v2), end(v2), back_inserter(v3), 11);
	cout << "v2 after remove_copy: " << v2 << endl;
	cout << "v3 after remove_copy: " << v3 << endl<<endl;

	remove_copy(begin(v2), end(v2), ostream_iterator<int>{cout,";"}, 11);
	cout << endl;

	v.erase(remove_if(begin(v), end(v), [](int a){return a%2==0;}), v.end());
	cout << "v after removing and erasing even numbers: " << v << endl << endl; 
	v3.clear();
	remove_copy_if(
		begin(v2), end(v2),  
		back_inserter(v3), 
		[](int a){return a%2==0;});
	cout << "v2 after remove_copy_if: " << v2 << endl;
	cout << "v3 after remove_copy_if: " << v3 << endl<<endl;
}

