/**
 * @author Ofir Pele
 * @since 2017
 */

#include "IntBuffer.hpp"
#include "gtest/gtest.h"

static int val(int i) {
	return i*3;
}

static void changeVals(IntBuffer& b, int multFactor= 1) {
	for (size_t i=0; i<b.size(); ++i) {
		b[i]= val(i)*multFactor;
	}
}

static void checkVals(const IntBuffer& b, int multFactor= 1) {
	for (size_t i=0; i<b.size(); ++i) {
		EXPECT_EQ(b[i], val(i)*multFactor);
	}
}

TEST(IntBuffer, simple) {
	constexpr size_t MAX_SIZE= 10; 
	for (size_t size= 0; size<MAX_SIZE; ++size) {
		IntBuffer b(size);
		EXPECT_EQ(b.size(), size);
		changeVals(b);
		checkVals(b);
	}
}

TEST(IntBuffer, copyCtor) {
	constexpr size_t MAX_SIZE= 10; 
	for (size_t size= 0; size<MAX_SIZE; ++size) {
		IntBuffer b(size);
		EXPECT_EQ(b.size(), size);
		changeVals(b);
		checkVals(b);

		IntBuffer b2(b);
		EXPECT_EQ(b2.size(), size);
		checkVals(b2);

		for (size_t i=0; i<b.size(); ++i) {
			b2[i]= 9999;
			EXPECT_EQ(b2[i],9999);
			checkVals(b); // b should not change!
		}
	}
}

TEST(IntBuffer, assignOp) {
	constexpr size_t MAX_SIZE= 10; 
	for (size_t size= 0; size<MAX_SIZE; ++size) {
		for (double d=0.5; d<=6; d+=0.5) {

			IntBuffer b(size);
			EXPECT_EQ(b.size(), size);
			changeVals(b);
			checkVals(b);
			
			IntBuffer b2(size*d);
			changeVals(b2,3);
			checkVals(b2,3);
			
			b2= (b=b); // checks also self assignment
			EXPECT_EQ(b2.size(),b.size());
			checkVals(b2);
			
			changeVals(b,1999);
			checkVals(b2); // b2 should not change
			changeVals(b2,18);
			checkVals(b,1999); // b should not change
		}
	}
}

