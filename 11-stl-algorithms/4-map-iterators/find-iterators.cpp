/**
 * Demonstrates iteration on stl maps
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <map>
#include <iostream>
using namespace std;

int main() {
	multimap<string, int> m {
		{"abc", 2},
		{"def", 4},
		{"xyz", 6},
		{"abc", 3},
		{"def", 5},
		{"xyz", 7},
	};

	auto iter = m.find("abc");
	cout << iter->first << "," << iter->second << endl;

	iter = m.lower_bound("abc");
	cout << iter->first << "," << iter->second << endl;

	iter = m.upper_bound("abc");
	cout << iter->first << "," << iter->second << endl;
}
