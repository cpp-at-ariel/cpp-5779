/**
 * Demonstrates STL numeric query algorithms.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>
#include <forward_list>
#include <array>
#include "output_containers.hpp"
using namespace std;



int main() {
	vector<int> v{4,6,8,5,4,1,3,1,4,7};    
	cout << "v = " << v << endl;
	cout << "count(4): " << count(begin(v),end(v),4) << endl;
	cout << "count(1): " << count(begin(v),end(v),1) << endl;
	cout << "count(0): " << count(begin(v),end(v),0) << endl;


	cout << "accumulate (sum): " << accumulate(begin(v),end(v),0) << endl;
	cout << "accumulate (product): " << accumulate(begin(v),end(v),1, [](int a, int b){return a*b;}) << endl;

	cout << "v = " << v << endl;
	vector<int> v2;
	partial_sum(begin(v),end(v), back_inserter(v2));
	cout << "\npartial_sum: " << v2 << endl;

	vector<int> v2a(v.size());
	partial_sum(begin(v),end(v), begin(v2a));
	cout << "\npartial_sum: " << v2a << endl;

	partial_sum(begin(v),end(v), ostream_iterator<int>(cout," "));
	cout << endl;

	vector<int> v3;
	adjacent_difference(begin(v2),end(v2), back_inserter(v3));
	cout << "adjacent_difference: " << v3 << endl;

	forward_list<int> u1 {1,2,3};
	vector<int> u2 {4,5,6};
	cout << "\ninner_product: " << inner_product(begin(u1),end(u1), begin(u2), 0) << endl;
}

