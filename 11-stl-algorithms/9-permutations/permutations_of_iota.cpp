/**
 * Demonstrates the "next_permutation" algorithm 
 * and the "iota" function.
 */

#include "output_containers.hpp"
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

int main() {
	vector<int> v(5);
	iota(v.begin(), v.end(), 0);
	cout << v << endl;
	do {
		cout << v << endl;
	} while ( next_permutation(v.begin(),v.end()) );
	cout << v << endl;
	return 0;
}
