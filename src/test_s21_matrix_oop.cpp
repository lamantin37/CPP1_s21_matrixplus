using namespace std;

#include <gtest/gtest.h>
#include "s21_matrix_oop.h"

TEST(MatrixTest, 1) {
	S21Matrix matrix1;
	S21Matrix matrix2;
	EXPECT_TRUE(matrix1.eq_matrix(matrix2));
}

TEST(MatrixTest, 2) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);
	EXPECT_TRUE(matrix1.eq_matrix(matrix2));
}

TEST(MatrixTest, 3) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);

	matrix1(0, 0) = 1;
	matrix1(1, 0) = 1;
	matrix1(0, 1) = 1;
	matrix1(1, 1) = 1;

	matrix2(0, 0) = 1;
	matrix2(1, 0) = 1;
	matrix2(0, 1) = 1;
	matrix2(1, 1) = 1;

	EXPECT_TRUE(matrix1.eq_matrix(matrix2));
}

TEST(MatrixTest, 4) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 1);
	EXPECT_FALSE(matrix1.eq_matrix(matrix2));
}

TEST(MatrixTest, 5) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(1, 2);
	EXPECT_FALSE(matrix1.eq_matrix(matrix2));
}

TEST(MatrixTest, 6) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);

	matrix1(0, 0) = 1;
	matrix1(1, 0) = 1;
	matrix1(0, 1) = 1;
	matrix1(1, 1) = 1;

	matrix2(0, 0) = 1;
	matrix2(1, 0) = 1;
	matrix2(0, 1) = 1;
	matrix2(1, 1) = 2;

	EXPECT_FALSE(matrix1.eq_matrix(matrix2));
}

TEST(MatrixTest, 7) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);
	S21Matrix matrix3(2, 2);

	matrix1(0, 0) = 1;
	matrix1(1, 0) = 1;
	matrix1(0, 1) = 1;
	matrix1(1, 1) = 1;

	matrix2(0, 0) = 1;
	matrix2(1, 0) = 2;
	matrix2(0, 1) = 1;
	matrix2(1, 1) = 2;

	matrix3(0, 0) = 2;
	matrix3(1, 0) = 3;
	matrix3(0, 1) = 2;
	matrix3(1, 1) = 3;

	matrix1 += matrix2;
	EXPECT_TRUE(matrix1 == matrix3);
}

TEST(MatrixTest, 8) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);
	S21Matrix matrix3(2, 2);

	matrix1(0, 0) = 1;
	matrix1(1, 0) = 1;
	matrix1(0, 1) = 1;
	matrix1(1, 1) = 1;

	matrix2(0, 0) = 1;
	matrix2(1, 0) = 2;
	matrix2(0, 1) = 1;
	matrix2(1, 1) = 2;

	matrix3(0, 0) = 2;
	matrix3(1, 0) = 3;
	matrix3(0, 1) = 2;
	matrix3(1, 1) = 3;

	matrix1 = matrix1 + matrix2;
	EXPECT_TRUE(matrix1 == matrix3);
}

TEST(MatrixTest, 9) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);
	S21Matrix matrix3(2, 2);

	matrix1(0, 0) = 1;
	matrix1(1, 0) = 1;
	matrix1(0, 1) = 1;
	matrix1(1, 1) = 1;

	matrix2(0, 0) = 1;
	matrix2(1, 0) = 2;
	matrix2(0, 1) = 1;
	matrix2(1, 1) = 2;

	matrix3(0, 0) = 2;
	matrix3(1, 0) = 3;
	matrix3(0, 1) = 2;
	matrix3(1, 1) = 3;

	matrix1.sum_matrix(matrix2);
	EXPECT_TRUE(matrix1 == matrix3);
}

TEST(MatrixTest, 10) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);
	S21Matrix matrix3(2, 2);

	matrix1(0, 0) = 1;
	matrix1(1, 0) = 1;
	matrix1(0, 1) = 1;
	matrix1(1, 1) = 1;

	matrix2(0, 0) = 1;
	matrix2(1, 0) = 2;
	matrix2(0, 1) = 1;
	matrix2(1, 1) = 2;

	matrix3(0, 0) = 0;
	matrix3(1, 0) = -1;
	matrix3(0, 1) = 0;
	matrix3(1, 1) = -1;

	matrix1 -= matrix2;
	EXPECT_TRUE(matrix1 == matrix3);
}

