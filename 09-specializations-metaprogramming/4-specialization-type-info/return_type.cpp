/**
 * Using template-class-specialization to control return-type
 * 
 * @author M Salters
 * @url    https://stackoverflow.com/a/26876959/827927
 */

#include <iostream>
using namespace std;

template <typename ArgumentType>
struct ReturnType {
  ArgumentType argument;
};

template <> struct ReturnType<int> {
  double argument;
};

template <class T> decltype(ReturnType<T>::argument) divide(T number) {
	decltype(ReturnType<T>::argument) result = number/10.0;
  return result;
}

int main() {
	cout << divide(35) << endl;
}
