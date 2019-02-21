/**
 * Defines the class TestCase, that represents a test-case 
 * in an automatic testing program.
 *
 * Use the macros CHECK_EQUAL and CHECK_OK for testing, e.g.:
 
   badkan::TestCase ("title")
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
#define CHECK_OUTPUT(actual,expected) check_output([&](){return actual;}, expected)
#define CHECK_INPUT(actual,expected) check_input(actual, expected)

#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <csignal>
#include <csetjmp>
using std::string, std::ostream, std::endl, std::cerr, std::exception;


namespace badkan {

/* The following code is used for catching signals (e.g. for timeout) during the execution. */
jmp_buf longjmp_buffer;        // A buffer to hold info on where to jump to.

void catch_signal(int signal_number) {
    longjmp (longjmp_buffer,signal_number);
}


class TestCase {
  string name;         // Name of test-case - for showing in error messages
  int passed, failed;  // Number of tests passed/failed so far.
  ostream& output;     // Stream to which the error messages will be sent.
  clock_t  start_time; // time in which the test-case is constructed.

public:
   TestCase(const string& name, ostream& output=cerr): 
     name(name),
     output(output),
     passed(0), failed(0),
     start_time(clock())
     {
       std::signal(SIGTERM, catch_signal);
     }
  
  int right() const { return this->passed; }
  int wrong() const { return this->failed; }
  int total() const { return failed+passed; }
  int grade() const { return (total()==0? 0: 100*passed/total()); }
  
  ostream& print(ostream& out, bool show_grade=true) const {
    double elapsed_seconds = double(clock() - start_time) / CLOCKS_PER_SEC;
    out << endl << "*** CPU time: " << elapsed_seconds << " sec.  Right: " << passed << ".  Wrong: " << failed << ". ";
    if (show_grade) out << "Grade: " << grade() << ". ";
    out << "***" << endl;
    return out;
  }

  TestCase& print()  {
    print(this->output, /*show_grade=*/true);
    return *this;
  }
  
  TestCase& print_timeout()  {
    this->output << "Your program timed out! (caught signal TERM)" << endl;
    print(this->output, /*show_grade=*/false);
    return *this;
  }



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
  
	template<typename TFUNC> TestCase& check_output(const TFUNC actual_func, const string& expected_string) {
    try {
      string actual_string = get_actual_string(actual_func);
      if (incorrect(actual_string==expected_string))
        output << "the result-string is " << actual_string << " but it should equal " << expected_string << "!" << endl;
    } catch(...) {}
		return *this;
	}

	template<typename TVAL> TestCase& check_input(const string& input, const TVAL& expected_value) {
		istringstream istr(input);
		TVAL actual_value;
		istr >> actual_value;
		if (fails(actual_value==expected_value))
			output << "object generated from " << input << " should be " << expected_value << " but is " << actual_value << endl;
		return *this;
	}

private:
  
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
  
  template<typename TFUNC> string get_actual_string(TFUNC actual_func) {
    try {
      ostringstream ostr;
  		ostr << actual_func();
  		return ostr.str();
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

}; // end class TestCase

}; // end namespace badkan
