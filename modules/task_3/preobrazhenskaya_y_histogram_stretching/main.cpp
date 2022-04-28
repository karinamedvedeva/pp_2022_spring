// Copyright 2022 Preobrazhenskaya Yuliya
#include <tbb/tbb.h>
#include <gtest/gtest.h>
#include "./histogram_stretching.h"

TEST(TBB_Histogram_Stretching, Image_is_empty) {
    int height = 0;
    int width = 0;
    ASSERT_ANY_THROW(getRandomImage(height, width));
}

TEST(TBB_Histogram_Stretching, Image_5x5) {
    int height = 5;
    int width = 5;
    int* image = getRandomImage(height, width);
    int y_max = getYmax(image, height, width);
    int y_min = getYmin(image, height, width);
    int* result_image_seq = nullptr;
    int* result_image_tbb = nullptr;
    tbb::tick_count start_seq = tbb::tick_count::now();
    result_image_seq = getSequentialOperations(image, height, width,
        y_max, y_min);
    tbb::tick_count end_seq = tbb::tick_count::now();
    double sequential_runtime = (end_seq - start_seq).seconds();
    tbb::tick_count start_tbb = tbb::tick_count::now();
    result_image_tbb = getParallelOperationsTBB(image, height, width,
        y_max, y_min);
    tbb::tick_count end_tbb = tbb::tick_count::now();
    double parallel_tbb_runtime = (end_tbb - start_tbb).seconds();
    std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
    std::cout << "parallel_tbb_runtime = " << parallel_tbb_runtime
        << std::endl;
    for (int i = 0; i < height * width; i++) {
        ASSERT_EQ(result_image_seq[i], result_image_tbb[i]);
    }
    delete[] image;
    delete[] result_image_seq;
    delete[] result_image_tbb;
}

TEST(TBB_Histogram_Stretching, Image_7x10) {
    int height = 7;
    int width = 10;
    int* image = getRandomImage(height, width);
    int y_max = getYmax(image, height, width);
    int y_min = getYmin(image, height, width);
    int* result_image_seq = nullptr;
    int* result_image_tbb = nullptr;
    tbb::tick_count start_seq = tbb::tick_count::now();
    result_image_seq = getSequentialOperations(image, height, width,
        y_max, y_min);
    tbb::tick_count end_seq = tbb::tick_count::now();
    double sequential_runtime = (end_seq - start_seq).seconds();
    tbb::tick_count start_tbb = tbb::tick_count::now();
    result_image_tbb = getParallelOperationsTBB(image, height, width,
        y_max, y_min);
    tbb::tick_count end_tbb = tbb::tick_count::now();
    double parallel_tbb_runtime = (end_tbb - start_tbb).seconds();
    std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
    std::cout << "parallel_tbb_runtime = " << parallel_tbb_runtime
        << std::endl;
    for (int i = 0; i < height * width; i++) {
        ASSERT_EQ(result_image_seq[i], result_image_tbb[i]);
    }
    delete[] image;
    delete[] result_image_seq;
    delete[] result_image_tbb;
}

TEST(TBB_Histogram_Stretching, Image_10x15) {
    int height = 10;
    int width = 15;
    int* image = getRandomImage(height, width);
    int y_max = getYmax(image, height, width);
    int y_min = getYmin(image, height, width);
    int* result_image_seq = nullptr;
    int* result_image_tbb = nullptr;
    tbb::tick_count start_seq = tbb::tick_count::now();
    result_image_seq = getSequentialOperations(image, height, width,
        y_max, y_min);
    tbb::tick_count end_seq = tbb::tick_count::now();
    double sequential_runtime = (end_seq - start_seq).seconds();
    tbb::tick_count start_tbb = tbb::tick_count::now();
    result_image_tbb = getParallelOperationsTBB(image, height, width,
        y_max, y_min);
    tbb::tick_count end_tbb = tbb::tick_count::now();
    double parallel_tbb_runtime = (end_tbb - start_tbb).seconds();
    std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
    std::cout << "parallel_tbb_runtime = " << parallel_tbb_runtime
        << std::endl;
    for (int i = 0; i < height * width; i++) {
        ASSERT_EQ(result_image_seq[i], result_image_tbb[i]);
    }
    delete[] image;
    delete[] result_image_seq;
    delete[] result_image_tbb;
}

TEST(TBB_Histogram_Stretching, Image_40x20) {
    int height = 40;
    int width = 20;
    int* image = getRandomImage(height, width);
    int y_max = getYmax(image, height, width);
    int y_min = getYmin(image, height, width);
    int* result_image_seq = nullptr;
    int* result_image_tbb = nullptr;
    tbb::tick_count start_seq = tbb::tick_count::now();
    result_image_seq = getSequentialOperations(image, height, width,
        y_max, y_min);
    tbb::tick_count end_seq = tbb::tick_count::now();
    double sequential_runtime = (end_seq - start_seq).seconds();
    tbb::tick_count start_tbb = tbb::tick_count::now();
    result_image_tbb = getParallelOperationsTBB(image, height, width,
        y_max, y_min);
    tbb::tick_count end_tbb = tbb::tick_count::now();
    double parallel_tbb_runtime = (end_tbb - start_tbb).seconds();
    std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
    std::cout << "parallel_tbb_runtime = " << parallel_tbb_runtime
        << std::endl;
    for (int i = 0; i < height * width; i++) {
        ASSERT_EQ(result_image_seq[i], result_image_tbb[i]);
    }
    delete[] image;
    delete[] result_image_seq;
    delete[] result_image_tbb;
}

TEST(TBB_Histogram_Stretching, Image_50x50) {
    int height = 50;
    int width = 50;
    int* image = getRandomImage(height, width);
    int y_max = getYmax(image, height, width);
    int y_min = getYmin(image, height, width);
    int* result_image_seq = nullptr;
    int* result_image_tbb = nullptr;
    tbb::tick_count start_seq = tbb::tick_count::now();
    result_image_seq = getSequentialOperations(image, height, width,
        y_max, y_min);
    tbb::tick_count end_seq = tbb::tick_count::now();
    double sequential_runtime = (end_seq - start_seq).seconds();
    tbb::tick_count start_tbb = tbb::tick_count::now();
    result_image_tbb = getParallelOperationsTBB(image, height, width,
        y_max, y_min);
    tbb::tick_count end_tbb = tbb::tick_count::now();
    double parallel_tbb_runtime = (end_tbb - start_tbb).seconds();
    std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
    std::cout << "parallel_tbb_runtime = " << parallel_tbb_runtime
        << std::endl;
    for (int i = 0; i < height * width; i++) {
        ASSERT_EQ(result_image_seq[i], result_image_tbb[i]);
    }
    delete[] image;
    delete[] result_image_seq;
    delete[] result_image_tbb;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    tbb::task_scheduler_init init(2);
    return RUN_ALL_TESTS();
}
