#include "output_containers.hpp"
#include <algorithm>
using namespace std;

int main() {
	vector<int> v1 {1,2,4,7,11,16,22};
	cout << v1 << endl;

	vector<int> v2;
	//copy(v1.begin(), v1.end(), v2.begin());  // segmentation fault
	copy(v1.begin(), v1.end(), back_inserter(v2));
	cout << v2 << endl;
}
