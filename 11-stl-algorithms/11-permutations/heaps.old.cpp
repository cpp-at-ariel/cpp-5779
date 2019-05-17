/**
 * Demonstrates STL heap algorithms.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;


// helpers for printing a vector as a heap or as a vector

class as_tree_class {};
as_tree_class as_tree;
class as_list_class {};
as_list_class as_list;

bool print_vector_as_tree = false;
ostream& operator<<(ostream& out, as_tree_class x) {
	print_vector_as_tree = true;
	return out;
}

ostream& operator<<(ostream& out, as_list_class x) {
	print_vector_as_tree = false;
	return out;
}


template<typename T> void print_vector_as_tree_recursive(ostream& out, const vector<T>& v, uint root=0, string prefix="") {
	if (root >= v.size())
		return;
	out << endl << prefix << v[root];
	print_vector_as_tree_recursive(out, v, 2*root+1, prefix+"--");
	print_vector_as_tree_recursive(out, v, 2*root+2, prefix+"--");
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
	if (print_vector_as_tree) {
		print_vector_as_tree_recursive(out, v, 0, "");
	} else {
		copy(v.begin(), v.end(), ostream_iterator<T>(out," "));
	}	
	return out;
}


int main() {
	cout << "A heap:" << endl;
	vector<int> v{9,8,6,7,4,5,2,0,3,1};
	cout << as_list << "v as list: " << v << endl;
	cout << as_tree << "v as tree: " << v << endl << endl;

	cout << "Not a heap:" << endl;
	vector<int> v1{1,2,3,4,5,6,7,8,9};
	cout << as_list << "v1 as list: " << v1 << endl;
	cout << as_tree << "v1 as tree: " << v1 << endl << endl;

	cout << "make_heap:" << endl;
	make_heap(v1.begin(), v1.end());
	cout << as_list << "v1 as list: " << v1 << endl;
	cout << as_tree << "v1 as tree: " << v1 << endl << endl;

	v1.push_back(10);
	cout << "After push_back - not a heap:" << v1 << endl << endl;
	push_heap(v1.begin(), v1.end());
	cout << "push_heap:" << v1 << endl << endl;


	pop_heap(v1.begin(), v1.end());
	cout << "pop_heap:" << v1 << endl << endl;
	cout << "popped maximum element:" << v1.back() << endl;
	v1.pop_back();
	cout << "After pop_back:" << v1 << endl << endl;
}

