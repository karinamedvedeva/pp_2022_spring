// Copyright 2022 Gudkov Andrey

#include <gtest/gtest.h>
#include "./gaussian.h"

TEST(Gauss_Filter, _50x50) {
    int width = 50;
    int height = 50;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> seq;
    std::vector<uint8_t> par;

    seq = Filter(img, width, height, 32);
    par = ParFilter(img, width, height, 32);
    ASSERT_EQ(seq, par);
}

TEST(Gauss_Filter, _100x100) {
    int width = 100;
    int height = 100;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> seq;
    std::vector<uint8_t> par;

    seq = Filter(img, width, height, 32);
    par = ParFilter(img, width, height, 32);
    ASSERT_EQ(seq, par);
}

TEST(Gauss_Filter, _200x200) {
    int width = 200;
    int height = 200;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> seq;
    std::vector<uint8_t> par;

    seq = Filter(img, width, height, 32);
    par = ParFilter(img, width, height, 32);
    ASSERT_EQ(seq, par);
}

TEST(Gauss_Filter, _320x240) {
    int width = 320;
    int height = 240;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> seq;
    std::vector<uint8_t> par;

    seq = Filter(img, width, height, 32);
    par = ParFilter(img, width, height, 32);
    ASSERT_EQ(seq, par);
}

TEST(Gauss_Filter, _500x500) {
    int width = 500;
    int height = 500;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> seq;
    std::vector<uint8_t> par;

    seq = Filter(img, width, height, 32);
    par = ParFilter(img, width, height, 32);
    ASSERT_EQ(seq, par);
}
/*
TEST(Gauss_Filter, _1000x1000)
{
    int width = 1000;
    int height = 1000;
    std::vector<uint8_t> img = GetRandMatrix(width, height);
    std::vector<uint8_t> seq;
    std::vector<uint8_t> par;
    tbb::tick_count omp_start = tbb::tick_count::now();
    seq = Filter(img, width, height, 32);
    tbb::tick_count omp_end = tbb::tick_count::now();
    tbb::tick_count seq_start = tbb::tick_count::now();
    par = ParFilter(img, width, height, 32);
    tbb::tick_count seq_end = tbb::tick_count::now();
    std::cout << "seq " << (seq_end - seq_start).seconds() << std::endl;
    std::cout << "tbb " << (omp_end - omp_start).seconds() << std::endl;
    ASSERT_EQ(seq, par);
}*/

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
