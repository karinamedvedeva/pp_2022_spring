// Copyright 2018 Nesterov Alexander
#include <gtest/gtest.h>
#include <tbb/tbb.h>
#include <vector>
#include <numeric>
#include "../gordey_m_matrix_mult_tbb/gordey_m_matrix_mult.h"

TEST(SPARSE_MATRIX_MULT_SEQ, CREATE_MATRIX) {
        double* arr = create_random_matrix(4);
        SparseM A(arr, 2, 2);
        SparseM B(arr, 2, 2);
        ASSERT_EQ(1, 1);
}

TEST(SPARSE_MATRIX_MULT_SEQ, TRANSPOSE) {
        double arr[] = { 1, 0, 0, 2 };
        double arr2[] = { 0, 3, 7, 0 };
        double arr3[] = { 0, 3, 14, 0 };
        SparseM A(arr, 2, 2);
        SparseM B(arr2, 2, 2);
        SparseM C(arr3, 2, 2);
        ASSERT_EQ(1, 1);
}

TEST(SPARSE_MATRIX_MULT_SEQ, MULT_1) {
        double arr[] = { 0, 5, 0, 0, 1, 0, 3, 0, 8 };
        double arr2[] = { 1, 0, 0, 0, 0, 1, 0, 0, 4 };
        double arr3[] = { 0, 0, 5, 0, 0, 1, 3, 0, 32 };
        SparseM A(arr, 3, 3);
        SparseM B(arr2, 3, 3);
        SparseM C(arr3, 3, 3);
        ASSERT_EQ(C == A * B, true);
}

TEST(SPARSE_MATRIX_MULT_SEQ, MULT_2) {
        int count = 250;
        double* arr = create_random_matrix(count*count);
        double* arr1 = create_random_matrix(count*count);
        SparseM A(arr, count, count);
        SparseM B(arr1, count, count);
        delete[] arr;
        delete[] arr1;
        tbb::tick_count start_seq = tbb::tick_count::now();
        SparseM C = A * B;
        tbb::tick_count end_seq = tbb::tick_count::now();
    double sequential_runtime = (end_seq - start_seq).seconds();
    tbb::tick_count start_tbb = tbb::tick_count::now();
        SparseM D = Mult_parallel(A, B);
        tbb::tick_count end_tbb = tbb::tick_count::now();
        double parallel_tbb_runtime = (end_tbb - start_tbb).seconds();
        std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
        std::cout << "parallel_tbb_runtime = "
                << parallel_tbb_runtime << std::endl;
        std::cout << "a: " << sequential_runtime / parallel_tbb_runtime << "\n";
        ASSERT_EQ(D, C);
}

TEST(SPARSE_MATRIX_MULT_SEQ, MULT_3) {
        int count = 300;
        double* arr = create_random_matrix(count*count);
        double* arr1 = create_random_matrix(count*count);
        SparseM A(arr, count, count);
        SparseM B(arr1, count, count);
        delete[] arr;
        delete[] arr1;
        tbb::tick_count start_seq = tbb::tick_count::now();
        SparseM C = A * B;
        tbb::tick_count end_seq = tbb::tick_count::now();
        double sequential_runtime = (end_seq - start_seq).seconds();
        tbb::tick_count start_tbb = tbb::tick_count::now();
        SparseM D = Mult_parallel(A, B);
        tbb::tick_count end_tbb = tbb::tick_count::now();
        double parallel_tbb_runtime = (end_tbb - start_tbb).seconds();
        std::cout << "sequential_runtime = "
                << sequential_runtime << std::endl;
        std::cout << "parallel_tbb_runtime = "
                << parallel_tbb_runtime << std::endl;
        std::cout << "a: " << sequential_runtime / parallel_tbb_runtime << "\n";
        ASSERT_EQ(D, C);
}
TEST(SPARSE_MATRIX_MULT_SEQ, MULT_4) {
        int count = 320;
        double* arr = create_random_matrix(count*count);
        double* arr1 = create_random_matrix(count*count);
        SparseM A(arr, count, count);
        SparseM B(arr1, count, count);
        delete[] arr;
        delete[] arr1;
        tbb::tick_count start_seq = tbb::tick_count::now();
        SparseM C = A * B;
        tbb::tick_count end_seq = tbb::tick_count::now();
        double sequential_runtime = (end_seq - start_seq).seconds();
        tbb::tick_count start_tbb = tbb::tick_count::now();
        SparseM D = Mult_parallel(A, B);
        tbb::tick_count end_tbb = tbb::tick_count::now();
        double parallel_tbb_runtime =
                (end_tbb - start_tbb).seconds();
        std::cout << "sequential_runtime = "
                << sequential_runtime << std::endl;
        std::cout << "parallel_tbb_runtime = "
                << parallel_tbb_runtime << std::endl;
        std::cout << "a: " << sequential_runtime / parallel_tbb_runtime << "\n";
        ASSERT_EQ(D, C);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
