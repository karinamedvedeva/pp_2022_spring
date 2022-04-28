// Copyright 2022 Preobrazhenskaya Yuliya
#include <omp.h>
#include <gtest/gtest.h>
#include "./histogram_stretching.h"

TEST(OpenMP_Histogram_Stretching, Image_is_empty) {
    int height = 0;
    int width = 0;
    ASSERT_ANY_THROW(getRandomImage(height, width));
}

TEST(OpenMP_Histogram_Stretching, Image_5x5) {
    int height = 5;
    int width = 5;
    int* image = getRandomImage(height, width);
    int y_max = getYmax(image, height, width);
    int y_min = getYmin(image, height, width);
    int* result_image_seq = nullptr;
    int* result_image_omp = nullptr;
    double start_seq = omp_get_wtime();
    result_image_seq = getSequentialOperations(image, height, width,
        y_max, y_min);
    double end_seq = omp_get_wtime();
    double sequential_runtime = end_seq - start_seq;
    double start_omp = omp_get_wtime();
    result_image_omp = getParallelOperationsOMP(image, height, width,
        y_max, y_min);
    double end_omp = omp_get_wtime();
    double parallel_omp_runtime = end_omp - start_omp;
    std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
    std::cout << "parallel_omp_runtime = " << parallel_omp_runtime
        << std::endl;
    for (int i = 0; i < height * width; i++) {
        ASSERT_EQ(result_image_seq[i], result_image_omp[i]);
    }
    delete[] image;
    delete[] result_image_seq;
    delete[] result_image_omp;
}

TEST(OpenMP_Histogram_Stretching, Image_7x10) {
    int height = 7;
    int width = 10;
    int* image = getRandomImage(height, width);
    int y_max = getYmax(image, height, width);
    int y_min = getYmin(image, height, width);
    int* result_image_seq = nullptr;
    int* result_image_omp = nullptr;
    double start_seq = omp_get_wtime();
    result_image_seq = getSequentialOperations(image, height, width,
        y_max, y_min);
    double end_seq = omp_get_wtime();
    double sequential_runtime = end_seq - start_seq;
    double start_omp = omp_get_wtime();
    result_image_omp = getParallelOperationsOMP(image, height, width,
        y_max, y_min);
    double end_omp = omp_get_wtime();
    double parallel_omp_runtime = end_omp - start_omp;
    std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
    std::cout << "parallel_omp_runtime = " << parallel_omp_runtime
        << std::endl;
    for (int i = 0; i < height * width; i++) {
        ASSERT_EQ(result_image_seq[i], result_image_omp[i]);
    }
    delete[] image;
    delete[] result_image_seq;
    delete[] result_image_omp;
}

TEST(OpenMP_Histogram_Stretching, Image_10x15) {
    int height = 10;
    int width = 15;
    int* image = getRandomImage(height, width);
    int y_max = getYmax(image, height, width);
    int y_min = getYmin(image, height, width);
    int* result_image_seq = nullptr;
    int* result_image_omp = nullptr;
    double start_seq = omp_get_wtime();
    result_image_seq = getSequentialOperations(image, height, width,
        y_max, y_min);
    double end_seq = omp_get_wtime();
    double sequential_runtime = end_seq - start_seq;
    double start_omp = omp_get_wtime();
    result_image_omp = getParallelOperationsOMP(image, height, width,
        y_max, y_min);
    double end_omp = omp_get_wtime();
    double parallel_omp_runtime = end_omp - start_omp;
    std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
    std::cout << "parallel_omp_runtime = " << parallel_omp_runtime
        << std::endl;
    for (int i = 0; i < height * width; i++) {
        ASSERT_EQ(result_image_seq[i], result_image_omp[i]);
    }
    delete[] image;
    delete[] result_image_seq;
    delete[] result_image_omp;
}

TEST(OpenMP_Histogram_Stretching, Image_40x20) {
    int height = 40;
    int width = 20;
    int* image = getRandomImage(height, width);
    int y_max = getYmax(image, height, width);
    int y_min = getYmin(image, height, width);
    int* result_image_seq = nullptr;
    int* result_image_omp = nullptr;
    double start_seq = omp_get_wtime();
    result_image_seq = getSequentialOperations(image, height, width,
        y_max, y_min);
    double end_seq = omp_get_wtime();
    double sequential_runtime = end_seq - start_seq;
    double start_omp = omp_get_wtime();
    result_image_omp = getParallelOperationsOMP(image, height, width,
        y_max, y_min);
    double end_omp = omp_get_wtime();
    double parallel_omp_runtime = end_omp - start_omp;
    std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
    std::cout << "parallel_omp_runtime = " << parallel_omp_runtime
        << std::endl;
    for (int i = 0; i < height * width; i++) {
        ASSERT_EQ(result_image_seq[i], result_image_omp[i]);
    }
    delete[] image;
    delete[] result_image_seq;
    delete[] result_image_omp;
}

TEST(OpenMP_Histogram_Stretching, Image_50x50) {
    int height = 50;
    int width = 50;
    int* image = getRandomImage(height, width);
    int y_max = getYmax(image, height, width);
    int y_min = getYmin(image, height, width);
    int* result_image_seq = nullptr;
    int* result_image_omp = nullptr;
    double start_seq = omp_get_wtime();
    result_image_seq = getSequentialOperations(image, height, width,
        y_max, y_min);
    double end_seq = omp_get_wtime();
    double sequential_runtime = end_seq - start_seq;
    double start_omp = omp_get_wtime();
    result_image_omp = getParallelOperationsOMP(image, height, width,
        y_max, y_min);
    double end_omp = omp_get_wtime();
    double parallel_omp_runtime = end_omp - start_omp;
    std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
    std::cout << "parallel_omp_runtime = " << parallel_omp_runtime
        << std::endl;
    for (int i = 0; i < height * width; i++) {
        ASSERT_EQ(result_image_seq[i], result_image_omp[i]);
    }
    delete[] image;
    delete[] result_image_seq;
    delete[] result_image_omp;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    omp_set_num_threads(2);
    return RUN_ALL_TESTS();
}
