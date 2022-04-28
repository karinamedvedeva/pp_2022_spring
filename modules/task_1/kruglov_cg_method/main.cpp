// Copyright 2022 Kruglov Aleksei
#include <gtest/gtest.h>
#include <iostream>
#include "./sequence.h"

void print_info(const std::vector<std::vector<double>>& matr, const std::vector<double>& x,
             const std::vector<double>& b) {
    bool log = false;
    if (log) {
        auto size = x.size();
        for (std::size_t i = 0; i < size; i++) {
            std::cout << std::fixed << std::setprecision(14) << vectorScalarMultiply(matr[i], x) << ' ';
        }
        std::cout << '\n';
        for (std::size_t i = 0; i < size; i++) {
            std::cout << std::fixed << std::setprecision(14) << b[i] << ' ';
        }
    }
}

TEST(CGmethod, size50) {
    std::size_t size = 50;
    auto b = generateVector(size);
    auto matr = generateMatrix(size);
    auto x = solve(matr, b);
    print_info(matr, x, b);
    ASSERT_TRUE(checkSolution(matr, x, b));
}

TEST(CGmethod, size100) {
    std::size_t size = 100;
    auto b = generateVector(size);
    auto matr = generateMatrix(size);
    auto x = solve(matr, b);
    print_info(matr, x, b);
    ASSERT_TRUE(checkSolution(matr, x, b));
}

TEST(CGmethod, size150) {
    std::size_t size = 150;
    auto b = generateVector(size);
    auto matr = generateMatrix(size);
    auto x = solve(matr, b);
    print_info(matr, x, b);
    ASSERT_TRUE(checkSolution(matr, x, b));
}

TEST(CGmethod, size250) {
    std::size_t size = 250;
    auto b = generateVector(size);
    auto matr = generateMatrix(size);
    auto x = solve(matr, b);
    print_info(matr, x, b);
    ASSERT_TRUE(checkSolution(matr, x, b));
}

TEST(CGmethod, size500) {
    std::size_t size = 500;
    auto b = generateVector(size);
    auto matr = generateMatrix(size);
    auto x = solve(matr, b);
    print_info(matr, x, b);
    ASSERT_TRUE(checkSolution(matr, x, b));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
