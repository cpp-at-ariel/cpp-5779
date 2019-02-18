/**
 * Demo of the comma operator without overloading (in C)
 * 
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
using namespace std;

int main() {
	cout << (1,2,3) << endl;
	int i = (4,5,6);
	cout << i << endl;

	if ( (i=5*6, i>0) ) {
		cout << "i>0 and i="<<i<<endl;
	}
}


