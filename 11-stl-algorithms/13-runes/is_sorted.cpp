/**
 * Demonstrates STL is_ rune (is_sorted algorithm).
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
	cout << boolalpha;
	vector<int> v{4,6,8,5,2,0,3,1,9,7};       // OK
	cout << "unsorted: " << v << endl;
	cout << "is_sorted: " << is_sorted(begin(v), end(v)) << endl;

	auto iter = is_sorted_until(begin(v), end(v));
	cout << "Number of sorted elements: " << (iter-begin(v)) << endl;

	sort(begin(v), end(v));
	cout << "\nsorted: " << v << endl;
	cout << "is_sorted: " << is_sorted(begin(v), end(v)) << endl;
	iter = is_sorted_until(begin(v), end(v));
	cout << "Number of sorted elements: " << (iter-begin(v)) << endl;
}

