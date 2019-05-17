/**
 * Using template-class-specialization to create type-information
 * 
 * @author ?
 * @url    ?
 */

#include <iostream>
#include <cassert>
using namespace std;


template<typename T> struct is_numeric {
	static const bool value = false;
};

template<>    struct is_numeric<int> {
	static const bool value = true;
};

template<>    struct is_numeric<double>  {
	static const bool value = true;
};

template<typename T> T add(T a, T b) {
    static_assert(is_numeric<T>::value, 
	 	"Can only be numeric type");
	// assert(is_numeric<T>::value); 
	return a+b;
}

class A {
	static const int i=5;
};

int main() {
	cout << boolalpha;
    cout << is_numeric<int>::value << '\n';
    cout << add(5,6) << '\n';
	cout << is_numeric<char>::value << '\n'; 
	float f;
	add(f,f);
    // cout << add('a','b') << '\n';
}
