using namespace std;

#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(EqMatrix, 1) {
  S21Matrix matrix1;
  S21Matrix matrix2;
  EXPECT_TRUE(matrix1.eq_matrix(matrix2));
}

TEST(EqMatrix, 2) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);
  EXPECT_TRUE(matrix1.eq_matrix(matrix2));
}

TEST(EqMatrix, 3) {
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

TEST(EqMatrix, 4) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 1);
  EXPECT_FALSE(matrix1.eq_matrix(matrix2));
}

TEST(EqMatrix, 5) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(1, 2);
  EXPECT_FALSE(matrix1.eq_matrix(matrix2));
}

TEST(EqMatrix, 6) {
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

TEST(EqMatrix, 7) {
  S21Matrix matrix1(2, 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(matrix1);

  EXPECT_TRUE(matrix1.eq_matrix(matrix2));
}

TEST(SumMatrix, 1) {
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

TEST(SumMatrix, 2) {
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

TEST(SumMatrix, 3) {
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

TEST(SubMatrix, 1) {
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

TEST(SubMatrix, 2) {
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

TEST(SubMatrix, 3) {
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

TEST(SubMatrix, 4) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 3);

  matrix1(0, 0) = 0.25;
  matrix1(0, 1) = 1.25;
  matrix1(0, 2) = 2.25;
  matrix1(1, 0) = 3.25;
  matrix1(1, 1) = 4.25;
  matrix1(1, 2) = 5.25;

  matrix2(0, 0) = 9.25;
  matrix2(0, 1) = 8.25;
  matrix2(0, 2) = 7.25;
  matrix2(1, 0) = 6.25;
  matrix2(1, 1) = 5.25;
  matrix2(1, 2) = 4.25;
  matrix2(2, 0) = 3.25;
  matrix2(2, 1) = 2.25;
  matrix2(2, 2) = 1.25;

  EXPECT_THROW(matrix1.sub_matrix(matrix2), invalid_argument);
}

TEST(MulMatrix, 1) {
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

TEST(MulMatrix, 2) {
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

TEST(MulMatrix, 3) {
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

TEST(MulMatrix, 4) {
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

TEST(MulMatrix, 5) {
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

TEST(MulMatrix, 6) {
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

TEST(MulMatrix, 7) {
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

TEST(MulMatrix, 8) {
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

TEST(MulNumber, 9) {
  S21Matrix matrix1(1, 1);
  matrix1(0, 0) = 3.3;
  matrix1.mul_number(3);
  EXPECT_DOUBLE_EQ(matrix1(0, 0), 9.9);
}

TEST(MulMatrix, 10) {
  S21Matrix matrix1(2, 5);
  matrix1(0, 0) = 3.0;
  matrix1(0, 1) = -3.0;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5.0;
  matrix2(0, 1) = 3.0;
  matrix2(1, 0) = 1.0;
  matrix2(1, 1) = 3.0;

  EXPECT_THROW(matrix1.mul_matrix(matrix2), invalid_argument);
}

TEST(DetMatrix, 1) {
  S21Matrix matrix1(2, 2);

  matrix1(0, 0) = 1;
  matrix1(1, 0) = 2;
  matrix1(0, 1) = 3;
  matrix1(1, 1) = 4;

  EXPECT_TRUE(matrix1.determinant() == -2);
}

TEST(DetMatrix, 2) {
  S21Matrix matrix1(5, 5);
  matrix1(0, 0) = 4.0;
  matrix1(0, 1) = 1.0;
  matrix1(0, 2) = 1.0;
  matrix1(0, 3) = 2.0;
  matrix1(0, 4) = 1.0;

  matrix1(1, 0) = 1.0;
  matrix1(1, 1) = 2.0;
  matrix1(1, 2) = -1.0;
  matrix1(1, 3) = 1.0;
  matrix1(1, 4) = 1.0;

  matrix1(2, 0) = 3.0;
  matrix1(2, 1) = 1.0;
  matrix1(2, 2) = 1.0;
  matrix1(2, 3) = 1.0;
  matrix1(2, 4) = 1.0;

  matrix1(3, 0) = 2.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;
  matrix1(3, 3) = 4.0;
  matrix1(3, 4) = 1.0;

  matrix1(4, 0) = 2.0;
  matrix1(4, 1) = -1.0;
  matrix1(4, 2) = 1.0;
  matrix1(4, 3) = 1.0;
  matrix1(4, 4) = 5.0;
  double result = matrix1.determinant();
  EXPECT_DOUBLE_EQ(result, 64.0);
}

TEST(DetMatrix, 3) {
  S21Matrix matrix1(3, 2);

  EXPECT_THROW(matrix1.determinant(), invalid_argument);
}

TEST(TransposeMatrix, 1) {
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

TEST(ComplementMatrix, 1) {
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

TEST(ComplementMatrix, 2) {
  S21Matrix matrix1(3, 3);
  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(0, 2) = 3.0;

  matrix1(1, 0) = 0.0;
  matrix1(1, 1) = 4.0;
  matrix1(1, 2) = 2.0;

  matrix1(2, 0) = 5.0;
  matrix1(2, 1) = 2.0;
  matrix1(2, 2) = 1.0;

  S21Matrix matrix2(3, 3);
  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 10.0;
  matrix2(0, 2) = -20.0;

  matrix2(1, 0) = 4.0;
  matrix2(1, 1) = -14.0;
  matrix2(1, 2) = 8.0;

  matrix2(2, 0) = -8.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 4.0;
  S21Matrix other_matrix = matrix1.calc_complements();
  EXPECT_EQ(other_matrix.eq_matrix(matrix2), true);
}

TEST(InverseMatrix, 1) {
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

TEST(InverseMatrix, 2) {
  S21Matrix matrix1(3, 3);
  matrix1(0, 0) = 2.0;
  matrix1(0, 1) = 5.0;
  matrix1(0, 2) = 7.0;

  matrix1(1, 0) = 6.0;
  matrix1(1, 1) = 3.0;
  matrix1(1, 2) = 4.0;

  matrix1(2, 0) = 5.0;
  matrix1(2, 1) = -2.0;
  matrix1(2, 2) = -3.0;

  S21Matrix matrix2(3, 3);
  matrix2(0, 0) = 1.0;
  matrix2(0, 1) = -1.0;
  matrix2(0, 2) = 1.0;

  matrix2(1, 0) = -38.0;
  matrix2(1, 1) = 41.0;
  matrix2(1, 2) = -34.0;

  matrix2(2, 0) = 27.0;
  matrix2(2, 1) = -29.0;
  matrix2(2, 2) = 24.0;
  S21Matrix other_matrix = matrix1.inverse_matrix();
  EXPECT_EQ(other_matrix.eq_matrix(matrix2), true);
  EXPECT_EQ(matrix1.eq_matrix(matrix2), false);
}

TEST(GetterMatrix, 1) {
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

TEST(SetterMatrix, 1) {
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

  matrix1.setRows(4);
  matrix1.setCols(4);
  ASSERT_EQ(matrix1.getRows(), 4);
  ASSERT_EQ(matrix1.getCols(), 4);
}

TEST(SetterMatrix, 2) {
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

TEST(SetterMatrix, 3) {
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

  EXPECT_THROW(matrix1.setRows(-1), invalid_argument);
}

TEST(SetterMatrix, 4) {
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

  EXPECT_THROW(matrix1.setCols(-1), invalid_argument);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
