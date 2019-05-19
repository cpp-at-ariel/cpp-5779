/**
 * Demonstrates STL search query algorithms.
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
	vector<int> v{4,2,8,5,2,0,1,1,9,7,5,2,0};       
	cout << "unsorted: " << v << endl;

	auto find8 = find(begin(v), end(v), 8);
	cout << "\nfind(8): " << (find8!=end(v)) << " " << (find8-begin(v)) << endl;

	auto find99 = find(begin(v), end(v), 99);
	cout << "find(99): " << (find99!=end(v)) << " " << (find99-begin(v)) << endl;

	auto adjacentfind = adjacent_find(begin(v), end(v));
	cout << "\nadjacent_find(): " << (adjacentfind!=end(v)) << " " << (adjacentfind-begin(v)) << endl;

	vector<int> v520 {5,2,0};
	auto search520 = search(begin(v), end(v), begin(v520), end(v520));
	cout << "\nsearch(5,2,0): " << (search520!=end(v)) << " " << (search520-begin(v)) << endl;
	vector<int> v521 {5,2,1};
	auto search521 = search(begin(v), end(v), begin(v521), end(v521));
	cout << "search(5,2,1): " << (search521!=end(v)) << " " << (search521-begin(v)) << endl;

	auto findend520 = find_end(begin(v), end(v), begin(v520), end(v520));
	cout << "\nfind_end(5,2,0): " << (findend520!=end(v)) << " " << (findend520-begin(v)) << endl;
	auto findend521 = find_end(begin(v), end(v), begin(v521), end(v521));
	cout << "find_end(5,2,1): " << (findend521!=end(v)) << " " << (findend521-begin(v)) << endl;

	auto findfirstof521 = find_first_of(begin(v), end(v), begin(v521), end(v521));
	cout << "\nfind_first_of(5,2,1): " << (findfirstof521!=end(v)) << " " << (findfirstof521-begin(v)) << endl;

	auto minelement = min_element(begin(v), end(v));
	cout << "\nmin_element(): index=" << (minelement-begin(v)) << ", value=" << (*minelement) << endl;
	auto maxelement = max_element(begin(v), end(v));
	cout << "max_element(): index=" << (maxelement-begin(v)) << ", value=" << (*maxelement) << endl;
	auto [min1,max1] = minmax_element(begin(v), end(v));
	// // equivalent to:
	// auto minmaxpair = minmax_element(begin(v), end(v));
	// auto min1 = minmaxpair.first;
	// auto max1 = minmaxpair.second;

	cout << "min index=" << (min1-begin(v)) << ", value=" << (*min1) << endl;
	cout << "max index=" << (max1-begin(v)) << ", value=" << (*max1) << endl;

	sort(begin(v), end(v));
	cout << "\nsorted: " << v << endl;
	auto [first1,last1] = equal_range(begin(v), end(v), 1);
	cout << "equal_range(1): " << first1-begin(v) << "," << last1-begin(v) << endl;
	auto [first2,last2] = equal_range(begin(v), end(v), 2);
	cout << "equal_range(2): " << first2-begin(v) << "," << last2-begin(v) << endl;
	auto [first3,last3] = equal_range(begin(v), end(v), 3);
	cout << "equal_range(3): " << first3-begin(v) << "," << last3-begin(v) << endl;
	cout << "binary_search(8): " << binary_search(begin(v), end(v), 8) << endl;
}

