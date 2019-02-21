/**
 * Demo of overloading the comma operator.
 * See: https://stackoverflow.com/a/18136340/827927
 * 
 * Not very useful.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
using namespace std;

class StringPair {
	string i, j;
public:
	StringPair(string ii, string jj): i(ii), j(jj) {}
	friend ostream& operator<< (ostream& out, const StringPair& pair);
	friend StringPair operator+(StringPair a, StringPair b);
};

ostream& operator<< (ostream& out, const StringPair& pair) {
	out << pair.i << "," << pair.j;
	return out;
}

StringPair operator, (string ii, string jj) {
	return StringPair(ii,jj);
}

string operator, (string ii, StringPair jj) {
	return "Operator, on string,StringPair"s;
}

string operator, (StringPair jj, string ii) {
	return "Operator, on StringPair,string"s;
}

StringPair operator+(StringPair a, StringPair b) {
	return StringPair(a.i+b.i, a.j+b.j);
}

int main() {
	cout << (string{"aa"} , "bb"s) + ("cc"s , "dd"s) << endl;
	cout << ("ee", "ff") << endl;
	cout << ("gg"s, "hh"s, "ii"s) << endl;
	return 0;
}
