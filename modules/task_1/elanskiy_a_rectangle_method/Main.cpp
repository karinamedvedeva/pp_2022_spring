// Copyright 2022 Elanskiy Alexander
#include "gtest/gtest.h"
#include "../../../modules/task_1/elanskiy_a_rectangle_method/rectangle_method.h"

double f1(double x) { return 1 / log(x); }
double f2(double x) { return x * x / 2; }

TEST(rec_seq, test_one_integral_another) {
    std::vector<std::vector<int>> inter = { { 0, 1 } };
    int step = 5;
    double res = rec_seq(inter, step, f2);
    double re = 0.1200;
    ASSERT_EQ(res, re);
}

TEST(rec_seq, test_one_integral) {
    std::vector<std::vector<int>> inter = { { 2, 5 } };
    int step = 5;
    double res = rec_seq(inter, step, f1);
    double re = 2.8638;
    ASSERT_EQ(res, re);
}

TEST(rec_seq, test_two_integrals_another) {
    std::vector<std::vector<int>> inter = { { 2, 5 },
                                            { 3, 6 } };
    int step = 5;
    double res = rec_seq(inter, step, f2);
    double re = 452.7576;
    ASSERT_NEAR(res, re, 0.0001);
}

TEST(rec_seq, test_two_integrals) {
    std::vector<std::vector<int>> inter = { { 2, 5 },
                                            { 3, 6 } };
    int step = 5;
    double res = rec_seq(inter, step, f1);
    double re = 6.2171;
    ASSERT_EQ(res, re);
}

TEST(rec_seq, test_three_integrals) {
    std::vector<std::vector<int>> inter = { { 2, 5 },
                                            { 3, 7 },
                                            { 4, 9 } };
    int step = 5;
    double res = rec_seq(inter, step, f1);
    double re = 22.9244;
    ASSERT_EQ(res, re);
}
