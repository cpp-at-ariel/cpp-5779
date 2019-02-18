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

TEST_CASE("equals","==")
{
    CircularInt hour {1, 10};
    CircularInt hour2 {1, 10};
    bool test1 = (hour == hour2);
    REQUIRE(test1);
    REQUIRE(hour == 1 );
    REQUIRE( 1 == hour );
}
