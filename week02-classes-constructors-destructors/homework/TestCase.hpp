#pragma once

#include <string>
#include <iostream>
#include <sstream>
using std::string;
using std::ostream;
using std::endl;
using std::cerr;
using std::istringstream;
using std::ostringstream;

class TestCase {
	string name;        // name of test-case.
	int passed, failed, total; // keeps the number of tests passed/failed so far.
	ostream& output;    // where all output will be sent.

	bool fails(bool passes) {
		if (passes) {
			passed++;
			total++;
			return false;
		} else {
			failed++;
			total++;
			output << name << ": " << "Failure in test #" << total<< ": ";
			return true;
		}
	}

public:
	ostream& print(ostream& out) const {
		int grade = (total==0? 0: 100*passed/total);
		return (out << "\n*** Right: " << passed << ". Wrong: " << failed << ". Grade: " << grade << " ***\n");
	}
	TestCase& print()  {
		print(this->output);
		// this->output << endl << "---" << endl;
		return *this;
	}
	TestCase(const string& name, ostream& output=cerr): 
		name(name), 
		output(output),
		passed(0), failed(0), total(0) {}
		
	template<typename T> TestCase& check_ok(const T) { 
		return *this;
	}

	template<typename T> TestCase& check_equal(const T& actual, const T& expected) {
		if (fails(actual==expected))
			output << "the result is " << actual << " but it should equal " << expected << "!" << endl;
		return *this;
	}
};
