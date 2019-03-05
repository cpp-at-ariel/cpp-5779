/**
 * A simple example of variable scopes.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-02
 */

#include <iostream>
using namespace std;

int j=1111;

int main() {
	int i = 1111;
	int j = i+2222;
	cout << "j = " << j << endl;
	{
		int j = i+3333;
		cout << "j = " << j << endl;
		int k = i+4444;
	}
	cout << "j = " << j << endl;
	// cout << k << endl;  // k is not defined
}
