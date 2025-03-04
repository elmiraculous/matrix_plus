#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

class matrixTest : public testing::Test {
 protected:
  S21Matrix matrix_33_a;
  S21Matrix matrix_33_b;
  S21Matrix matrix_transpose;
  S21Matrix matrix_inverse;
  S21Matrix matrix_calc_c;
  S21Matrix matrix_Sub_row;
  S21Matrix matrix_Sum_col;
  S21Matrix matrix_32_c;

  void SetUp() {
    matrix_33_a = S21Matrix(3, 3);
    matrix_33_a(0, 0) = 3.0;
    matrix_33_a(0, 1) = 1.0;
    matrix_33_a(0, 2) = 2.0;
    matrix_33_a(1, 0) = 4.0;
    matrix_33_a(1, 1) = 0.0;
    matrix_33_a(1, 2) = 2.0;
    matrix_33_a(2, 0) = 1.0;
    matrix_33_a(2, 1) = 0.0;
    matrix_33_a(2, 2) = 1.5;

    matrix_inverse = S21Matrix(3, 3);
    matrix_inverse(0, 0) = -0.0;
    matrix_inverse(0, 1) = 0.375;
    matrix_inverse(0, 2) = -0.5;
    matrix_inverse(1, 0) = 1.0;
    matrix_inverse(1, 1) = -0.625;
    matrix_inverse(1, 2) = -0.5;
    matrix_inverse(2, 0) = -0.0;
    matrix_inverse(2, 1) = -0.25;
    matrix_inverse(2, 2) = 1.0;

    matrix_33_b = S21Matrix(3, 3);
    matrix_33_b(0, 0) = 43.3;
    matrix_33_b(0, 1) = 1.0;
    matrix_33_b(0, 2) = 0.41;
    matrix_33_b(1, 0) = 4.0;
    matrix_33_b(1, 1) = 0.0;
    matrix_33_b(1, 2) = -6.0;
    matrix_33_b(2, 0) = -7.0;
    matrix_33_b(2, 1) = 0.0;
    matrix_33_b(2, 2) = -9.0;

    matrix_transpose = S21Matrix(3, 3);
    matrix_transpose(0, 0) = 43.3;
    matrix_transpose(0, 1) = 4.0;
    matrix_transpose(0, 2) = -7.0;
    matrix_transpose(1, 0) = 1.0;
    matrix_transpose(1, 1) = 0.0;
    matrix_transpose(1, 2) = 0.0;
    matrix_transpose(2, 0) = 0.41;
    matrix_transpose(2, 1) = -6.0;
    matrix_transpose(2, 2) = -9.0;

    matrix_calc_c = S21Matrix(3, 3);
    matrix_calc_c(0, 0) = 0.0;
    matrix_calc_c(0, 1) = 78.0;
    matrix_calc_c(0, 2) = 0.0;
    matrix_calc_c(1, 0) = 9.0;
    matrix_calc_c(1, 1) = -386.83;
    matrix_calc_c(1, 2) = -7.0;
    matrix_calc_c(2, 0) = -6.0;
    matrix_calc_c(2, 1) = 261.44;
    matrix_calc_c(2, 2) = -4.0;

    matrix_Sub_row = S21Matrix(2, 3);
    matrix_Sub_row(0, 0) = 0.0;
    matrix_Sub_row(0, 1) = 78.0;
    matrix_Sub_row(0, 2) = 0.0;
    matrix_Sub_row(1, 0) = 9.0;
    matrix_Sub_row(1, 1) = -386.83;
    matrix_Sub_row(1, 2) = -7.0;

    matrix_Sum_col = S21Matrix(3, 3);
    matrix_Sum_col(0, 0) = 0.0;
    matrix_Sum_col(0, 1) = 78.0;
    matrix_Sum_col(0, 2) = 0.0;
    matrix_Sum_col(1, 0) = 9.0;
    matrix_Sum_col(1, 1) = -386.83;
    matrix_Sum_col(1, 2) = 0.0;
    matrix_Sum_col(2, 0) = -6.0;
    matrix_Sum_col(2, 1) = 261.44;
    matrix_Sum_col(2, 2) = 0.0;

    matrix_32_c = S21Matrix(3, 2);
    matrix_32_c(0, 0) = 0.0;
    matrix_32_c(0, 1) = 78.0;
    matrix_32_c(1, 0) = 9.0;
    matrix_32_c(1, 1) = -386.83;
    matrix_32_c(2, 0) = -6.0;
    matrix_32_c(2, 1) = 261.44;
  }
};

 TEST_F(matrixTest, set_row) {
   S21Matrix x(3, 3), y(2, 3);
   x = matrix_calc_c;
   y = matrix_Sub_row;
   x.SetRows(2);
   EXPECT_EQ(x == y, true);
 }

