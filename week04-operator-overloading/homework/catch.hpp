/**
 * A replacement for catch.hpp
 * that compiles faster.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2018-04
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
using namespace std;

vector<function<void()>> tests;

int numPass, numFail;

int main() {
    for (int i=0; i<tests.size(); ++i)
        tests[i]();
    int numTotal = numPass + numFail;
    cout << "assertions: " << numTotal << " | " << numPass << " passed | " << numFail << " failed" << endl;
}

#define REQUIRE(condition) \
if (condition) { \
    numPass++; \
} else { \
    numFail++; \
}

#define REQUIRE_THROWS(condition) \
try { \
	condition; \
	numFail++; \
} catch (...) { \
	numPass++; \
}

#define REQUIRE_NOTHROW(condition) \
try { \
	condition; \
	numPass++; \
} catch (...) { \
	numFail++; \
}

struct RegisterTest {
	RegisterTest(function<void()> theTest) {
		tests.push_back(theTest);
	}
};

#define INTERNAL_CATCH_UNIQUE_NAME_LINE2( name, line ) name##line
#define INTERNAL_CATCH_UNIQUE_NAME_LINE( name, line ) INTERNAL_CATCH_UNIQUE_NAME_LINE2( name, line )
#define INTERNAL_CATCH_UNIQUE_NAME( name ) INTERNAL_CATCH_UNIQUE_NAME_LINE( name, __LINE__ )

#define TEST_CASE(name,params) \
	void INTERNAL_CATCH_UNIQUE_NAME(test)(); \
	RegisterTest INTERNAL_CATCH_UNIQUE_NAME(register){INTERNAL_CATCH_UNIQUE_NAME(test)}; \
	void INTERNAL_CATCH_UNIQUE_NAME(test)()
