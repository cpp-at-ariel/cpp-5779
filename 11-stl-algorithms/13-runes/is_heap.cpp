/**
 * Demonstrates STL is_heap algorithm.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;


template<typename T> void print_vector_as_tree_recursive(ostream& out, const vector<T>& v, uint root=0, string prefix="") {
	if (root >= v.size())
		return;
	out << endl << prefix << v[root];
	print_vector_as_tree_recursive(out, v, 2*root+1, prefix+"--");
	print_vector_as_tree_recursive(out, v, 2*root+2, prefix+"--");
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
	copy(v.begin(), v.end(), ostream_iterator<T>(out," "));
	print_vector_as_tree_recursive(out, v, 0, "");
	cout << endl;
	return out;
}


int main() {
	cout << boolalpha;
	cout << "Not a heap:" << endl;
	vector<int> v1{1,2,3,4,5,6,7,8,9};
	cout << v1 << endl;
	cout << is_heap(begin(v1), end(v1)) << endl;

	cout << "make_heap: " << endl;
	make_heap(begin(v1), end(v1));
	cout << v1 << endl;
	cout << is_heap(begin(v1), end(v1)) << endl;
}

