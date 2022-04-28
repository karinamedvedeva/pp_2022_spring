// Copyright 2022 Ermakov Pavel
#include "../../../modules/task_3/ermakov_p_grackham_tbb/grackham.h"
#include "gtest/gtest.h"
#define THREAD_NUM 4

TEST(grackham_seq, test_size_0) {
    std::vector<std::pair<double, double>> dots;
    int size = 0;
    dots = gen_dots(size);
    std::vector<std::pair<double, double>> seq_res;
    seq_res = grackham_seq(dots.begin(), dots.end());
    ASSERT_EQ(seq_res, seq_res);
}

TEST(grackham_seq, test_size_100) {
    std::vector<std::pair<double, double>> dots;
    int size = 100;
    dots = gen_dots(size);
    std::vector<std::pair<double, double>> seq_res;
    std::vector<std::pair<double, double>> omp_res;

    seq_res = grackham_seq(dots.begin(), dots.end());
    omp_res = grackham_tbb(dots.begin(), dots.end(), THREAD_NUM);

    ASSERT_EQ(seq_res, seq_res);
}

/*TEST(grackham_seq, test_size_500000)
{
     std::vector<std::pair<double, double>> dots;
    int size = 500000;
    dots = gen_dots(size);
    std::vector<std::pair<double, double>> seq_res;
    std::vector<std::pair<double, double>> omp_res;
    tbb::tick_count omp_start = tbb::tick_count::now();
    omp_res = grackham_tbb(dots.begin(), dots.end(), THREAD_NUM);
    tbb::tick_count omp_end = tbb::tick_count::now();
    tbb::tick_count seq_start = tbb::tick_count::now();
    seq_res = grackham_seq(dots.begin(), dots.end());
    tbb::tick_count seq_end = tbb::tick_count::now();
    
    std::cout << "seq " << (seq_end - seq_start).seconds() << std::endl;
    std::cout << "tbb " << (omp_end - omp_start).seconds() << std::endl;

    ASSERT_EQ(seq_res, omp_res);
}*/

TEST(grackham_seq, test_size_200) {
    std::vector<std::pair<double, double>> dots;
    int size = 200;
    dots = gen_dots(size);
    std::vector<std::pair<double, double>> seq_res;
    std::vector<std::pair<double, double>> omp_res;

    seq_res = grackham_seq(dots.begin(), dots.end());
    omp_res = grackham_tbb(dots.begin(), dots.end(), THREAD_NUM);

    ASSERT_EQ(seq_res, seq_res);
}

TEST(grackham_seq, test_size_400) {
    std::vector<std::pair<double, double>> dots;
    int size = 400;
    dots = gen_dots(size);
    std::vector<std::pair<double, double>> seq_res;
    std::vector<std::pair<double, double>> omp_res;

    seq_res = grackham_seq(dots.begin(), dots.end());
    omp_res = grackham_tbb(dots.begin(), dots.end(), THREAD_NUM);

    ASSERT_EQ(seq_res, seq_res);
}

TEST(grackham_seq, test_size_1000) {
    std::vector<std::pair<double, double>> dots;
    int size = 1000;
    dots = gen_dots(size);
    std::vector<std::pair<double, double>> seq_res;
    std::vector<std::pair<double, double>> omp_res;

    seq_res = grackham_seq(dots.begin(), dots.end());
    omp_res = grackham_tbb(dots.begin(), dots.end(), THREAD_NUM);

    ASSERT_EQ(seq_res, seq_res);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