TEST(MatrixTest, 11) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);
	S21Matrix matrix3(2, 2);

	matrix1(0, 0) = 1;
	matrix1(1, 0) = 1;
	matrix1(0, 1) = 1;
	matrix1(1, 1) = 1;

	matrix2(0, 0) = 1;
	matrix2(1, 0) = 2;
	matrix2(0, 1) = 1;
	matrix2(1, 1) = 2;

	matrix3(0, 0) = 0;
	matrix3(1, 0) = -1;
	matrix3(0, 1) = 0;
	matrix3(1, 1) = -1;

	matrix1 = matrix1 - matrix2;
	EXPECT_TRUE(matrix1 == matrix3);
}

TEST(MatrixTest, 12) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);
	S21Matrix matrix3(2, 2);

	matrix1(0, 0) = 1;
	matrix1(1, 0) = 1;
	matrix1(0, 1) = 1;
	matrix1(1, 1) = 1;

	matrix2(0, 0) = 1;
	matrix2(1, 0) = 2;
	matrix2(0, 1) = 1;
	matrix2(1, 1) = 2;

	matrix3(0, 0) = 0;
	matrix3(1, 0) = -1;
	matrix3(0, 1) = 0;
	matrix3(1, 1) = -1;

	matrix1.sub_matrix(matrix2);
	EXPECT_TRUE(matrix1 == matrix3);
}

TEST(MatrixTest, 13) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);
	S21Matrix matrix3(2, 2);

	matrix1(0, 0) = 1;
	matrix1(1, 0) = 1;
	matrix1(0, 1) = 1;
	matrix1(1, 1) = 1;

	matrix2(0, 0) = 1;
	matrix2(1, 0) = 2;
	matrix2(0, 1) = 1;
	matrix2(1, 1) = 2;

	matrix3(0, 0) = 2;
	matrix3(1, 0) = 4;
	matrix3(0, 1) = 2;
	matrix3(1, 1) = 4;

	matrix1 *= matrix2;
	cout << matrix1(0, 0) << endl;
	cout << matrix1(1, 0) << endl;
	cout << matrix1(0, 1) << endl;
	cout << matrix1(1, 1) << endl;
	EXPECT_TRUE(matrix1 == matrix3);
}

TEST(MatrixTest, 14) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);
	S21Matrix matrix3(2, 2);

	matrix1(0, 0) = 1;
	matrix1(1, 0) = 1;
	matrix1(0, 1) = 1;
	matrix1(1, 1) = 1;

	matrix2(0, 0) = 1;
	matrix2(1, 0) = 2;
	matrix2(0, 1) = 1;
	matrix2(1, 1) = 2;

	matrix3(0, 0) = 2;
	matrix3(1, 0) = 4;
	matrix3(0, 1) = 2;
	matrix3(1, 1) = 4;

	matrix1 = matrix1 * matrix2;
	cout << matrix1(0, 0) << endl;
	cout << matrix1(1, 0) << endl;
	cout << matrix1(0, 1) << endl;
	cout << matrix1(1, 1) << endl;
	EXPECT_TRUE(matrix1 == matrix3);
}

TEST(MatrixTest, 15) {
	S21Matrix matrix1(2, 2);
	S21Matrix matrix2(2, 2);
	S21Matrix matrix3(2, 2);

	matrix1(0, 0) = 1;
	matrix1(1, 0) = 1;
	matrix1(0, 1) = 1;
	matrix1(1, 1) = 1;

	matrix2(0, 0) = 1;
	matrix2(1, 0) = 2;
	matrix2(0, 1) = 3;
	matrix2(1, 1) = 4;

	matrix3(0, 0) = 2;
	matrix3(1, 0) = 4;
	matrix3(0, 1) = 2;
	matrix3(1, 1) = 4;

	matrix1.mul_matrix(matrix2);
	cout << matrix1(0, 0) << endl;
	cout << matrix1(1, 0) << endl;
	cout << matrix1(0, 1) << endl;
	cout << matrix1(1, 1) << endl;
	EXPECT_TRUE(matrix1 == matrix3);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

