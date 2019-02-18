#include "output_containers.hpp"
#include <algorithm>
using namespace std;

int main() {
	cout << "vector" << endl;
	vector<int> v1 {11,1,2,4,7,16,22};
	cout << v1 << endl;
	sort(v1.begin(), v1.end());
	cout << v1 << endl;

	cout << "list" << endl;
	list<int> l1 {11,1,2,4,7,16,22};
	cout << l1 << endl;
	//sort(l1.begin(), l1.end());  // cryptic error message
	l1.sort();
	cout << l1 << endl;
}