TEST_F(matrixTest, set_col) {
  S21Matrix x(3, 2), y(3, 3);
  x = matrix_32_c;
  y = matrix_Sum_col;
  x.SetCols(3);
  EXPECT_EQ(x == y, true);
}

TEST(MatrixSumTest, copyConstructor) {
  S21Matrix m(2, 3);
  S21Matrix res(m);
  EXPECT_EQ(res.GetRows(), 2);
  EXPECT_EQ(res.GetCols(), 3);
  EXPECT_EQ(m == res, true);
}

TEST(MatrixSumTest, moveConstructor) {
  S21Matrix m(2, 3);
  S21Matrix res(std::move(m));
  EXPECT_EQ(res.GetRows(), 2);
  EXPECT_EQ(res.GetCols(), 3);
  EXPECT_EQ(m.GetRows(), 0);
  EXPECT_EQ(m.GetCols(), 0);
}

 TEST(MatrixSumTest, SetRows) {
   S21Matrix m(2, 3);
   m(1, 1) = 4.4;
   EXPECT_EQ(m(1, 1), 4.4);
   EXPECT_EQ(m.GetRows(), 2);
   EXPECT_EQ(m.GetCols(), 3);
 }

TEST(MatrixSumTest, copy) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a = b;
  EXPECT_DOUBLE_EQ(a(1, 1), 2.2);
}

TEST(MatrixSumTest, badCreate) {
     EXPECT_ANY_THROW(S21Matrix a(0, 0););
 }

TEST(functionalFuncTest, inverseMatrix) {
  S21Matrix m(3, 3);
  m(0, 0) = 4.0;
  m(0, 1) = -2.0;
  m(0, 2) = 1.0;
  m(1, 0) = 1.0;
  m(1, 1) = 6.0;
  m(1, 2) = -2.0;
  m(2, 0) = 1.0;
  m(2, 1) = 0.0;
  m(2, 2) = 0.0;

  m = m.InverseMatrix();

  EXPECT_EQ(m(0, 1), 0.0);
  EXPECT_EQ(m(0, 2), 1.0);
  EXPECT_EQ(m(1, 0), 1.0);
  EXPECT_EQ(m(2, 0), 3.0);
  EXPECT_EQ(m(2, 1), 1.0);
  EXPECT_EQ(m(2, 2), -13.0);
}

TEST(functionalFuncTest, inverseMatrixEx) {
  S21Matrix m(3, 3);

  m(0, 0) = 1.0;
  m(0, 1) = 1.0;
  m(0, 2) = 3.0;
  m(1, 0) = 4.0;
  m(1, 1) = 4.0;
  m(1, 2) = 6.0;
  m(2, 0) = 4.0;
  m(2, 1) = 4.0;
  m(2, 2) = 9.0;
  EXPECT_EQ(m.Determinant(), 0.0);
  EXPECT_ANY_THROW(m.InverseMatrix());
}

TEST(functionalFuncTest, inverseMatrixEx2) {
  S21Matrix m(3, 3);

  m(0, 0) = 1.0;
  m(0, 1) = 4.0;
  m(0, 2) = 1.0;
  m(1, 0) = 3.0;
  m(1, 1) = 7.0;
  m(1, 2) = 2.0;
  m(2, 0) = 3.0;
  m(2, 1) = 2.0;
  m(2, 2) = 1.0;
  EXPECT_EQ(m.Determinant(), 0.0);
  EXPECT_ANY_THROW(m.InverseMatrix());
}

TEST(functionalFuncTest, inverseMatrixEx3) {
  S21Matrix m(3, 2);
  EXPECT_ANY_THROW(m.InverseMatrix());
}

TEST(functionalFuncTest, bracketEx) {
  S21Matrix m(1, 1);
  EXPECT_ANY_THROW(m(5, 0) = 5.0);
}

TEST(functionalFuncTest, bracketEx2) {
  S21Matrix m(1, 1);
  EXPECT_ANY_THROW(m(5, 0) = 5.0);
}

TEST(functionalFuncTest, bracketEx3) {
  S21Matrix m(3, 3);
  m(1, 1) = 1.0;
  EXPECT_EQ(m(1, 1), 1.0);
  EXPECT_ANY_THROW(m(-1, -1));
  EXPECT_ANY_THROW(m(0, -1));
  EXPECT_ANY_THROW(m(-1, 1));
}

