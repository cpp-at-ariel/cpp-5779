/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber;
#include "badkan.hpp"

int main() {
  PhysicalNumber a(2, "km");
  PhysicalNumber b(300, "m");
  badkan::TestCase ("Physical number")
  .CHECK_OUTPUT(a, "2[km]")
  .CHECK_OUTPUT(b, "300[m]")
  .CHECK_OUTPUT(b+a, "2300[m]")
  .CHECK_OUTPUT(a+=b, "2.3[km]")
  .CHECK_OUTPUT(a, "2.3[km]")
  .CHECK_OUTPUT(a+a, "4.6[km]")
  .CHECK_OUTPUT(b-b, "0[m]")
  .print();
}
