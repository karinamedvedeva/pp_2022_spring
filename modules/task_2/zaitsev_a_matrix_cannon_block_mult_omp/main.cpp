// Copyright 2022 Zaitsev Alexander
#include <gtest/gtest.h>

#include <vector>

#include "./matrix.h"

TEST(Test, test_1) {
  size_t size = 40;
  std::vector<std::vector<double>> matrix1(size, std::vector<double>(size));
  std::vector<std::vector<double>> matrix2(size, std::vector<double>(size));
  std::vector<std::vector<double>> answer(size, std::vector<double>(size, 0.0));
  size_t block_size = size / 4;
  size_t block_count = size / block_size;
  double num1 = 1.076, num2 = 2.067;
  matrix1 = get_Matrix(num1, size);
  matrix2 = get_Matrix(num2, size);
  std::vector<std::vector<double>> matrix1_copy2 = matrix1;
  std::vector<std::vector<double>> matrix3 =
      cannon_mult_alg_Seq(matrix1, matrix2, block_size, block_count, size);
  std::vector<std::vector<double>> matrix4 = cannon_mult_alg_OMP(
      matrix1_copy2, matrix2, 4, block_size, block_count, size);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_DOUBLE_EQ(matrix3[i][j], matrix4[i][j]);
    }
  }
}

TEST(Test, test_2) {
  size_t size = 80;
  std::vector<std::vector<double>> matrix1(size, std::vector<double>(size));
  std::vector<std::vector<double>> matrix2(size, std::vector<double>(size));
  std::vector<std::vector<double>> answer(size, std::vector<double>(size, 0.0));
  size_t block_size = size / 4;
  size_t block_count = size / block_size;
  double num1 = 1.076, num2 = 2.067;
  matrix1 = get_Matrix(num1, size);
  matrix2 = get_Matrix(num2, size);
  std::vector<std::vector<double>> matrix1_copy2 = matrix1;
  std::vector<std::vector<double>> matrix3 =
      cannon_mult_alg_Seq(matrix1, matrix2, block_size, block_count, size);
  std::vector<std::vector<double>> matrix4 = cannon_mult_alg_OMP(
      matrix1_copy2, matrix2, 4, block_size, block_count, size);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_DOUBLE_EQ(matrix3[i][j], matrix4[i][j]);
    }
  }
}

TEST(Test, test_3) {
  size_t size = 120;
  std::vector<std::vector<double>> matrix1(size, std::vector<double>(size));
  std::vector<std::vector<double>> matrix2(size, std::vector<double>(size));
  std::vector<std::vector<double>> answer(size, std::vector<double>(size, 0.0));
  size_t block_size = size / 4;
  size_t block_count = size / block_size;
  double num1 = 1.076, num2 = 2.067;
  matrix1 = get_Matrix(num1, size);
  matrix2 = get_Matrix(num2, size);
  std::vector<std::vector<double>> matrix1_copy2 = matrix1;
  std::vector<std::vector<double>> matrix3 =
      cannon_mult_alg_Seq(matrix1, matrix2, block_size, block_count, size);
  std::vector<std::vector<double>> matrix4 = cannon_mult_alg_OMP(
      matrix1_copy2, matrix2, 4, block_size, block_count, size);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_DOUBLE_EQ(matrix3[i][j], matrix4[i][j]);
    }
  }
}

TEST(Test, test_4) {
  size_t size = 160;
  std::vector<std::vector<double>> matrix1(size, std::vector<double>(size));
  std::vector<std::vector<double>> matrix2(size, std::vector<double>(size));
  std::vector<std::vector<double>> answer(size, std::vector<double>(size, 0.0));
  size_t block_size = size / 4;
  size_t block_count = size / block_size;
  double num1 = 1.076, num2 = 2.067;
  matrix1 = get_Matrix(num1, size);
  matrix2 = get_Matrix(num2, size);
  std::vector<std::vector<double>> matrix1_copy2 = matrix1;
  std::vector<std::vector<double>> matrix3 =
      cannon_mult_alg_Seq(matrix1, matrix2, block_size, block_count, size);
  std::vector<std::vector<double>> matrix4 = cannon_mult_alg_OMP(
      matrix1_copy2, matrix2, 4, block_size, block_count, size);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_DOUBLE_EQ(matrix3[i][j], matrix4[i][j]);
    }
  }
}

TEST(Test, test_5) {
  size_t size = 200;
  std::vector<std::vector<double>> matrix1(size, std::vector<double>(size));
  std::vector<std::vector<double>> matrix2(size, std::vector<double>(size));
  std::vector<std::vector<double>> answer(size, std::vector<double>(size, 0.0));
  size_t block_size = size / 4;
  size_t block_count = size / block_size;
  double num1 = 1.076, num2 = 2.067;
  matrix1 = get_Matrix(num1, size);
  matrix2 = get_Matrix(num2, size);
  std::vector<std::vector<double>> matrix1_copy2 = matrix1;
  std::vector<std::vector<double>> matrix3 =
      cannon_mult_alg_Seq(matrix1, matrix2, block_size, block_count, size);
  std::vector<std::vector<double>> matrix4 = cannon_mult_alg_OMP(
      matrix1_copy2, matrix2, 4, block_size, block_count, size);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_DOUBLE_EQ(matrix3[i][j], matrix4[i][j]);
    }
  }
}
