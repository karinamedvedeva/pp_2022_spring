// Copyright 2022 Elanskiy Alexander
#include "../../modules/task_2/elanskiy_a_rectangle_method/rectangle_method.h"
#include "gtest/gtest.h"

double f1(double x) { return 1 / log(x); }
double f2(double x) { return x * x / 2; }

TEST(rec_seq, test_one_integral) {
    std::vector<std::vector<int>> inter = { { 2, 5 } };
    int step = 5;
    double res = rec_par(inter, step, f1);
    double re = 2.8638;
    ASSERT_EQ(res, re);
}

TEST(rec_seq, test_one_integral_another) {
    std::vector<std::vector<int>> inter = { { 0, 1 } };
    int step = 5;
    double res = rec_par(inter, step, f2);
    double re = 0.1200;
    ASSERT_EQ(res, re);
}

TEST(rec_seq, test_two_integrals) {
    std::vector<std::vector<int>> inter = { { 2, 5 },
                                            { 3, 6 } };
    int step = 5;
    double res = rec_par(inter, step, f1);
    double re = 6.2171;
    ASSERT_EQ(res, re);
}

TEST(rec_seq, test_two_integrals_another) {
    std::vector<std::vector<int>> inter = { { 2, 5 },
                                            { 3, 6 } };
    int step = 5;
    double res = rec_par(inter, step, f2);
    double re = 452.7576;
    ASSERT_NEAR(res, re, 0.0001);
}

TEST(rec_seq, test_three_integrals) {
    std::vector<std::vector<int>> inter = { { 2, 5 },
                                            { 3, 7 },
                                            { 4, 9 } };
    int step = 5;
    double res = rec_par(inter, step, f1);
    double re = 22.9244;
    ASSERT_EQ(res, re);
}
/*
TEST(rec_par, test_three_integrals) {
    std::vector<std::vector<int>> inter = { { 2, 5 },
                                            { 3, 7 },
                                            { 4, 9 } };
    int step = 1000;
    long double par_start, par_stop, seq_start, seq_stop;
    double seq_result, par_result;
    seq_start = omp_get_wtime();
    seq_result = rec_seq(inter, step, f1);
    seq_stop = omp_get_wtime();
    par_start = omp_get_wtime();
    par_result = rec_par(inter, step, f1);
    par_stop = omp_get_wtime();
    std::cout << "Time seq: " << seq_stop - seq_start << std::endl;
    std::cout << "Time par: " << par_stop - par_start << std::endl;
    ASSERT_EQ(par_result, seq_result);
}
*/
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
