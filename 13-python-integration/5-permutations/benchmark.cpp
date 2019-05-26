/**
 * Benchmark for computing all permutations
 */

#include "output_containers.hpp"
#include <algorithm>
#include <numeric>
using namespace std;

void benchmark(int N) {
	vector<int> v(N);
	auto begin = time(NULL);
	iota(v.begin(), v.end(), 1); // fill the vector with 1,...,N
	int count=0;
	cout << "Permutations of 1.." << N << ":" << endl;
	do {
		++count;
	} while ( next_permutation(v.begin(),v.end()) );
	auto end = time(NULL);
	auto duration = end-begin;
	cout << "  " << count << " permutations calculated in " << duration << " seconds" << endl;
}

int main() {
	for (int i=5;i<=13; ++i)
		benchmark(i);
	return 0;
}
