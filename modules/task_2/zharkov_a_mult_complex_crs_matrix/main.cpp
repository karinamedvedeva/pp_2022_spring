// Copyright 2022 Zharkov Andrey
#include <gtest/gtest.h>
#include <omp.h>

#include <iostream>
#include <vector>

#include "../../modules/task_2/zharkov_a_mult_complex_crs_matrix/zharkov_a_mult_complex_crs_matrix.h"


TEST(SparceMatrixMultiplication, matrix_to_csr) {
  std::vector<std::vector<std::complex<double>>> mat;
  SparseComplexMatrix crsMat;
  mat = randomMatrix(5, 5, 30);
  ASSERT_NO_THROW(crsMat.matrixToCRS(mat));
}

TEST(SparceMatrixMultiplication, transpose) {
  std::vector<std::complex<double>> vals_trans = {std::complex<double>(0, 5),
                                                  std::complex<double>(7, 9)};
  std::vector<int> col_ind_trans = {0, 0};
  std::vector<int> row_ind_trans = {0, 0, 1, 1, 2, 2, 2};

  std::vector<std::complex<double>> vals = {std::complex<double>(0, 5),
                                            std::complex<double>(7, 9)};
  std::vector<int> col_ind = {1, 3};
  std::vector<int> row_ind = {0, 2, 2, 2};

  SparseComplexMatrix mat(3, 6, vals, col_ind, row_ind);
  SparseComplexMatrix mat_trans(6, 3, vals_trans, col_ind_trans, row_ind_trans);
  SparseComplexMatrix tmp;
  tmp = mat.transposeCRS();

  ASSERT_TRUE(mat_trans == tmp);
}

TEST(SparceMatrixMultiplication, can_multimply_square_csr_matrices) {
  int size = 5;
  std::vector<std::vector<std::complex<double>>> mat1;
  std::vector<std::vector<std::complex<double>>> mat2;
  SparseComplexMatrix crsMat1;
  SparseComplexMatrix crsMat2;
  SparseComplexMatrix crsMat3;
  mat1 = randomMatrix(size, size, 30);
  mat2 = randomMatrix(size, size, 30);
  crsMat1 = crsMat1.matrixToCRS(mat1);
  crsMat2 = crsMat2.matrixToCRS(mat2);
  ASSERT_NO_THROW(crsMat3 = crsMat1 * crsMat2);
}

TEST(SparceMatrixMultiplication, can_multimply_not_square_csr_matrices) {
  int rows1 = 200;
  int cols1 = 110;
  int rows2 = 110;
  int cols2 = 350;
  double percent = 50;
  std::vector<std::vector<std::complex<double>>> mat1;
  std::vector<std::vector<std::complex<double>>> mat2;
  SparseComplexMatrix crsMat1;
  SparseComplexMatrix crsMat2;
  SparseComplexMatrix crsMat3;
  SparseComplexMatrix crsMat4;
  mat1 = randomMatrix(rows1, cols1, percent);
  mat2 = randomMatrix(rows2, cols2, percent);
  crsMat1 = crsMat1.matrixToCRS(mat1);
  crsMat2 = crsMat2.matrixToCRS(mat2);


  double start_seq = omp_get_wtime();
  crsMat3 = crsMat1 * crsMat2;
  double end_seq = omp_get_wtime();


  double start_par = omp_get_wtime();
  crsMat4 = crsMat1.crsParallelMult(crsMat2);
  double end_par = omp_get_wtime();


  std::cout << "Seq time: " << end_seq - start_seq << "\n";
  std::cout << "Par time: " << end_par - start_par << "\n";
  std::cout << "Boost time: " << (end_seq - start_seq) / (end_par - start_par) << "\n";

  ASSERT_TRUE(crsMat3 == crsMat4);
}

TEST(SparceMatrixMultiplication, can_multimply_square_new_csr_matrices) {
  int rows1 = 350;
  int cols1 = 110;
  int rows2 = 110;
  int cols2 = 350;
  double percent = 50;
  std::vector<std::vector<std::complex<double>>> mat1;
  std::vector<std::vector<std::complex<double>>> mat2;
  SparseComplexMatrix crsMat1;
  SparseComplexMatrix crsMat2;
  SparseComplexMatrix crsMat3;
  SparseComplexMatrix crsMat4;
  mat1 = randomMatrix(rows1, cols1, percent);
  mat2 = randomMatrix(rows2, cols2, percent);
  crsMat1 = crsMat1.matrixToCRS(mat1);
  crsMat2 = crsMat2.matrixToCRS(mat2);

  double start_seq = omp_get_wtime();
  crsMat3 = crsMat1 * crsMat2;
  double end_seq = omp_get_wtime();

  double start_par = omp_get_wtime();
  crsMat4 = crsMat1.crsParallelMult(crsMat2);
  double end_par = omp_get_wtime();

  std::cout << "Seq time: " << end_seq - start_seq << "\n";
  std::cout << "Par time: " << end_par - start_par << "\n";
  std::cout << "Boost time: " << (end_seq - start_seq) / (end_par - start_par)
            << "\n";

  ASSERT_TRUE(crsMat3 == crsMat4);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
