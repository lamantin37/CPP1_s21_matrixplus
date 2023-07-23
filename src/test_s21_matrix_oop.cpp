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
  matrix2(1, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(1, 1) = 2;

  matrix3(0, 0) = 2;
  matrix3(1, 0) = 2;
  matrix3(0, 1) = 4;
  matrix3(1, 1) = 4;

  matrix1 *= matrix2;
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
  matrix2(1, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(1, 1) = 2;

  matrix3(0, 0) = 2;
  matrix3(1, 0) = 2;
  matrix3(0, 1) = 4;
  matrix3(1, 1) = 4;

  matrix1 = matrix1 * matrix2;
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
  matrix2(1, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(1, 1) = 2;

  matrix3(0, 0) = 2;
  matrix3(1, 0) = 2;
  matrix3(0, 1) = 4;
  matrix3(1, 1) = 4;

  matrix1.mul_matrix(matrix2);
  EXPECT_TRUE(matrix1 == matrix3);
}

TEST(MatrixTest, 16) {
  S21Matrix matrix1(2, 1);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 3;
  matrix1(1, 0) = -6.6;

  matrix2(0, 0) = -7;
  matrix2(0, 1) = 0;
  matrix2(1, 0) = -3.5;
  matrix2(1, 1) = 2;

  EXPECT_THROW(matrix1.mul_matrix(matrix2), invalid_argument);
}

TEST(MatrixTest, 17) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = -14;
  matrix1(0, 1) = 0;
  matrix1(1, 0) = -7;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = -7;
  matrix2(0, 1) = 0;
  matrix2(1, 0) = -3.5;
  matrix2(1, 1) = 2;

  EXPECT_TRUE(matrix1.eq_matrix(matrix2 * 2));
}

TEST(MatrixTest, 18) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = -14;
  matrix1(0, 1) = 0;
  matrix1(1, 0) = -7;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = -7;
  matrix2(0, 1) = 0;
  matrix2(1, 0) = -3.5;
  matrix2(1, 1) = 2;

  EXPECT_TRUE(matrix1.eq_matrix(2 * matrix2));
}

TEST(MatrixTest, 19) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = -14;
  matrix1(0, 1) = 0;
  matrix1(1, 0) = -7;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = -7;
  matrix2(0, 1) = 0;
  matrix2(1, 0) = -3.5;
  matrix2(1, 1) = 2;

  EXPECT_TRUE(matrix1.eq_matrix(2 * matrix2));
}

TEST(MatrixTest, 20) {
  S21Matrix matrix1(3, 3);
  S21Matrix matrix2(3, 3);
  S21Matrix matrix3(3, 3);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;
  matrix1(2, 0) = 5;
  matrix1(2, 1) = 6;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(0, 2) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;
  matrix2(1, 2) = 6;

  matrix3(0, 0) = 9;
  matrix3(0, 1) = 12;
  matrix3(0, 2) = 15;
  matrix3(1, 0) = 19;
  matrix3(1, 1) = 26;
  matrix3(1, 2) = 33;
  matrix3(2, 0) = 29;
  matrix3(2, 1) = 40;
  matrix3(2, 2) = 51;

  EXPECT_TRUE(matrix3.eq_matrix(matrix1 * matrix2));
}

TEST(MatrixTest, 21) {
  S21Matrix matrix1(2, 2);

  matrix1(0, 0) = 1;
  matrix1(1, 0) = 2;
  matrix1(0, 1) = 3;
  matrix1(1, 1) = 4;

  EXPECT_TRUE(matrix1.determinant() == -2);
}

TEST(MatrixTest, 22) {
  S21Matrix matrix1(3, 2);

  EXPECT_THROW(matrix1.determinant(), invalid_argument);
}

TEST(MatrixTest, 23) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 4;

  EXPECT_TRUE(matrix1.eq_matrix(matrix2.transpose()));
}

TEST(MatrixTest, 24) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = -3;
  matrix2(1, 0) = -2;
  matrix2(1, 1) = 1;

  EXPECT_TRUE(matrix2.eq_matrix(matrix1.calc_complements()));
}

TEST(MatrixTest, 25) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = -2;
  matrix2(0, 1) = 1;
  matrix2(1, 0) = 1.5;
  matrix2(1, 1) = -0.5;

  EXPECT_TRUE(matrix2.eq_matrix(matrix1.inverse_matrix()));
}

TEST(MatrixTest, 26) {
  S21Matrix matrix1(3, 3);

  matrix1(0, 0) = 2;
  matrix1(0, 1) = 5;
  matrix1(0, 2) = 7;
  matrix1(1, 0) = 6;
  matrix1(1, 1) = 3;
  matrix1(1, 2) = 4;
  matrix1(2, 0) = 5;
  matrix1(2, 1) = -2;
  matrix1(2, 2) = -3;

  ASSERT_EQ(matrix1.getRows(), 3);
  ASSERT_EQ(matrix1.getCols(), 3);
}

TEST(MatrixTest, 27) {
  S21Matrix matrix1(3, 3);
  S21Matrix result(3, 2);

  matrix1(0, 0) = 2;
  matrix1(0, 1) = 5;
  matrix1(0, 2) = 7;
  matrix1(1, 0) = 6;
  matrix1(1, 1) = 3;
  matrix1(1, 2) = 4;
  matrix1(2, 0) = 5;
  matrix1(2, 1) = -2;
  matrix1(2, 2) = -3;

  result(0, 0) = 2;
  result(0, 1) = 5;

  result(1, 0) = 6;
  result(1, 1) = 3;

  result(2, 0) = 5;
  result(2, 1) = -2;
  matrix1.setCols(2);

  ASSERT_TRUE(matrix1 == result);

  S21Matrix matrix2(3, 3);
  S21Matrix result2(2, 3);

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 5;
  matrix2(0, 2) = 7;
  matrix2(1, 0) = 6;
  matrix2(1, 1) = 3;
  matrix2(1, 2) = 4;
  matrix2(2, 0) = 5;
  matrix2(2, 1) = -2;
  matrix2(2, 2) = -3;

  result2(0, 0) = 2;
  result2(0, 1) = 5;
  result2(0, 2) = 7;
  result2(1, 0) = 6;
  result2(1, 1) = 3;
  result2(1, 2) = 4;

  matrix2.setRows(2);
  ASSERT_TRUE(matrix2 == result2);
}

TEST(MatrixTest, 28) {
  S21Matrix matrix1(2, 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(matrix1);

  EXPECT_TRUE(matrix1.eq_matrix(matrix2));
}

int main(int argc, char *argv[]) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
