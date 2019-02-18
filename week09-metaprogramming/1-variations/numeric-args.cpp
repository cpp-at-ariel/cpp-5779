#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <typename T, int n, T defval> class array {
	T vals[n];
public:
	array() { 
		for (int i=0; i<n; i++)
			vals[i]=defval;
	}
	T& operator[](int i) {
		assert(i<n);
		return vals[i];
	}
	T operator[](int i) const {
		assert(i<n);
		return vals[i];
	}

	static const int size = n;
};

template <typename T, int n, T defval> 
ostream& operator<< (ostream& out, const array<T,n,defval>& thearray) {
	for (int i=0; i<n; ++i)
		out << thearray[i] << " ";
	return out;
}


int main() {
	array<int,5,55> array5;
	cout << array5 << endl;
	array5[0] = 99999;
	cout << array5 << endl;
	cout << "size of array5 = " << array5.size << endl << endl;

	array<int,3,33> array3;     // a different class!
	cout << array3 << endl;  // a different operator<<!
	array3[0] = 99999;
	cout << array3 << endl;
	cout << "size of array3 = " << array3.size << endl << endl;

	const int i=7;
	array<int,i,77> array7;

	array7[0] = 99999;
	cout << array7 << endl;
	cout << "size of array7 = " << array7.size << endl << endl;

	// const char* abc="abc";
	// array<char*,6, abc> array6;
	// cout << "size of array6 = " << array6.size << endl << endl;
	// cout << array6 << endl;
	// cout << "size of array6 = " << array6.size << endl << endl;

	string a="xbc";
	string b="def";
	cout << std::boolalpha << (a<b) << endl;
}
