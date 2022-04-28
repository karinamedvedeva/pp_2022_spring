// Copyright 2022 Gudkov Andrey
#include <gtest/gtest.h>
#include <omp.h>
#include "./gaussian.h"
#define THREAD_NUM 4

TEST(Gauss_Filter, _50x50) {
    int width = 50;
    int height = 50;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> seq;
    std::vector<uint8_t> par;

    seq = Filter(img, width, height, 32);
    par = ParFilter(img, width, height, THREAD_NUM, 32);
    ASSERT_EQ(seq, par);
}

TEST(Gauss_Filter, _100x100) {
    int width = 100;
    int height = 100;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> seq;
    std::vector<uint8_t> par;

    seq = Filter(img, width, height, 32);
    par = ParFilter(img, width, height, THREAD_NUM, 32);
    ASSERT_EQ(seq, par);
}

TEST(Gauss_Filter, _200x200) {
    int width = 200;
    int height = 200;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> seq;
    std::vector<uint8_t> par;

    seq = Filter(img, width, height, 32);
    par = ParFilter(img, width, height, THREAD_NUM, 32);
    ASSERT_EQ(seq, par);
}

TEST(Gauss_Filter, _320x240) {
    int width = 320;
    int height = 240;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> seq;
    std::vector<uint8_t> par;

    seq = Filter(img, width, height, 32);
    par = ParFilter(img, width, height, THREAD_NUM, 32);
    ASSERT_EQ(seq, par);
}

TEST(Gauss_Filter, _500x500) {
    int width = 500;
    int height = 500;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> seq;
    std::vector<uint8_t> par;

    seq = Filter(img, width, height, 32);
    par = ParFilter(img, width, height, THREAD_NUM, 32);
    ASSERT_EQ(seq, par);
}

/*
TEST(Gauss_Filter, Eff_Test) {
    int width = 3000, height = 5500;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> a;
    clock_t start, end;
    start = clock();
    a = Filter(img, width, height);
    end = clock();
    double seconds = (static_cast<double>(end - start)) / CLOCKS_PER_SEC;
    std::cout << "seq " << seconds << std::endl;
    start = clock();
    a = ParFilter(img, width, height, 32);
    end = clock();
    seconds = (static_cast<double>(end - start)) / CLOCKS_PER_SEC;
    std::cout << "par " << seconds << std::endl;

    ASSERT_EQ(1,1);
}
*/

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
