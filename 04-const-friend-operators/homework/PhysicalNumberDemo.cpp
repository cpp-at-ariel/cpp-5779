/**
 * Demo file for the exercise on physical numbers
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
#include <stdexcept>
using std::cout, std::endl, std::boolalpha, std::istringstream;
#include "PhysicalNumber.h"
#include "Unit.h"
using ariel::PhysicalNumber, ariel::Unit;

int main() {
  try {
    PhysicalNumber a(2, Unit::KM);   // 2 kilometers
    PhysicalNumber b(300, Unit::M);  // 300 meters
    cout << a << endl;   // Prints "2[km]"
    cout << (a+b) << endl;   // Prints "2.3[km]"
    cout << (b-a) << endl;   // Prints "-1700[m]"
    cout << (-a) << endl;   // Prints "-2[km]"

    cout << boolalpha; // print booleans as strings from now on:
    cout << (a>b) << endl;  // Prints "true"
    cout << (a<=b) << endl;  // Prints "false"
    cout << (a==PhysicalNumber(2000, Unit::M)) << endl;  // Prints "true"

    istringstream input("700[kg]");
    input >> a;
    cout << a << endl;   // Prints "700[kg]"
    cout << (a += PhysicalNumber(1, Unit::TON)) << endl;  // prints "1700[kg]"
    cout << a << endl;   // Prints "1700[kg]" since a has changed.

    try {
      cout << (a+b) << endl;  
    } catch (const std::exception& ex) {
      cout << ex.what() << endl; // Prints "Units do not match - [m] cannot be converted to [kg]"
    }
  } catch (...) {
    cout << "Unexpected exception!" << endl;
  }
  return 100;
}
