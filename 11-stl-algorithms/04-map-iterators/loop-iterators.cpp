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
	map<string, int> m {
		{"abc", 2},
		{"xyz", 8},
	};
	m["def"] = 4;
	m["ghi"] = 6;

	// map<string,int> m1 {[](const string& a, const string& b){return a>b;}};

	// Old version:
	for (map<string, int>::iterator iter = m.begin(); iter!=m.end(); ++iter) 
		cout << iter->first << "," << iter->second << endl;	
	cout << endl;

	// C++11 version:
	for (auto pair: m) 
		cout << pair.first << "," << pair.second << endl;	
	cout << endl;

	// C++17 version:
	for (auto [key,value]: m)
		cout << key << "," << value << endl;	
	cout << endl;
}
