/**
 * @author Ofir Pele
 * @since 2017
 */

#include "Complex.hpp"

#include "gtest/gtest.h"
#include <sstream>

TEST(Complex, ctors) {
	Complex c1;
	EXPECT_EQ(0.0, c1.re());
	EXPECT_EQ(0.0, c1.im());

	double d= 42.2;
	Complex c2(d);
	EXPECT_EQ(d, c2.re());
	EXPECT_EQ(0.0, c2.im());

	double d1= 42.2;
	double d2= -33.32;
	Complex c3(d1, d2);
	EXPECT_EQ(d1, c3.re());
	EXPECT_EQ(d2, c3.im());
		
}

TEST(Complex, opeq) {
	double d1= 42.2;
	double d2= -33.32;
	Complex c1(d1, d2);
	Complex c2(d1, d2);

	EXPECT_EQ(c1, c1);
	EXPECT_EQ(c1, c2);
	EXPECT_EQ(c2, c1);
	EXPECT_EQ(c2, c2);
}

TEST(Complex, opneq) {
	double d1= 42.2;
	double d2= -33.32;
	double d3= 0.2;
	Complex c1(d1, d2);
	Complex c2(d1+d3, d2);
	
	EXPECT_NE(c1, c2);
}

TEST(Complex, opadd) {
	Complex c1(10.0, -2.5);
	Complex c2(5, 3);
	Complex c3(15, 0.5);
	
	EXPECT_EQ(c3, c2+c1);
}

TEST(Complex, opmult) {
	Complex c1(10.0, -2.5);
	Complex c2(5, 3);
	Complex c3(10*5+2.5*3, 30-2.5*5);
	
	EXPECT_EQ(c3, c2*c1);
}

TEST(Complex, opsassign) {
	double d1= 42.2;
	double d2= -33.32;
	Complex c1(d1, d2);
	Complex c2(d1+0.33, d2+0.3232);
	c2= c1;
	
	EXPECT_EQ(c1, c2);

	c2= c2+c2;
	EXPECT_NE(c1, c2);
}

TEST(Complex, opsassignadd) {
	Complex c1(10.0, -2.5);
	Complex c2(5, 3);
	Complex c3(15, 0.5);
	
	EXPECT_EQ(c3, c1+=c2);
	EXPECT_EQ(c3, c1);
	
}

TEST(Complex, opsassignadd2) {
	Complex c1(10.0, -2.5);
	Complex c3(20, -5);
	
	EXPECT_EQ(c3, c1+=c1);
	EXPECT_EQ(c3, c1);

}

TEST(Complex, opassignmult) {
	Complex c1(10.0, -2.5);
	Complex c2(5, 3);
	Complex c3(10*5+2.5*3, 30-2.5*5);
	
	EXPECT_EQ(c3, c1*=c2);
	EXPECT_EQ(c3, c1);
}

TEST(Complex, opassignmult2) {
	Complex c1(10.0, -2);
	Complex c2(100-4, -40);
	
	EXPECT_EQ(c2, c1*=c1);
	EXPECT_EQ(c2, c1);
}

TEST(Complex, opunaryminus) {
	Complex c1(100, -2);
	Complex c2(-100, 2);
	
	EXPECT_EQ(c2, -c1);
}

TEST(Complex, output1) {
	stringstream ss;
	Complex c1(3, 4);
	ss << c1;
	EXPECT_EQ("3+4i", ss.str());
}

TEST(Complex, output2) {
	stringstream ss;
	Complex c1(-23, 4);
	ss << c1;
	EXPECT_EQ("-23+4i", ss.str());
}

TEST(Complex, input1) {
	stringstream ss("3+5i");
	Complex c1(3, 5);
	Complex c2;
	ss >> c2;
	EXPECT_EQ(c1,c2);
}

TEST(Complex, input2) {
	stringstream ss("3+5ifdsa");
	Complex c1(3, 5);
	Complex c2;
	ss >> c2;
	EXPECT_EQ(c1,c2);
}

TEST(Complex, input3) {
	stringstream ss("3+5i-100 +234i");
	Complex c1(3, 5);
	Complex c2(-100, 234);
	Complex c3;
	ss >> c3;
	EXPECT_EQ(c1,c3);	
	ss >> c3;
	EXPECT_EQ(c2,c3);	
}


TEST(Complex, input4) {
	stringstream ss("3+5i-100 +234i432");
	Complex c1(3, 5);
	Complex c2(-100, 234);
	Complex c3;
	ss >> c3;
	EXPECT_EQ(c1,c3);	
	ss >> c3;
	EXPECT_EQ(c2,c3);	
}



TEST(Complex, inputerr1) {
	string str1("a");
	stringstream ss(str1);
	Complex c1;
	ss >> c1;
	EXPECT_FALSE(ss);
	// checks rewind
	string str2;
	ss.clear();
	ss >> str2;
	EXPECT_EQ(str1,str2);
}

TEST(Complex, inputerr2) {
	string str1("3");
	stringstream ss(str1);
	Complex c1;
	ss >> c1;
	EXPECT_FALSE(ss);
	// checks rewind
	string str2;
	ss.clear();
	ss >> str2;
	EXPECT_EQ(str1,str2);
}

TEST(Complex, inputerr3) {
	string str1("3+");
	stringstream ss(str1);
	Complex c1;
	ss >> c1;
	EXPECT_FALSE(ss);
	// checks rewind
	string str2;
	ss.clear();
	ss >> str2;
	EXPECT_EQ(str1,str2);
}

TEST(Complex, inputerr4) {
	string str1("3+");
	stringstream ss(str1);
	Complex c1;
	ss >> c1;
	EXPECT_FALSE(ss);
	// checks rewind
	string str2;
	ss.clear();
	ss >> str2;
	EXPECT_EQ(str1,str2);
}

TEST(Complex, inputerr5) {
	string str1("3+4");
	stringstream ss(str1);
	Complex c1;
	ss >> c1;
	EXPECT_FALSE(ss);
	// checks rewind
	string str2;
	ss.clear();
	ss >> str2;
	EXPECT_EQ(str1,str2);
}

TEST(Complex, inputerr6) {
	string str1("3+4f");
	stringstream ss(str1);
	Complex c1;
	ss >> c1;
	EXPECT_FALSE(ss);
	// checks rewind
	string str2;
	ss.clear();
	ss >> str2;
	EXPECT_EQ(str1,str2);
}

//...



