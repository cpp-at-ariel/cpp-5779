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
TEST_CASE("submit","-")
{
    CircularInt hour {1, 12};
    hour = hour - 3;
    REQUIRE(cirToString(hour) == "10");
    CircularInt hour2 {1, 12};
    hour2 = 2 - hour ;
    REQUIRE(cirToString(hour2) == "4");
    hour = hour - hour2 ;
    REQUIRE(cirToString(hour) == "6");
}
