/**
 * Demonstrates basic strings vs strings.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <tuple>
using namespace std;


ostream& operator<< (ostream& out, basic_string<int> s) {
	for (int i: s)
		out << i;
	return out;
}

int main() {
	string s("abcdef");
	s.replace(3,6,"xyz");
	cout << s << endl;

	basic_string<int> si({1,2,3,4,5,6});
	si.replace(3,6, basic_string<int>{7,8,9});
	cout << si << endl;
}
