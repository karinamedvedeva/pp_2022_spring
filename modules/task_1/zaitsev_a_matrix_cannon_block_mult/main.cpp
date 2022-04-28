// Copyright 2022 Zaitsev Alexander
#include <gtest/gtest.h>

#include <random>
#include <vector>

std::vector<std::vector<double>> random_matrix(size_t rows, size_t columns,
                                               double value) {
  std::vector<std::vector<double>> random(rows, std::vector<double>(columns));
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < columns; j++) {
      random[i][j] = j * value + 1.434;
    }
  }
  return random;
}

std::vector<std::vector<double>> shift_to_left(
    const std::vector<std::vector<double>>& matrix, int position, int shift,
    size_t size) {
  std::vector<double> array(size);
  std::vector<std::vector<double>> shift_to_left = matrix;
  for (size_t y = 0; y < size; y++) {
    array[y] = shift_to_left[position][(y + shift) % size];
  }
  for (size_t z = 0; z < size; z++) {
    shift_to_left[position][z] = array[z];
  }
  return shift_to_left;
}

std::vector<std::vector<double>> shift_to_up(
    const std::vector<std::vector<double>>& matrix, int position, int shift,
    size_t size) {
  std::vector<double> array(size);
  std::vector<std::vector<double>> shift_to_up = matrix;
  for (size_t y = 0; y < size; y++) {
    array[y] = shift_to_up[(y + shift) % size][position];
  }
  for (size_t z = 0; z < size; z++) {
    shift_to_up[z][position] = array[z];
  }
  return shift_to_up;
}

std::vector<std::vector<double>> Cannon_block_matrix_mult(
    const std::vector<std::vector<double>>& first_multiplier,
    const std::vector<std::vector<double>>& second_multiplier, size_t size) {
  std::vector<std::vector<double>> result(size, std::vector<double>(size));
  std::vector<std::vector<double>> first = first_multiplier;
  std::vector<std::vector<double>> second = second_multiplier;
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      result[i][j] = 0.0;
    }
  }
  for (size_t i = 0; i < size; ++i) {
    first = shift_to_left(first, i, i, size);
  }
  for (size_t j = 0; j < size; ++j) {
    second = shift_to_up(second, j, j, size);
  }
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      for (size_t k = 0; k < size; ++k) {
        result[j][k] += first[j][k] * second[j][k];
      }
    }
    for (size_t l = 0; l < size; ++l) {
      first = shift_to_left(first, l, 1, size);
    }
    for (size_t l = 0; l < size; ++l) {
      second = shift_to_up(second, l, 1, size);
    }
  }
  return result;
}

std::vector<std::vector<double>> matrix_mult(
    const std::vector<std::vector<double>>& first_multiplier,
    const std::vector<std::vector<double>>& second_multiplier, size_t size) {
  std::vector<std::vector<double>> result(size, std::vector<double>(size));
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      result[i][j] = 0.0;
    }
  }
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      for (size_t k = 0; k < size; k++)
        result[i][j] += first_multiplier[i][k] * second_multiplier[k][j];
    }
  }
  return result;
}

TEST(Sequential, Test_1) {
  size_t size = 4;
  std::vector<std::vector<double>> A = random_matrix(size, size, 2.6);
  std::vector<std::vector<double>> B = random_matrix(size, size, 7.8);
  std::vector<std::vector<double>> C, D;
  D = matrix_mult(A, B, size);
  C = Cannon_block_matrix_mult(A, B, size);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_DOUBLE_EQ(C[i][j], D[i][j]);
    }
  }
}

TEST(Sequential, Test_2) {
  size_t size = 14;
  std::vector<std::vector<double>> A = random_matrix(size, size, 2.6);
  std::vector<std::vector<double>> B = random_matrix(size, size, 2.3);
  std::vector<std::vector<double>> C, D;
  D = matrix_mult(A, B, size);
  C = Cannon_block_matrix_mult(A, B, size);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_DOUBLE_EQ(C[i][j], D[i][j]);
    }
  }
}

TEST(Sequential, Test_3) {
  size_t size = 20;
  std::vector<std::vector<double>> A = random_matrix(size, size, 4.8);
  std::vector<std::vector<double>> B = random_matrix(size, size, 2.6);
  std::vector<std::vector<double>> C, D;
  D = matrix_mult(A, B, size);
  C = Cannon_block_matrix_mult(A, B, size);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_DOUBLE_EQ(C[i][j], D[i][j]);
    }
  }
}

TEST(Sequential, Test_4) {
  size_t size = 24;
  std::vector<std::vector<double>> A = random_matrix(size, size, 4.8);
  std::vector<std::vector<double>> B = random_matrix(size, size, 2.6);
  std::vector<std::vector<double>> C, D;
  D = matrix_mult(A, B, size);
  C = Cannon_block_matrix_mult(A, B, size);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_DOUBLE_EQ(C[i][j], D[i][j]);
    }
  }
}

TEST(Sequential, Test_5) {
  size_t size = 26;
  std::vector<std::vector<double>> A = random_matrix(size, size, 4.8);
  std::vector<std::vector<double>> B = random_matrix(size, size, 2.6);
  std::vector<std::vector<double>> C, D;
  D = matrix_mult(A, B, size);
  C = Cannon_block_matrix_mult(A, B, size);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_DOUBLE_EQ(C[i][j], D[i][j]);
    }
  }
}
