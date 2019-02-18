#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "CircularInt.hpp"
#include "catch.hpp"

std::string cirToString(const CircularInt &circularInt)
{
    std::stringstream ss;
    ss << circularInt ;
    return ss.str();
}
TEST_CASE("Add","+")
{
    CircularInt hour {1, 12};
    hour = hour + 4;
    std::stringstream ss;
    ss << hour ;
    REQUIRE(ss.str() == "5");
	CircularInt hour2 {1, 12};
	hour2 = 4 + hour ;
	std::stringstream ss2;
	ss2<<hour2;
	REQUIRE(ss2.str() == "9");
	hour = hour + hour ;
    std::stringstream ss3;
    ss3<<hour;
    REQUIRE(ss3.str() == "10");
    hour = hour + hour ;
    std::stringstream ss4;
    ss4<<hour;
    REQUIRE(ss4.str() == "8");
}