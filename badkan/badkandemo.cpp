#include "badkan.hpp"

int f(int x) {
	return x+1;
}

int g(int x) {
	throw string("hahaha");
}

struct C {
	int size() const { return 5; }
};

int main() {
	const C obj1,obj2;
	badkan::TestCase ("f")
	.CHECK_EQUAL(obj1.size(), 5)
	.CHECK_EQUAL(obj1.size()+obj2.size(), 10)
	.CHECK_EQUAL(f(1), 2)
	.CHECK_EQUAL(g(2), 3)   //  f test #4: There was an exception: hahaha
	.CHECK_EQUAL(f(2), 3)
	.CHECK_EQUAL(f(3), 5)   // f test #6: the result was 4 but it should equal 5!
	.CHECK_OK(g(4))         // f test #7: There was an exception: hahaha
	.CHECK_OK(f(4))
	.CHECK_EQUAL(f(3), 4)
	.CHECK_OUTPUT(f(3)*f(3), "16") 
	.CHECK_OUTPUT(f(3)*f(3), "17")   // f test #11: the result was '16' but it should equal '17'!
	.CHECK_OUTPUT(g(4), "55")        // f test #12: There was an exception: hahaha
	.CHECK_THROWS(g(4))
	.CHECK_THROWS(f(4))              // f test #14: There should be an exception!
	.print();
	return 0;
}
