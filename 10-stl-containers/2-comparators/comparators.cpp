/**
 * Demonstrates how to define and use different comparators.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <iostream>
#include <set>
using namespace std;

/**
 * This is a comparator for ordering elements from large to small
 * (instead of the default which is from small to large).
 */
struct SederYored {
	bool operator()(int x, int y) {
		return x>y;
	}
};

/**
 * This is a comparator for ordering the even elements first, and then the odd elements.
 * In each group, elements are arranged from small to large.
 */
struct ZugiIzugi {
	bool operator()(int x, int y) {
		if ( (x%2 == y%2) )
			return x<y;
		if (x%2==0 && y%2!=0)
			return true;
		else // if (x%2!=0 && y%2==0)
			return false;
	}
};

int main() {
	//set<int> s1;
	//set<int, less<int> > s1;  // default
	// set<int,SederYored> s1;
	// set<int,greater<int>> s1;
	set<int,ZugiIzugi> s1 {1,2,4,6};
	s1.emplace(5);
	s1.emplace(7);
	s1.emplace(3);
	for (auto s: s1)
		cout << s << endl;
}
