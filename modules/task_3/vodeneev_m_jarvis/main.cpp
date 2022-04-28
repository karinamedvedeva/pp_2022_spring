// Copyright 2022 VODENEEV MIKHAIL
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "./jarvis.h"


TEST(Jarvis_test_tbb, less_than_minimum_required_size) {
    std::vector<std::pair<double, double>> points = GetPoints(0, 10, 0, 10, 0);
    ASSERT_ANY_THROW(JarvisTbb(points));
}

TEST(Jarvis_test_tbb, work_with_the_correct_set_size) {
    std::vector<std::pair<double, double>> points = GetPoints(0, 10, 0, 10, 10);
    ASSERT_NO_THROW(JarvisTbb(points));
}

TEST(Jarvis_test_tbb, hull_for_3_points) {
    std::vector<std::pair<double, double>> points = { {1, 1}, {0, 0}, {0, 1} };

    std::vector<std::pair<double, double>> res = JarvisTbb(points);
    std::vector<std::pair<double, double>> expect_set = { {0, 0}, {1, 1}, {0, 1} };

    ASSERT_EQ(res, expect_set);
}

TEST(Jarvis_test_tbb, hull_for_5_points) {
    std::vector<std::pair<double, double>> points = { {0, 0}, {0, 4}, {4, 4}, {4, 0}, {2, 2} };

    std::vector<std::pair<double, double>> res = JarvisTbb(points);
    std::vector<std::pair<double, double>> expect_set = { {0, 0}, {4, 0}, {4, 4}, {0, 4} };

    ASSERT_EQ(res, expect_set);
}

TEST(Jarvis_test_tbb, hull_for_8_points) {
    std::vector<std::pair<double, double>> points = { {0, 0}, {0, 4}, {4, 4}, {4, 0}, {2, 2},
        {0.5, 0.5}, {1, 1.5}, {1.5, 1} };
    std::vector<std::pair<double, double>> res = JarvisTbb(points);
    std::vector<std::pair<double, double>> expect_set = { {0, 0}, {4, 0}, {4, 4}, {0, 4} };

    ASSERT_EQ(res, expect_set);
}

TEST(Jarvis_test_tbb, compare_seq_and_tbb_1000_points) {
    std::vector<std::pair<double, double>> points = GetPoints(-1000, 1000, -1000, 1000, 1000);
    tbb::tick_count start_seq = tbb::tick_count::now();
    std::vector<std::pair<double, double>> res_seq = JarvisSeq(points);
    tbb::tick_count end_seq = tbb::tick_count::now();
    tbb::tick_count start_tbb = tbb::tick_count::now();
    std::vector<std::pair<double, double>> res_tbb = JarvisTbb(points);
    tbb::tick_count end_tbb = tbb::tick_count::now();


    std::cout << "Time seq: " << (end_seq - start_seq).seconds() << std::endl;
    std::cout << "Time tbb: " << (end_tbb - start_tbb).seconds() << std::endl;

    ASSERT_EQ(res_tbb, res_seq);
}

TEST(Jarvis_test_tbb, compare_seq_and_tbb_10000_points) {
    std::vector<std::pair<double, double>> points = GetPoints(-1000, 1000, -1000, 1000, 10000);
    tbb::tick_count start_seq = tbb::tick_count::now();
    std::vector<std::pair<double, double>> res_seq = JarvisSeq(points);
    tbb::tick_count end_seq = tbb::tick_count::now();
    tbb::tick_count start_tbb = tbb::tick_count::now();
    std::vector<std::pair<double, double>> res_tbb = JarvisTbb(points);
    tbb::tick_count end_tbb = tbb::tick_count::now();


    std::cout << "Time seq: " << (end_seq - start_seq).seconds() << std::endl;
    std::cout << "Time tbb: " << (end_tbb - start_tbb).seconds() << std::endl;

    ASSERT_EQ(res_tbb, res_seq);
}

TEST(Jarvis_test_tbb, compare_seq_and_tbb_100000_points) {
    std::vector<std::pair<double, double>> points = GetPoints(-1000, 1000, -1000, 1000, 100000);
    tbb::tick_count start_seq = tbb::tick_count::now();
    std::vector<std::pair<double, double>> res_seq = JarvisSeq(points);
    tbb::tick_count end_seq = tbb::tick_count::now();
    tbb::tick_count start_tbb = tbb::tick_count::now();
    std::vector<std::pair<double, double>> res_tbb = JarvisTbb(points);
    tbb::tick_count end_tbb = tbb::tick_count::now();


    std::cout << "Time seq: " << (end_seq - start_seq).seconds() << std::endl;
    std::cout << "Time tbb: " << (end_tbb - start_tbb).seconds() << std::endl;

    ASSERT_EQ(res_tbb, res_seq);
}