TEST(functionalFuncTest, bracketEx4) {
  S21Matrix m(3, 3);
  m(1, 1) = 1.0;
  EXPECT_EQ(m(1, 1), 1.0);
  EXPECT_ANY_THROW(m(-1, -1));
  EXPECT_ANY_THROW(m(0, -1));
  EXPECT_ANY_THROW(m(-1, 1));
}

TEST(MatrixSumTest, Sum) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  S21Matrix res = a + b;
  EXPECT_DOUBLE_EQ(res(1, 1), 3.3);
}

TEST(MatrixSumTest, SumEx) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  EXPECT_ANY_THROW(S21Matrix res = a + b);
}

TEST(MatrixSumTest, Sum2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a += b;
  EXPECT_DOUBLE_EQ(a(1, 1), 3.3);
}

TEST(functionalTest, SumEx2) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  EXPECT_ANY_THROW(a += b);
}

TEST(functionalTest, Sum3) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a.SumMatrix(b);
  EXPECT_DOUBLE_EQ(a(1, 1), 3.3);
}

TEST(functionalTest, Sub) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  S21Matrix res = a - b;
  EXPECT_DOUBLE_EQ(res(1, 1), -1.1);
}

TEST(functionalTest, SubEx) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  EXPECT_ANY_THROW(S21Matrix res = a + b);
}

TEST(functionalTest, Sub2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a -= b;
  EXPECT_DOUBLE_EQ(a(1, 1), -1.1);
}

TEST(functionalTest, SubEx2) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  EXPECT_ANY_THROW(a -= b);
}

TEST(functionalTest, Sub3) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a.SubMatrix(b);
  EXPECT_DOUBLE_EQ(a(1, 1), -1.1);
}

TEST(functionalTest, SubEx3) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  EXPECT_ANY_THROW(a.SubMatrix(b));
}

TEST(functionalTest, SubEx4) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  EXPECT_ANY_THROW(a - b);
}

TEST(functionalTest, MulMatrix) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 3);
  a(1, 1) = 1.1;
  b(1, 1) = 2.0;
  S21Matrix res = a * b;
  EXPECT_DOUBLE_EQ(res(1, 1), 2.2);
}

TEST(functionalTest, MulMatrixEx) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  EXPECT_ANY_THROW(S21Matrix res = a * b);
}

TEST(functionalTest, MulMatrix2) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 3);
  a(1, 1) = 1.1;
  b(1, 1) = 2.0;
  a *= b;
  EXPECT_DOUBLE_EQ(a(1, 1), 2.2);
}

TEST(functionalTest, MulMatrixEx2) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  EXPECT_ANY_THROW(a *= b);
}

TEST(functionalTest, MulMatrix3) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 3);
  a(1, 1) = 1.1;
  b(1, 1) = 2.0;
  a.MulMatrix(b);
  EXPECT_DOUBLE_EQ(a(1, 1), 2.2);
}

TEST(functionalTest, MulMatrixEx3) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  EXPECT_ANY_THROW(a.MulMatrix(b));
}

TEST(functionalTest, MulNumber) {
  S21Matrix a(3, 2);
  a(1, 1) = 1.1;
  S21Matrix res = a * 2.0;
  EXPECT_DOUBLE_EQ(res(1, 1), 2.2);
}

TEST(functionalTest, MulNumber2) {
  S21Matrix a(3, 2);
  a(1, 1) = 1.1;
  a *= 2.0;
  EXPECT_DOUBLE_EQ(a(1, 1), 2.2);
}

TEST(functionalTest, MulNumber3) {
  S21Matrix a(3, 2);
  a(1, 1) = 1.1;
  a.MulNumber(2);
  EXPECT_DOUBLE_EQ(a(1, 1), 2.2);
}

 TEST(functionalTest, MulNumber4) {
   S21Matrix a(3, 2);
   a(1, 1) = 1.1;
   S21Matrix res = a*2.0;
   EXPECT_DOUBLE_EQ(res(1, 1), 2.2);
 }

TEST(MatrixSumTest, determinant) {
  S21Matrix m(4, 4);
  m(0, 0) = 9.0;
  m(0, 1) = 2.0;
  m(0, 2) = 2.0;
  m(0, 3) = 4.0;

  m(1, 0) = 3.0;
  m(1, 1) = 4.0;
  m(1, 2) = 4.0;
  m(1, 3) = 4.0;

  m(2, 0) = 4.0;
  m(2, 1) = 4.0;
  m(2, 2) = 9.0;
  m(2, 3) = 9.0;

  m(3, 0) = 1.0;
  m(3, 1) = 1.0;
  m(3, 2) = 5.0;
  m(3, 3) = 1.0;
  S21Matrix m1(1, 1);
  m1(0, 0) = 10.0;
  EXPECT_EQ(m1.Determinant(), 10.0);
  S21Matrix m2(2, 2);
  m2(0, 0) = 1.1;
  m2(0, 1) = 3.5;
  m2(1, 0) = -2.0;
  m2(1, 1) = 4.0;
  EXPECT_DOUBLE_EQ(m2.Determinant(), 11.4);
}

