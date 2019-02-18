#include "output_containers.hpp"
#include <algorithm>
#include <random>
#include <functional>
using namespace std;

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,6);
auto dice = bind(distribution, generator);

int main() {
	for (int i=0; i<100; ++i)
		cout << distribution(generator) << " "; // dice roll
	cout << endl << endl;
	
	vector<int> v1 (100);
	generate(v1.begin(), v1.end(), dice);
	cout << v1 << endl;
}
