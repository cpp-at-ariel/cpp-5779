/**
 * Demonstrates STL partition algorithms.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <array>
#include "output_containers.hpp"
using namespace std;



int main() {
	vector<int> v{9,8,6,7,4,5,2,0,3,1};       // OK
	cout << "original vector: " << v << endl;

	auto middle = partition(begin(v), end(v), [](int x){return x%2==0;});
	cout << "partition to even vs. odd: " << v << endl;

	cout << "even elements: " << tostring(begin(v), middle) << endl;
	cout << "odd elements: " << tostring(middle, end(v)) << endl;

	auto middle2 = partition_point(begin(v), end(v), [](int x){return x%2==0;});
	cout << "\neven elements: " << tostring(begin(v), middle) << endl;
	cout << "odd elements: " << tostring(middle, end(v)) << endl;
}

