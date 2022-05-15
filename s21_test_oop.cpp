#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

TEST(MatrixCreateTest, HandlesErrorCreate) {
  EXPECT_THROW(S21Matrix matrixOne(-2, 7), std::exception);
}

TEST(MatrixEqualTest, HandlesZeroMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(3, 3);
  matrixOne.sum_matrix(matrixTwo);
  bool check = matrixOne.eq_matrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixEqualTest, HandlesFalseMatrixInput) {
  S21Matrix matrixOne(1, 3);
  S21Matrix matrixTwo(3, 3);
  bool one = matrixOne.eq_matrix(matrixTwo);
  EXPECT_EQ(one, false);
}

TEST(MatrixEqualTest, HandlesIncorrectMatrixInput) {
  S21Matrix matrixOne(3, 3);
  matrixOne.form_matrix();
  S21Matrix matrixTwo(3, 3);
  matrixTwo.form_matrix();
  matrixTwo.set_value(1, 2, 0);
  bool check = matrixOne.eq_matrix(matrixTwo);
  EXPECT_EQ(check, false);
}

TEST(MatrixSumTest, HandlesZeroMatrixInput) {
  S21Matrix matrixOne;
  S21Matrix matrixTwo(2, 2);
  matrixOne.sum_matrix(matrixTwo);
  bool check = matrixOne.eq_matrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixSumTest, HandlesMatrixInput) {
  S21Matrix matrixOne(5, 5);
  S21Matrix matrixTwo(5, 5);
  matrixOne.form_matrix();
  matrixTwo.sum_matrix(matrixOne);
  bool check = matrixOne.eq_matrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixSumTest, HandlesMatrixInputCorrect) {
  S21Matrix matrixOne(5, 5);
  S21Matrix matrixTwo(5, 5);
  matrixOne.form_matrix();
  matrixTwo.form_matrix();
  matrixOne.sum_matrix(matrixTwo);
  matrixTwo *= 2;
  bool check = matrixOne.eq_matrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixSumTest, HandlesErrorMatrixInput) {
  S21Matrix matrixOne(1, 3);
  S21Matrix matrixTwo(3, 3);
  EXPECT_THROW(matrixOne.sum_matrix(matrixTwo), std::exception);
}

TEST(MatrixSubTest, HandlesZeroMatrixInput) {
  S21Matrix matrixOne;
  S21Matrix matrixTwo(2, 2);
  matrixOne.sub_matrix(matrixTwo);
  bool check = matrixOne.eq_matrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixSubTest, HandlesMatrixInput) {
  S21Matrix matrixOne(5, 5);
  S21Matrix matrixTwo(5, 5);
  S21Matrix matrixZero(5, 5);
  matrixOne.form_matrix();
  matrixTwo.form_matrix();
  matrixOne.sub_matrix(matrixTwo);
  bool check = matrixOne.eq_matrix(matrixZero);
  EXPECT_EQ(check, true);
}

TEST(MatrixSubTest, HandlesMatrixInputCorrect) {
  S21Matrix matrixOne(5, 5);
  S21Matrix matrixTwo(5, 5);
  matrixOne.form_matrix();
  matrixTwo.form_matrix();
  matrixOne *= 2;
  matrixOne.sub_matrix(matrixTwo);
  bool check = matrixOne.eq_matrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixSubTest, HandlesErrorMatrixInput) {
  S21Matrix matrixOne(1, 3);
  S21Matrix matrixTwo(3, 3);
  EXPECT_THROW(matrixOne.sub_matrix(matrixTwo), std::exception);
}

TEST(MatrixSubTest, HandlesErrorTwoMatrixInput) {
  S21Matrix matrixOne(2, 7);
  S21Matrix matrixTwo(2, 3);
  EXPECT_THROW(matrixOne.sub_matrix(matrixTwo), std::exception);
}

