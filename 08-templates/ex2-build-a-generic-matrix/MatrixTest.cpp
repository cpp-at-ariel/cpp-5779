#include "Matrix.hpp"

#include "gtest/gtest.h"

TEST(matrix, matrix_test)
{
	Matrix<int> mat1(1, 1, std::vector<int>(1,2));

	EXPECT_EQ(1, mat1.getRowNum());
	EXPECT_EQ(1, mat1.getColNum());

	int t= 0;
	EXPECT_TRUE(mat1.hasTrace(t));
    EXPECT_TRUE(mat1.isSquareMatrix());
    
	Matrix<int> transpose_mat= mat1;
	EXPECT_EQ(transpose_mat, mat1.transpose());

	Matrix<int> mat2(1, 1, std::vector<int>(1,3));
    Matrix<int> add_mat(1, 1, std::vector<int> (1,5));
	EXPECT_EQ(add_mat, mat1+mat2);

	Matrix<int> multi_mat(1, 1, std::vector<int>(1,6));
	EXPECT_EQ(multi_mat, mat1*mat2);

	Matrix<int> scalar_multi_mat(1, 1, std::vector<int>(1,4));
	EXPECT_EQ(scalar_multi_mat, mat1*2);
}
