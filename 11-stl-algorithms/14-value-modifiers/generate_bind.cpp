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

default_random_engine generator;
uniform_int_distribution<int> distribution(1,6);

int powers_of_two() {
	static int n=1;
	n *= 2;
	return n;
}

int powers_of_k(int k) {
	static int n=1;
	n *= k;
	return n;
}

int main() {
	// Demonstrates the generate algorithm:	
	vector<int> v1 (10);
	generate(v1.begin(), v1.end(), powers_of_two);
	cout << v1 << endl  << endl;

	// Demonstrates the bind function:
	auto powers_of_three = bind(powers_of_k, 3);
	// cout << powers_of_three();
	//generate(v1.begin(), v1.end(), powers_of_k); // compile error
	generate(v1.begin(), v1.end(), powers_of_three);
	//generate(v1.begin(), v1.end(), bind(powers_of_k, 3));
	cout << v1 << endl  << endl;

	// Demonstrates the distribution generator:
	for (int i=0; i<10; ++i)
		cout << distribution(generator) << " "; // dice roll
	cout << endl << endl;

	// Demonstrates the bind function:
	auto dice = bind(distribution, generator);
	for (int i=0; i<10; ++i)
		cout << dice() << " "; // same dice roll
	cout << endl << endl;

	// Demonstrates generate+bind:
	generate(v1.begin(), v1.end(), bind(distribution,generator) );
	cout << v1 << endl  << endl;
}
