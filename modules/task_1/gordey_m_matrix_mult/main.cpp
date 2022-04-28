// Copyright 2022 Gordey Maria
#include <gtest/gtest.h>

#include "../../../modules/task_1/gordey_m_matrix_mult/matrix_mult.h"

TEST(SPARSE_MATRIX_MULT_SEQ, CREATE_MATRIX) {
    double* arr = create_random_matrix(4);
    SparseM A(arr, 2, 2);
    SparseM B(arr, 2, 2);
    delete[] arr;
    ASSERT_NO_THROW(A*B);
}

TEST(SPARSE_MATRIX_MULT_SEQ, TRANSPOSE) {
    double arr[] = { 1, 0, 0, 2 };
    double arr2[] = { 0, 3, 7, 0 };
    double arr3[] = { 0, 3, 14, 0 };
    SparseM A(arr, 2, 2);
    SparseM B(arr2, 2, 2);
    SparseM C(arr3, 2, 2);
    ASSERT_EQ(C== A*B, true);
}
TEST(SPARSE_MATRIX_MULT_SEQ, MULT_1) {
    double arr[] = { 0, 5, 0, 0, 1, 0, 3, 0, 8 };
    double arr2[] = { 1, 0, 0, 0, 0, 1, 0, 0, 4};
    double arr3[] = { 0, 0, 5, 0, 0, 1, 3, 0, 32 };
    SparseM A(arr, 3, 3);
    SparseM B(arr2, 3, 3);
    SparseM C(arr3, 3, 3);
    ASSERT_EQ(C == A * B, true);
}

TEST(SPARSE_MATRIX_MULT_SEQ, MULT_2) {
    int count = 4;
    double* arr = create_random_matrix(count*count);
    double* arr1 = create_random_matrix(count*count);
    SparseM A(arr, count, count);
    SparseM B(arr1, count, count);
    delete[] arr;
    delete[] arr1;
    ASSERT_NO_THROW(A*B);
}

TEST(SPARSE_MATRIX_MULT_SEQ, MULT_3) {
    int count = 5;
    double* arr = create_random_matrix(count*count);
    double* arr1 = create_random_matrix(count*count);
    SparseM A(arr, count, count);
    SparseM B(arr1, count, count);
    delete[] arr;
    delete[] arr1;
    ASSERT_NO_THROW(A*B);
}

TEST(SPARSE_MATRIX_MULT_SEQ, MULT_4) {
    int count = 6;
    double* arr = create_random_matrix(count*count);
    double* arr1 = create_random_matrix(count*count);
    SparseM A(arr, count, count);
    SparseM B(arr1, count, count);
    delete[] arr;
    delete[] arr1;
    ASSERT_NO_THROW(A*B);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
