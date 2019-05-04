/**
 * Using template-class-specialization to create type-information
 * 
 * @author ?
 * @url    ?
 */

#include <iostream>
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
    static_assert(is_numeric<T>::value, "Can only be numeric type");
	return a+b;
}

int main() {
	cout << boolalpha;
    cout << is_numeric<int>::value << '\n';
    cout << add(5,6) << '\n';
	cout << is_numeric<char>::value << '\n'; 
    cout << add('a','b') << '\n';
}
