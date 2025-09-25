#include <gtest/gtest.h>
#include "matrix.h"

TEST(MatrixTest, CreateAndFree) {
    Matrix m = create_matrix(2, 2);
    EXPECT_EQ(m.rows, 2);
    EXPECT_EQ(m.cols, 2);
    EXPECT_NE(m.data, nullptr);
    free_matrix(m);
}

TEST(MatrixTest, InvalidSize) {
    EXPECT_THROW(create_matrix(-1, 2), std::invalid_argument);
}

TEST(MatrixTest, MatrixAddition) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);

    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;

    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;

    Matrix C = matrix_add(A, B);
    EXPECT_EQ(C.data[0][0], 6);
    EXPECT_EQ(C.data[0][1], 8);
    EXPECT_EQ(C.data[1][0], 10);
    EXPECT_EQ(C.data[1][1], 12);

    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
}

TEST(MatrixTest, MatrixMultiplication) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);

    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;

    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;

    Matrix C = matrix_multiply(A, B);
    EXPECT_EQ(C.data[0][0], 19);
    EXPECT_EQ(C.data[0][1], 22);
    EXPECT_EQ(C.data[1][0], 43);
    EXPECT_EQ(C.data[1][1], 50);

    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
}

TEST(MatrixTest, MatrixSum) {
    Matrix A = create_matrix(2, 2);
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;

    EXPECT_DOUBLE_EQ(matrix_sum(A), 10.0);
    free_matrix(A);
}

TEST(MatrixTest, MatrixSumEmpty) {
    Matrix A = create_matrix(1, 1);
    A.data[0][0] = 0.0;
    EXPECT_DOUBLE_EQ(matrix_sum(A), 0.0);
    free_matrix(A);
}

TEST(MatrixTest, MatrixSumInvalidMatrix) {
    Matrix A;
    A.data = nullptr;
    A.rows = 0;
    A.cols = 0;
    EXPECT_DOUBLE_EQ(matrix_sum(A), 0.0);
}

TEST(MatrixTest, MatrixSumSingleElement) {
    Matrix A = create_matrix(1, 1);
    A.data[0][0] = 5.5;
    EXPECT_DOUBLE_EQ(matrix_sum(A), 5.5);
    free_matrix(A);
}
