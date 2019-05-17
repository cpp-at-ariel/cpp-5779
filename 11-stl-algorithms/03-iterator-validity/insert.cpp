#include "output_containers.hpp"
using namespace std;

int main() {
	{
		vector<int> v {1,2,4,7,11,16,22};
		cout << v << endl;
		v.insert(v.begin(),0);
		cout << v << endl;
		auto it = v.begin();
		++it;
		++it;
		++it;
		++it;
		cout << "*it=" << *it << endl;
		v.insert(it,5);
		cout << "*it=" << *it << endl;
		cout << v << endl;
		v.insert(it,6);
		cout << "*it=" << *it << endl;
		cout << v << endl;

		//int capacity_before = v.capacity();
		v.emplace_back(99);
		v.emplace_back(99);
		v.emplace_back(99);
		v.emplace_back(99);
		v.emplace_back(99);
		v.emplace_back(99);
		v.emplace_back(99);
		//int capacity_after = v.capacity();
		cout << v << endl;
		v.insert(it,55);
		cout << v << endl;
	}
}
