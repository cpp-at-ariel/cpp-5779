#include <iostream>
using namespace std;


istream& operator>>(istream& in, int x) {
	in.precision(x);
	return in;
}

int main() {
	cin >> 5;
}
