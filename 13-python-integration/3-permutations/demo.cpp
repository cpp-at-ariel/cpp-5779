/**
 * Demonstrates "next_permutation" and "iota".
 */

#include "output_containers.hpp"
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	{
		vector<int> v(4);
		iota(v.begin(), v.end(), 1); // fill the vector with 1,...,n
		cout << "Permutations of iota:" << endl;
		do {
			cout << v << endl;
		} while ( next_permutation(v.begin(),v.end()) );
	}
	{
		string v {"abcd"};
		cout << "Permutations of string:" << endl;
		do {
			cout << v << endl;
		} while ( next_permutation(v.begin(),v.end()) );
	}
	return 0;
}
