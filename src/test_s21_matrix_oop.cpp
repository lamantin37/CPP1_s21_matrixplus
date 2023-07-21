using namespace std;

#include <gtest/gtest.h>
#include "s21_matrix_oop.h"

TEST(MatrixTest, EqMatrixElementsAreEqual) {
	S21Matrix matrix1;
	S21Matrix matrix2;
	EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

