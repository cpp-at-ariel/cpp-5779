#include <cassert>
#include <iostream>
#include <set>
using namespace std;

struct SederYored {
	bool operator()(int x, int y) {
		return x>y;
	}
};
	
struct ZugiIzugi {
	bool operator()(int x, int y) {
		if ( (x%2 == y%2) )
			return x<y;
		if (x%2==0 && y%2!=0)
			return true;
		if (x%2!=0 && y%2==0)
			return false;
	}
};

int main() {
	//set<int> s1;
	//set<int, less<int> > s1;  // default
	//set<int,SederYored> s1;
	set<int,greater<int>> s1;
	//set<int,ZugiIzugi> s1 {1,2,4,6};
	s1.emplace(5);
	s1.emplace(7);
	s1.emplace(3);
	for (auto s: s1)
		cout << s << endl;
}
