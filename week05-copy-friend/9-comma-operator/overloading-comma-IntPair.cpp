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

enum myint {};
myint operator"" i(unsigned long long int j)  {return myint(j);}

class IntPair {
	int i, j;
public:
	IntPair(int ii, int jj): i(ii), j(jj) {}
	friend ostream& operator<< (ostream& out, const IntPair& pair);
	friend IntPair operator+ (IntPair a, IntPair b);
};


IntPair operator+ (IntPair a, IntPair b) {
	return IntPair(a.i+b.i, a.j+b.j);
}

ostream& operator<< (ostream& out, const IntPair& pair) {
	out << pair.i << "," << pair.j;
	return out;
}

IntPair operator, (myint ii, myint jj) {
	return IntPair(ii,jj);
}

int main() {
	IntPair p1(1,2) ;
	cout << "p1 = " << p1 << endl;

	cout << (3i,4i)+(5i,6i) << endl;
	//cout << ({3,4}+{5,6}) << endl;
	return 0;
}
