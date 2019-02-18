
#include <iostream>
using namespace std;

#include "CircularInt.hpp"

class CircularInt {
	CircularInt& operator/=(const CircularInt& other) {
		...
		throw {...}
	}

	const CircularInt operator/(const CircularInt& other) {
		CircularInt result = *this;
		result /= other;
		return result;
	}

	CircularInt& operator+= (int x) {
		...
	}

	CircularInt& operator+= (const CircularInt& x) {
		//return this->operator+=(x.number);
		return (*this) += x.number;
	}

	const CircularInt operator+ (int x) {
		CircularInt result = *this;
		result += x;
		return result;
	}
}

int main() {
	CircularInt hour {1, 12};                 // <hour is an integer between 1 and 12, like an hour on the clock>
	cout << hour << endl;                     // 1
	hour += 4;  cout << hour << endl;         // 5
	(hour += 2)++;  cout << hour << endl;     // 8
	hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
	cout << -hour << endl;                    // 10  (2 hours before midnight)
	hour = 1 - hour; cout << hour << endl;    // 11  (2 hours before 1)
	cout << hour+hour << endl;                // 10 (11 hours after 11)
	hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
	cout << hour/2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).

	try {
		cout << hour/3;
	} catch (const string& message) {
		cout << message << endl;     // "There is no number x in {1,12} such that x*3=10"
	}

	// RIDDLES (not for submission): 
	//  * when is there exactly one answer to a/b?
	//  * when are there two or more answers to a/b?
	//	* when is there no answer to a/b?
}
