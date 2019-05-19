/**
 * Demonstrates STL two-range query algorithms.
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
	cout << boolalpha;
	vector<int> v1{0,1,2,3,4,5,6,7,8,9};
	list<int> v2{0,1,2,8,4,5,6,7,3,9};
	cout << "equal(v1,v2)): " << equal(begin(v1),end(v1),begin(v2),end(v2)) << endl;
	cout << "is_permutation(v1,v2)): " << is_permutation(begin(v1),end(v1),begin(v2),end(v2)) << endl;
	cout << "lexicographical_compare(v1,v2)): " << lexicographical_compare(begin(v1),end(v1),begin(v2),end(v2)) << endl;
	cout << "lexicographical_compare(v2,v1)): " << lexicographical_compare(begin(v2),end(v2),begin(v1),end(v1)) << endl;

	auto [iter1,iter2] = mismatch(begin(v1),end(v1),begin(v2),end(v2));
	cout << "mismatch-1: " << *iter1 << endl;
	cout << "mismatch-2: " << *iter2 << endl;
}

