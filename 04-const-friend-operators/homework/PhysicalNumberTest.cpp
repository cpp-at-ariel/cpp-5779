/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  PhysicalNumber a(2, Unit::KM);
  PhysicalNumber b(300, Unit::M);
  PhysicalNumber c(2, Unit::HOUR);
  PhysicalNumber d(30, Unit::MIN);
  badkan::TestCase ("Physical number")
  .CHECK_OUTPUT(a, "2[km]")
  .CHECK_OUTPUT(b, "300[m]")
  .CHECK_OUTPUT(b+a, "2300[m]")
  .CHECK_OUTPUT(a+=b, "2.3[km]")
  .CHECK_OUTPUT(a, "2.3[km]")
  .CHECK_OUTPUT(a+a, "4.6[km]")
  .CHECK_OUTPUT(b-b, "0[m]")
  .CHECK_OUTPUT(c, "2[hour]")
  .CHECK_OUTPUT(d, "30[min]")
  .CHECK_OUTPUT(d+c, "150[min]")
  .CHECK_THROWS(a+c)
  .CHECK_THROWS(a+d)
  .CHECK_THROWS(b+c)
  .CHECK_THROWS(b+d)
  .CHECK_OK("700[kg]" >> a)
  .CHECK_OUTPUT(a += PhysicalNumber(1, Unit::TON), "1700[kg]")
  .print();
}
