#include <cassert>
#include <iostream>
#include <iterator>
#include <set>
#include <map>
using namespace std;

int main() {
	set<int> s1 {1,2,5,7,16,21};

	cout << boolalpha;
	auto i4 = s1.find(99);
	cout << (i4 == s1.end()) << endl; // true
	cout << (*i4) << endl;  // meaningless

	cout << (s1.find(5) == s1.end()) << endl; // false
	cout << (*s1.find(5)) << endl;  // 5

	cout << (*s1.lower_bound(4)) << endl;  // 5
	cout << (*s1.upper_bound(4)) << endl;  // 5

	cout << (*s1.lower_bound(5)) << endl;  // 5
	cout << (*s1.upper_bound(5)) << endl;  // 7

	multimap<int,int> mymap {
		{1,11}, 
		{2,22}, 
		{3,33}, {3,34}, {3,35},
		{4,44}};
	for (auto it = mymap.lower_bound(3); it != mymap.upper_bound(3); ++it) {
		cout << "key=" << it->first << " value=" << it->second << endl;
	}
}
