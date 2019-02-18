#include "Rational.hpp"

#include "gtest/gtest.h"

TEST(rational, rational_tests1)
{
    Rational r1(2,4);
    Rational r2(1,1);
       
    EXPECT_EQ(1, r1.getNumerator());
	EXPECT_EQ(2, r1.getDenominator());
	EXPECT_EQ(Rational(3,2), r1+r2);
	EXPECT_EQ(Rational(1,2), r1*r2);
}
