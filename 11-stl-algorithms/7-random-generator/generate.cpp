/**
 * Random number generator
 * Demonstrates the "generate" algorithm 
 * and the "bind" function.
 */

#include "output_containers.hpp"
#include <algorithm>
#include <random>
#include <functional>
using namespace std;

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,6);

int num() {
	static int n=0;
	return n++;
}

int main() {
	// Demonstrates the generate algorithm:	
	vector<int> v1 (100);
	generate(v1.begin(), v1.end(), num);
	cout << v1 << endl  << endl;

	// Demonstrates the distribution generator:
	for (int i=0; i<100; ++i)
		cout << distribution(generator) << " "; // dice roll
	cout << endl << endl;

	// Demonstrates the bind function:
	auto dice = bind(distribution, generator);
	for (int i=0; i<100; ++i)
		cout << dice() << " "; // same dice roll
	cout << endl << endl;

	// Demonstrates generate+bind:
	generate(v1.begin(), v1.end(), bind(distribution,generator) );
	cout << v1 << endl  << endl;
}
