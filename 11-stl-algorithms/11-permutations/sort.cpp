/**
 * Demonstrates STL sort algorithms.
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
	array<int,10> v{9,8,6,7,4,5,2,0,3,1};
	cout << "unsorted: " << v << endl;

	sort(begin(v), end(v));
	cout << "sorted: " << v << endl;
}

