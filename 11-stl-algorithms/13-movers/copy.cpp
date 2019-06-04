/**
 * Demonstrates STL copy and copy_backward algorithms
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <array>
#include "output_containers.hpp"
using namespace std;



int main() {
	vector<int> v{0,1,2,3,4,5,6,7,8,9};
	vector<int> v2;
	cout << "v: " << v << endl;
	cout << "v2: " << v2 << endl;
	copy(begin(v), end(v), back_inserter(v2));
	cout << "v: " << v << endl;
	cout << "v2: " << v2 << endl << endl;
	//v2.insert(begin(v2), begin(v), end(v));
	//cout << "v2: " << v2 << endl << endl;

	copy(begin(v)+4, end(v), begin(v)+1);
	cout << "v after copy [4,end) to begin+1: " << v << endl;
	copy(begin(v2), end(v2), begin(v));
	cout << "v after copy from v2: " << v << endl;
	copy_backward(begin(v)+1, begin(v)+5, begin(v)+7);
	cout << "v after copy_backward [begin+1,begin+5) to begin+7: " << v << endl;
}