TEST(functionalFuncTest, determinant2) {
  S21Matrix m(4, 4);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(0, 2) = 3.0;
  m(0, 3) = 4.0;

  m(1, 0) = 1.0;
  m(1, 1) = 2.0;
  m(1, 2) = 5.0;
  m(1, 3) = 7.0;

  m(2, 0) = 1.0;
  m(2, 1) = 0.0;
  m(2, 2) = 6.0;
  m(2, 3) = 8.0;

  m(3, 0) = 1.0;
  m(3, 1) = 0.0;
  m(3, 2) = 6.0;
  m(3, 3) = 6.0;
  EXPECT_EQ(m.Determinant(), -8.0);
}

TEST(functionalFuncTest, determinantEx) {
  S21Matrix m(4, 3);

  EXPECT_ANY_THROW(m.Determinant());
}

TEST(MatrixSumTest, eq_matrix_size_33) {
  S21Matrix x(3, 3), y(3, 3);
  EXPECT_EQ(x == y, true);
}

TEST(MatrixSumTest, eq_matrix_size_33_fail) {
  S21Matrix x(2, 2);
  x(0, 0) = 1.0;
  x(0, 1) = 2.0;
  x(1, 0) = 3.0;
  x(1, 1) = 4.0;
  S21Matrix y(x);
  y *= 2.0;
  EXPECT_EQ(x == y, false);
}

TEST(MatrixSumTest, eq_matrix_size_43) {
  S21Matrix x, y(4, 4);
  EXPECT_EQ(x == y, false);
}

TEST(MatrixSumTest, inv_matrix) {
  S21Matrix x(1, 1), y(1, 1);
  x(0, 0) = 4.0;
  y(0, 0) = 1.0 / 4.0;
  x = x.InverseMatrix();
  EXPECT_EQ(x == y, true);
}

TEST(MatrixSumTest, const_op) {
  S21Matrix x(2, 2);
  x(0, 0) = 1.0;
  x(0, 1) = 2.0;
  x(1, 0) = 3.0;
  x(1, 1) = 4.0;
  const S21Matrix y(x);
  EXPECT_EQ(x(1, 0), y(1, 0));
}

TEST_F(matrixTest, eq_matrix) {
  S21Matrix x, y, z;
  x = matrix_33_b;
  ASSERT_EQ(y.EqMatrix(z), true);
  ASSERT_EQ(x == y, false);
}

TEST_F(matrixTest, transpose_matrix) {
  S21Matrix x, y;
  x = matrix_33_b;
  y = matrix_transpose;
  x = x.Transpose();
  ASSERT_EQ(x == y, true);
}

TEST_F(matrixTest, calc_matrix) {
  S21Matrix x, y, z(4, 1);
  x = matrix_33_b;
  y = matrix_calc_c;
  x = x.CalcComplements();
  ASSERT_EQ(x == y, true);
  EXPECT_THROW(z.CalcComplements(), std::logic_error);
}

TEST_F(matrixTest, calc_matrix_) {
  S21Matrix x(1, 1);
  EXPECT_THROW(x.CalcComplements(), std::logic_error);
}

TEST_F(matrixTest, inverse_matrix) {
  S21Matrix x, z(2, 3);
  x = matrix_33_a.InverseMatrix();
  bool res = (matrix_inverse == x);
  ASSERT_EQ(res, true);
  ASSERT_THROW(z.InverseMatrix(), std::logic_error);
}

TEST_F(matrixTest, det_matrix) {
  S21Matrix z(5, 3);
  double determinant = matrix_33_b.Determinant();
  ASSERT_EQ(determinant, 78.0);
  ASSERT_THROW(z.Determinant(), std::logic_error);
}

 TEST_F(matrixTest, set_rows_ex) {
   S21Matrix z(5, 3);
   ASSERT_THROW(z.SetRows(-1), std::out_of_range);
 }

TEST_F(matrixTest, set_cols_ex) {
  S21Matrix z(5, 3);
  ASSERT_THROW(z.SetCols(-1), std::out_of_range);
}

TEST_F(matrixTest, const_op_ex) {
  const S21Matrix z(5, 3);
  ASSERT_THROW(z(-1, 0), std::out_of_range);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