TEST(MatrixMulTest, HandlesZeroMatrixInput) {
  S21Matrix matrixOne;
  S21Matrix matrixTwo(2, 3);
  matrixOne.mul_matrix(matrixTwo);
  bool check = matrixOne.eq_matrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixMulTest, HandlesDifferentMatrixInput) {
  S21Matrix matrixOne(3, 3);
  matrixOne.form_matrix();
  S21Matrix matrixTwo(3, 1);
  matrixTwo.set_value(0, 0, 1.0);
  matrixTwo.set_value(1, 0, 2.0);
  matrixTwo.set_value(2, 0, 3.0);
  matrixOne.mul_matrix(matrixTwo);
  S21Matrix matrixResult(3, 1);
  matrixResult.set_value(0, 0, 8.0);
  matrixResult.set_value(1, 0, 14.0);
  matrixResult.set_value(2, 0, 20.0);
  bool check = matrixOne.eq_matrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(MatrixMulTest, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(3, 3);
  S21Matrix matrixThree(3, 3);
  matrixOne.form_matrix();
  matrixTwo.form_matrix();
  matrixOne.mul_matrix(matrixTwo);
  matrixThree.set_value(0, 0, 5.0);
  matrixThree.set_value(0, 1, 8.0);
  matrixThree.set_value(0, 2, 11.0);
  matrixThree.set_value(1, 0, 8.0);
  matrixThree.set_value(1, 1, 14.0);
  matrixThree.set_value(1, 2, 20.0);
  matrixThree.set_value(2, 0, 11.0);
  matrixThree.set_value(2, 1, 20.0);
  matrixThree.set_value(2, 2, 29.0);
  bool check = matrixOne.eq_matrix(matrixThree);
  EXPECT_EQ(check, true);
}

TEST(MatrixMulTest, HandlesErrorMatrixInput) {
  S21Matrix matrixOne(2, 7);
  S21Matrix matrixTwo(2, 3);
  EXPECT_THROW(matrixOne.mul_matrix(matrixTwo), std::exception);
}

TEST(MatrixTransposeTest, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(3, 3);
  matrixOne.form_matrix();
  matrixTwo.form_matrix();
  matrixOne.transpose();
  bool check = matrixOne.eq_matrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixTransposeTest, HandlesNotEqualInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(3, 3);
  matrixOne.form_matrix();
  matrixTwo.form_matrix();
  matrixTwo.set_value(0, 0, 4.0);
  matrixOne.transpose();
  bool check = matrixOne.eq_matrix(matrixTwo);
  EXPECT_EQ(check, false);
}

TEST(MatrixCalcComplecsTest, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  matrixOne.form_matrix();
  matrixOne.set_value(2, 2, 5.0);
  double test[] = {1, 1, -1, 1, -4, 2, -1, 2, -1};
  S21Matrix matrixResult = matrixOne.calc_complements();
  for (int i = 0, k = 0; i < matrixOne.getRows(); i++) {
    for (int j = 0; j < matrixOne.getCols(); j++) {
      EXPECT_EQ(matrixResult(i, j), test[k]);
      k++;
    }
  }
}

TEST(MatrixCalcComplecsTest, HandlesMatrix2_2Input) {
  S21Matrix matrixOne;
  matrixOne.form_matrix();
  double test[] = {2, -1, -1, 0};
  S21Matrix matrixResult = matrixOne.calc_complements();
  for (int i = 0, k = 0; i < matrixOne.getRows(); i++) {
    for (int j = 0; j < matrixOne.getCols(); j++) {
      EXPECT_EQ(matrixResult(i, j), test[k]);
      k++;
    }
  }
}

TEST(MatrixCalcComplecsTest, HandlesErrorMatrixInput) {
  S21Matrix matrixOne(2, 7);
  EXPECT_THROW(S21Matrix matrixResult = matrixOne.calc_complements(),
               std::exception);
}

TEST(MatrixDetermanantTest, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  matrixOne.form_matrix();
  matrixOne.set_value(2, 2, 5.0);
  double resultDet = matrixOne.determinant();
  EXPECT_EQ(resultDet, -1);
}

TEST(MatrixDetermanantTest, HandlesMatrixZeroInput) {
  S21Matrix matrixOne(3, 3);
  double result = matrixOne.determinant();
  EXPECT_EQ(result, 0);
}

TEST(MatrixDetermanantTest, HandlesMatrix1_1Input) {
  S21Matrix matrixOne(1, 1);
  matrixOne.set_value(0, 0, 2.0);
  double result = matrixOne.determinant();
  EXPECT_EQ(result, 2.0);
}

TEST(MatrixDetermanantTest, HandlesErrorMatrixInput) {
  S21Matrix matrixOne(3, 4);
  EXPECT_THROW(double result = matrixOne.determinant(), std::exception);
}

TEST(MatrixInverseTest, HandlesMatrixInput) {
  S21Matrix matrixOne(5, 5);
  matrixOne.form_matrix();
  matrixOne.set_value(2, 2, -4);
  matrixOne.set_value(2, 4, -6);
  matrixOne.set_value(3, 0, -3);
  matrixOne.set_value(3, 4, -7);
  matrixOne.set_value(4, 3, 6);
  matrixOne.set_value(4, 4, 6);
  double test[] = {108.75, -122, 1.75,  -2.5,  28,  -223.5,   250,   -3.5, 5,
                   -57, 70,  -78.5,   1, -1.5,   18, 90.5,   -101, 1.5,
                   -2, 23,  -46.75, 52.5, -0.75, 1,  -12};
  S21Matrix matrixResult = matrixOne.inverse_matrix();
  for (int i = 0, k = 0; i < matrixResult.getRows(); i++) {
    for (int j = 0; j < matrixResult.getCols(); j++) {
      bool result = false;
      if (fabs(matrixResult(i, j) - test[k]) < 1E-7) {
        result = true;
      }
      EXPECT_EQ(result, true);
      k++;
    }
  }
}

TEST(MatrixSubTestUnary, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixZero(3, 3);
  matrixOne.form_matrix();
  S21Matrix matrixTwo(matrixOne);
  matrixOne -= matrixTwo;
  bool check = matrixOne.eq_matrix(matrixZero);
  EXPECT_EQ(check, true);
}

TEST(MatrixSubTestBinary, HandlesMatrixInput) {
  S21Matrix matrixOne(4, 4);
  S21Matrix matrixZero(4, 4);
  matrixOne.form_matrix();
  S21Matrix matrixTwo(matrixOne);
  S21Matrix matrixResult = matrixOne - matrixTwo;
  bool check = matrixResult.eq_matrix(matrixZero);
  EXPECT_EQ(check, true);
}

TEST(MatrixSumTestUnary, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  matrixOne.form_matrix();
  S21Matrix matrixTwo(matrixOne);
  matrixOne += matrixTwo;
  S21Matrix matrixResult(matrixTwo);
  matrixResult.mul_number(2.0);
  bool check = matrixOne.eq_matrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(MatrixSumTestBinary, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  matrixOne.form_matrix();
  S21Matrix matrixTwo(matrixOne);
  S21Matrix matrixResult = matrixOne + matrixTwo;
  matrixOne.mul_number(2.0);
  bool check = matrixOne.eq_matrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(MatrixMulTestBinary, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(3, 3);
  S21Matrix matrixThree(3, 3);
  matrixOne.form_matrix();
  matrixTwo.form_matrix();
  S21Matrix matrixResult = matrixOne * matrixTwo;
  matrixThree.set_value(0, 0, 5.0);
  matrixThree.set_value(0, 1, 8.0);
  matrixThree.set_value(0, 2, 11.0);
  matrixThree.set_value(1, 0, 8.0);
  matrixThree.set_value(1, 1, 14.0);
  matrixThree.set_value(1, 2, 20.0);
  matrixThree.set_value(2, 0, 11.0);
  matrixThree.set_value(2, 1, 20.0);
  matrixThree.set_value(2, 2, 29.0);
  bool check = matrixResult == matrixThree;
  EXPECT_EQ(check, true);
}

TEST(MatrixMulTestUnary, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixThree(3, 3);
  S21Matrix matrixResult(3, 3);
  matrixOne.form_matrix();
  matrixResult.form_matrix();
  matrixResult *= matrixOne;
  matrixThree.set_value(0, 0, 5.0);
  matrixThree.set_value(0, 1, 8.0);
  matrixThree.set_value(0, 2, 11.0);
  matrixThree.set_value(1, 0, 8.0);
  matrixThree.set_value(1, 1, 14.0);
  matrixThree.set_value(1, 2, 20.0);
  matrixThree.set_value(2, 0, 11.0);
  matrixThree.set_value(2, 1, 20.0);
  matrixThree.set_value(2, 2, 29.0);
  bool check = matrixResult == matrixThree;
  EXPECT_EQ(check, true);
}

TEST(NumberMulTestBinary, HandlesMatrixInputRight) {
  S21Matrix matrixOne(3, 3);
  matrixOne.form_matrix();
  S21Matrix matrixResult = matrixOne * 2.0;
  matrixOne.mul_number(2.0);
  bool check = matrixResult == matrixOne;
  EXPECT_EQ(check, true);
}

TEST(NumberMulTestBinary, HandlesMatrixInputLeft) {
  S21Matrix matrixOne(3, 3);
  matrixOne.form_matrix();
  S21Matrix matrixResult = 2.0 * matrixOne;
  matrixOne.mul_number(2.0);
  bool check = matrixResult == matrixOne;
  EXPECT_EQ(check, true);
}

TEST(MoveConstruction, HandlesMatrixInputLeft) {
  S21Matrix matrixOne(3, 3);
  matrixOne.form_matrix();
  S21Matrix matrixResult(std::move(matrixOne));
  ASSERT_EQ(0, matrixOne.getCols());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
