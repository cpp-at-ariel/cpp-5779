/**
 * Defines the class TestCase, that represents a test-case 
 * in an automatic testing program.
 *
 * Use the macros CHECK_EQUAL and CHECK_OK for testing, e.g.:
 
	 TestCase ("title")
	 .CHECK_OK(do_something())
	 .CHECK_EQUAL(sum(1,2), 3)
	 .CHECK_EQUAL(factorial(5), 120)
	 .CHECK_OK(do_something_else())
	 .print();
 *
 * @author Erel Segal-Halevi
 * @credit Nathan Oliver: https://stackoverflow.com/a/54752705/827927
 * @since 2019-02
 * 
 */

#pragma once

#define CHECK_EQUAL(actual,expected) check_equal([&](){return actual;}, expected)
#define CHECK_OK(actual) check_ok([&](){actual;})


#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
using std::string, std::ostream, std::endl, std::cerr, std::exception;

class TestCase {
	string name;        // Name of test-case - for showing in error messages
	int passed, failed; // Number of tests passed/failed so far.
	ostream& output;    // Stream to which the error messages will be sent.

	template<typename TFUNC, typename TVAL> TVAL get_actual_value(TFUNC actual_func) {
		try {
			return actual_func();
		} catch (const string& message) {
      failed++;
			output << name << ": " << "Exception in test #" << total() << ": " << message << endl;
			throw;
		} catch (const exception& ex) {
      failed++;
			output << name << ": " << "Exception in test #" << total() << ": " << ex.what() << endl;
			throw;
		} catch (...) {
      failed++;
			output << name << ": " << "Exception in test #" << total() << ".";
			throw;
		}
	}

	bool incorrect(bool condition) {
		if (condition) {
			passed++;
			return false;
		} else {
			failed++;
			output << name << ": " << "Failure in test #" << total() << ": ";
			return true;
		}
	}

public:
  int right() const { return this->passed; }
  int wrong() const { return this->failed; }
  int total() const { return failed+passed; }
  int grade() const { return (total()==0? 0: 100*passed/total()); }
  
	ostream& print(ostream& out) const {
		return (out << "\n*** Right: " << passed << ". Wrong: " << failed << ". Grade: " << grade() << " ***\n");
	}
  
	TestCase& print()  {
		print(this->output);
		return *this;
	}
 
	TestCase(const string& name, ostream& output=cerr): 
		name(name), 
		output(output),
		passed(0), failed(0) {}
		
	template<typename TFUNC> TestCase& check_ok(const TFUNC actual_func) { 
		try {
			get_actual_value<TFUNC,void>(actual_func);
			passed++;
		} catch(...) {}
		return *this;
	}

	template<typename TFUNC, typename TVAL> TestCase& check_equal(const TFUNC actual_func, const TVAL& expected_value) {
		try {
			TVAL actual_value = get_actual_value<TFUNC,TVAL>(actual_func);
			if (incorrect(actual_value==expected_value))
				output << "the result is " << actual_value << " but it should equal " << expected_value << "!" << endl;
		} catch(...) {}
		return *this;
	}
};
