#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <typename T1, typename T2> struct pair {
	T1 first;
	T2 second;
};

template <typename T1, typename T2> 
ostream& operator<< (ostream& out, const pair<T1,T2>& thepair) {
		out << thepair.first << "," << thepair.second;
	return out;
}


int main() {
	pair<int,char> p1{2,'c'};
	cout << p1 << endl;
}
