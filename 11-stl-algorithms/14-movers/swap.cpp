/**
 * Demonstrates STL swap_ranges algorithm
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
	vector<int> v{4,6,8,5,2,0,3,1,9,7};   
	list<int> v2{1,1,1,1,1,1,1,1,1,1};
	cout << "v: " << v << endl;
	cout << "v2: " << v2 << endl;
	swap_ranges(begin(v), end(v), begin(v2));
	cout << "v: " << v << endl;
	cout << "v2: " << v2 << endl;
}

