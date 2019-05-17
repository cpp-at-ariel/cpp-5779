/**
 * Demonstrates IO iterators with STL containers.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <iostream>
#include <sstream>
#include <iterator>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

template<typename T> ostream& operator<<(ostream& out, const set<T>& container) {
	copy(container.begin(), container.end(), 
		ostream_iterator<T>(out,"; "));
	return out;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& container) {
	copy(container.begin(), container.end(), 
		ostream_iterator<T>(out,"; "));
	return out;
}

int main() {
	// example of insert iterator:
	vector<int> v;
	auto viter = back_inserter(v);
	*viter = 2;
	*viter = 5;
	*viter = 3;
	cout << "v: " << v << endl;

	set<int> s;
	auto siter = inserter(s, s.begin());
	*siter = 2;
	*siter = 5;
	*siter = 3;
	cout << "s: " << s << endl;

	
	// example of copy + inserter:
	// (copy vector to set - get rid of duplicates, and sort by value):
	vector<int> v1 {1,7,3,5,1,3};
	cout << "v1: " << v1 << endl;
	set<int> s1;
	copy(v1.begin(), v1.end(), insert_iterator(s1, s1.begin()));
	cout << "s1: " << s1 << endl;
	v1.clear();
	copy(s1.begin(), s1.end(), back_insert_iterator(v1));
	cout << "v1: " << v1 << endl;
}

