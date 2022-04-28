// Copyright 2022 Bakina Kseniia
#include <gtest/gtest.h>

#include "./ccs_matrix_mult.h"

TEST(Bakina_K_ccs_matrix_mult, check_matrix_transposition_small_size) {
    int n = 10, m = 15;
    std::vector<std::vector<double>> A = get_random_matrix(n, m);
    std::vector<std::vector<double>> AT = matrix_transposition(A);
    CCS_matrix A_ccs(convet_to_ccs(A));
    CCS_matrix AT_ccs(convet_to_ccs(AT));

    CCS_matrix AT_check(ccs_matrix_transposition(A_ccs));

    EXPECT_TRUE(AT_check == AT_ccs);
}

TEST(Bakina_K_ccs_matrix_mult, check_matrix_transposition_medium_size) {
    int n = 50, m = 100;
    std::vector<std::vector<double>> A = get_random_matrix(n, m);
    std::vector<std::vector<double>> AT = matrix_transposition(A);
    CCS_matrix A_ccs(convet_to_ccs(A));
    CCS_matrix AT_ccs(convet_to_ccs(AT));

    CCS_matrix AT_check(ccs_matrix_transposition(A_ccs));

    EXPECT_TRUE(AT_check == AT_ccs);
}

TEST(Bakina_K_ccs_matrix_mult, check_matrix_transposition_large_size) {
    int n = 250, m = 150;
    std::vector<std::vector<double>> A = get_random_matrix(n, m);
    std::vector<std::vector<double>> AT = matrix_transposition(A);
    CCS_matrix A_ccs(convet_to_ccs(A));
    CCS_matrix AT_ccs(convet_to_ccs(AT));

    CCS_matrix AT_check(ccs_matrix_transposition(A_ccs));

    EXPECT_TRUE(AT_check == AT_ccs);
}

TEST(Bakina_K_ccs_matrix_mult, check_matrix_multiplication_small_size) {
    int n = 10, m = 15, k = 20;
    std::vector<std::vector<double>> A = get_random_matrix(n, m);
    std::vector<std::vector<double>> B = get_random_matrix(k, n);
    std::vector<std::vector<double>> C = matrix_multplication(A, B);
    CCS_matrix A_ccs(convet_to_ccs(A));
    CCS_matrix B_ccs(convet_to_ccs(B));
    CCS_matrix C_ccs(convet_to_ccs(C));

    CCS_matrix C_betcher(ccs_matrix_multplication(A_ccs, B_ccs));

    EXPECT_TRUE(C_ccs == C_betcher);
}

TEST(Bakina_K_ccs_matrix_mult, check_matrix_multiplication_medium_size) {
    int n = 50, m = 100, k = 80;
    std::vector<std::vector<double>> A = get_random_matrix(n, m);
    std::vector<std::vector<double>> B = get_random_matrix(k, n);
    std::vector<std::vector<double>> C = matrix_multplication(A, B);
    CCS_matrix A_ccs(convet_to_ccs(A));
    CCS_matrix B_ccs(convet_to_ccs(B));
    CCS_matrix C_ccs(convet_to_ccs(C));

    CCS_matrix C_betcher(ccs_matrix_multplication(A_ccs, B_ccs));

    EXPECT_TRUE(C_ccs == C_betcher);
}

TEST(Bakina_K_ccs_matrix_mult, check_matrix_multiplication_large_size) {
    int n = 250, m = 150, k = 300;
    std::vector<std::vector<double>> A = get_random_matrix(n, m);
    std::vector<std::vector<double>> B = get_random_matrix(k, n);
    std::vector<std::vector<double>> C = matrix_multplication(A, B);
    CCS_matrix A_ccs(convet_to_ccs(A));
    CCS_matrix B_ccs(convet_to_ccs(B));
    CCS_matrix C_ccs(convet_to_ccs(C));

    CCS_matrix C_betcher(ccs_matrix_multplication(A_ccs, B_ccs));

    EXPECT_TRUE(C_ccs == C_betcher);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
