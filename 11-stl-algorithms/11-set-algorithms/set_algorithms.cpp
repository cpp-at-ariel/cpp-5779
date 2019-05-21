/**
 * Demonstrates STL set algorithms.
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
	vector<int> v1{0,1,1,2,3,4,4,5,6,7,8,9};
	set<int> v2{2,4,6,8,10,12,14,16,18};
	vector<int> vunion;
	vector<int> vdifference1, vdifference2, vdifference, vintersect;
	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;
	set_union(begin(v1), end(v1), begin(v2), end(v2), back_inserter(vunion));
	cout << "v1 U v2: " << vunion << endl;
	set_intersection(begin(v1), end(v1), begin(v2), end(v2), back_inserter(vintersect));
	cout << "v1 ^ v2: " << vintersect << endl;
	set_difference(begin(v1), end(v1), begin(v2), end(v2), back_inserter(vdifference1));
	cout << "v1 - v2: " << vdifference1 << endl;
	set_difference(begin(v2), end(v2), begin(v1), end(v1), back_inserter(vdifference2));
	cout << "v2 - v1: " << vdifference2 << endl;
	set_symmetric_difference(begin(v2), end(v2), begin(v1), end(v1), back_inserter(vdifference));
	cout << "v2 X v1: " << vdifference << endl;

	vector<int> v3{6,8,10};
	cout << boolalpha << includes(begin(v1), end(v1), begin(v3), end(v3)) << endl;
	cout << boolalpha << includes(begin(v2), end(v2), begin(v3), end(v3)) << endl;
}

