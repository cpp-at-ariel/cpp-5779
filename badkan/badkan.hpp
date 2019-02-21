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

#define CHECK_OK(actual) check_ok([&](){actual;})
#define CHECK_THROWS(actual) check_throws([&](){actual;})
#define CHECK_EQUAL(actual,expected) check_equal([&](){return actual;}, expected)
#define CHECK_OUTPUT(actual,expected) check_equal([&](){ostringstream ostr; ostr<<"'"<<actual<<"'"; return ostr.str();}, "'"+string(expected)+"'")

// #define CHECK_OUTPUT(actual,expected) check_output([&](){return actual;}, expected)
#define CHECK_INPUT(actual,expected) check_input(actual, expected)

#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <csignal>
#include <csetjmp>
using std::string, std::ostream, std::endl, std::cerr, std::exception, std::ostringstream,  std::istringstream;


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



  /** Checks that the given function is OK, i.e., does not throw an exception */
  template<typename TFUNC> TestCase& check_ok(const TFUNC actual_func) { 
    try {
      get_actual_value<TFUNC,void>(actual_func);
      passed++;
    } catch(...) {}
    return *this;
  }
  
  /** Checks that the given function throws an exception */
  template<typename TFUNC> TestCase& check_throws(const TFUNC actual_func) { 
    try {
      actual_func();
      failed++;
      output << title() << "There should be an exception!" << endl;
    } catch(...) {
      passed++;
    }
    return *this;
  }

  template<typename TFUNC, typename TVAL> TestCase& check_equal(const TFUNC actual_func, const TVAL& expected_value) {
    try {
      TVAL actual_value = get_actual_value<TFUNC,TVAL>(actual_func);
      if (incorrect(actual_value==expected_value))
        output << title() << "the result was " << actual_value << " but it should equal " << expected_value << "!" << endl;
    } catch(...) {}
    return *this;
  }

private:
  
  string title() {
    return name + " test #" + std::to_string(total()) + ": ";
  }
  
  template<typename TFUNC, typename TVAL> TVAL get_actual_value(TFUNC actual_func) {
    try {
      return actual_func();
    } catch (const string& message) {
      failed++;
      output << title() << "There was an exception: " << message << endl;
      throw;
    } catch (const exception& ex) {
      failed++;
      output << title() << "There was an exception: " << ex.what() << endl;
      throw;
    } catch (...) {
      failed++;
      output << title() << "There was an exception." << endl;
      throw;
    }
  }

  bool incorrect(bool condition) {
    if (condition) {
      passed++;
      return false;
    } else {
      failed++;
      return true;
    }
  }

}; // end class TestCase

}; // end namespace badkan
