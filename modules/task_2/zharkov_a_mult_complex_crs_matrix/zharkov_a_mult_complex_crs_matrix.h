// Copyright 2022 Zharkov Andrey
#ifndef MODULES_TASK_2_ZHARKOV_A_MULT_COMPLEX_CRS_MATRIX_ZHARKOV_A_MULT_COMPLEX_CRS_MATRIX_H_
#define MODULES_TASK_2_ZHARKOV_A_MULT_COMPLEX_CRS_MATRIX_ZHARKOV_A_MULT_COMPLEX_CRS_MATRIX_H_

#include <algorithm>
#include <complex>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

class SparseComplexMatrix {
 private:
  int rows_num;
  int cols_num;

  std::vector<std::complex<double>> values;
  std::vector<int> col_index;
  std::vector<int> row_index;

 public:
  SparseComplexMatrix();
  SparseComplexMatrix(int _rows_num, int _cols_num);
  SparseComplexMatrix(int _rows_num, int _cols_num,
                      std::vector<std::complex<double>> _values,
                      std::vector<int> _col_index, std::vector<int> _row_index);
  SparseComplexMatrix(const SparseComplexMatrix& sparse_complex_matrix);
  bool operator==(const SparseComplexMatrix& mat) const&;
  SparseComplexMatrix operator*(const SparseComplexMatrix& mat) const&;
  SparseComplexMatrix crsParallelMult(const SparseComplexMatrix& mat) const&;
  SparseComplexMatrix matrixToCRS(
      std::vector<std::vector<std::complex<double>>> matrix);
  SparseComplexMatrix transposeCRS();
  void printCRS();
};

std::vector<std::vector<std::complex<double>>> randomMatrix(int _rows_num,
                                                            int _cols_num,
                                                            double percent);
void print(std::vector<std::vector<std::complex<double>>> matrix);
#endif  // MODULES_TASK_2_ZHARKOV_A_MULT_COMPLEX_CRS_MATRIX_ZHARKOV_A_MULT_COMPLEX_CRS_MATRIX_H_
