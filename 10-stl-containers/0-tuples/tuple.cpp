/**
 * Demonstrates tuples as return values.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <tuple>
using namespace std;

tuple<int,char,string> f_full() {
	return tuple<int,char,string>{5,'a',"hello"};
}

tuple<int,char,string> f_automatic_constructor() {
	return {5,'a',"hello"};
}

auto f_automatic_returntype() {
	return tuple<int,char,string>{5,'a',string("hello")};
}

// Implementation of make_tuple 
//    (STL has a more general implementation)
template<typename T1, typename T2, typename T3>
auto make_tuple(T1 a1, T2 a2, T3 a3) {
	return tuple<T1,T2,T3>{a1,a2,a3};
}

auto f_automatic_both() {
 	return make_tuple(5,'a',"hello");
}

// auto f_automatic_none() {
// 	return {5,'a',"hello"};
// }

auto f_automatic_bug() {
	return (5,'a',"hello");
}


int main() {
	auto f = f_full;
	auto [ii,cc,ss] = f();
	// Equivalent to:

	// auto tt = f();
	// auto ii = std::get<0>(tt);
	// auto cc = std::get<1>(tt);
	// auto ss = std::get<2>(tt);


	cout << ii << " " << cc << " " << ss << endl;

	// cout << h() << endl;
}
