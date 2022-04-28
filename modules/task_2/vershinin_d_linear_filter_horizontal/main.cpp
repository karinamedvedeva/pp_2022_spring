// Copyright 2022 Vershinin Daniil
#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include <omp.h>

#include <iostream>
#include <vector>

#include "./linear_filter_horizontal.h"

TEST(OMP_TEST, TestGetParallelOperations_3x3) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 3;
  int height = 3;
  std::vector<float> img = getRandomImage(width, height);

  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);

  std::vector<float> res = getSequentialOperations(width, height, kernel, img);

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}

TEST(OMP_TEST, TestGetParallelOperations_128x128) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 128;
  int height = 128;
  std::vector<float> img = getRandomImage(width, height);

  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);

  std::vector<float> res = getSequentialOperations(width, height, kernel, img);

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}

TEST(OMP_TEST, TestGetParallelOperations_256x256) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 256;
  int height = 256;
  std::vector<float> img = getRandomImage(width, height);

  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);

  std::vector<float> res = getSequentialOperations(width, height, kernel, img);

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}

TEST(OMP_TEST, DISABLED_TestGetParallelOperations_512x512) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 512;
  int height = 512;
  std::vector<float> img = getRandomImage(width, height);

  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);

  std::vector<float> res = getSequentialOperations(width, height, kernel, img);

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}

TEST(OMP_TEST, DISABLED_TestGetParallelOperations_1024x1024) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 1024;
  int height = 1024;
  std::vector<float> img = getRandomImage(width, height);

  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);

  std::vector<float> res = getSequentialOperations(width, height, kernel, img);

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}

TEST(OMP_TEST, DISABLED_TestGetParallelOperations_1920x1080) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 1920;
  int height = 1080;
  std::vector<float> img = getRandomImage(width, height);

  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);

  std::vector<float> res = getSequentialOperations(width, height, kernel, img);

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}

// Test with time

/*
TEST(OMP_TEST, TestGetParallelOperations_3x3) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 3;
  int height = 3;
  std::vector<float> img = getRandomImage(width, height);

  double t1, t2;

  t1 = omp_get_wtime();
  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);
  t1 = omp_get_wtime() - t1;

  t2 = omp_get_wtime();
  std::vector<float> res = getSequentialOperations(width, height, kernel, img);
  t2 = omp_get_wtime() - t2;

  std::cout << "paralel (t1): " << t1 << " seq (t2): " << t2
            << " t2/t1 :" << t2 / t1 << std::endl;

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}

TEST(OMP_TEST, TestGetParallelOperations_128x128) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 128;
  int height = 128;
  std::vector<float> img = getRandomImage(width, height);

  double t1, t2;

  t1 = omp_get_wtime();
  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);
  t1 = omp_get_wtime() - t1;

  t2 = omp_get_wtime();
  std::vector<float> res = getSequentialOperations(width, height, kernel, img);
  t2 = omp_get_wtime() - t2;

  std::cout << "paralel (t1): " << t1 << " seq (t2): " << t2
            << " t2/t1 :" << t2 / t1 << std::endl;

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}

TEST(OMP_TEST, TestGetParallelOperations_256x256) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 256;
  int height = 256;
  std::vector<float> img = getRandomImage(width, height);

  double t1, t2;

  t1 = omp_get_wtime();
  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);
  t1 = omp_get_wtime() - t1;

  t2 = omp_get_wtime();
  std::vector<float> res = getSequentialOperations(width, height, kernel, img);
  t2 = omp_get_wtime() - t2;

  std::cout << "paralel (t1): " << t1 << " seq (t2): " << t2
            << " t2/t1 :" << t2 / t1 << std::endl;

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}

TEST(OMP_TEST, TestGetParallelOperations_512x512) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 512;
  int height = 512;
  std::vector<float> img = getRandomImage(width, height);

  double t1, t2;

  t1 = omp_get_wtime();
  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);
  t1 = omp_get_wtime() - t1;

  t2 = omp_get_wtime();
  std::vector<float> res = getSequentialOperations(width, height, kernel, img);
  t2 = omp_get_wtime() - t2;

  std::cout << "paralel (t1): " << t1 << " seq (t2): " << t2
            << " t2/t1 :" << t2 / t1 << std::endl;

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}

TEST(OMP_TEST, TestGetParallelOperations_1024x1024) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 1024;
  int height = 1024;
  std::vector<float> img = getRandomImage(width, height);

  double t1, t2;

  t1 = omp_get_wtime();
  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);
  t1 = omp_get_wtime() - t1;

  t2 = omp_get_wtime();
  std::vector<float> res = getSequentialOperations(width, height, kernel, img);
  t2 = omp_get_wtime() - t2;

  std::cout << "paralel (t1): " << t1 << " seq (t2): " << t2
            << " t2/t1 :" << t2 / t1 << std::endl;

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}

TEST(OMP_TEST, TestGetParallelOperations_1920x1080) {
  std::vector<float> kernel = getGaussKernel(1, 1.5);
  int width = 1920;
  int height = 1080;
  std::vector<float> img = getRandomImage(width, height);

  double t1, t2;

  t1 = omp_get_wtime();
  std::vector<float> res_check =
      getParallelOperations(width, height, kernel, img);
  t1 = omp_get_wtime() - t1;

  t2 = omp_get_wtime();
  std::vector<float> res = getSequentialOperations(width, height, kernel, img);
  t2 = omp_get_wtime() - t2;

  std::cout << "paralel (t1): " << t1 << " seq (t2): " << t2
            << " t2/t1 :" << t2 / t1 << std::endl;

  for (int i = 0; i < width * height; i++) {
    ASSERT_NEAR(res[i], res_check[i], 0.001);
  }
}
*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
