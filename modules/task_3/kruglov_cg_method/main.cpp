// Copyright 2022 Kruglov Aleksei
#include <gtest/gtest.h>
#include <tbb/tbb.h>
#include <iostream>
#include "./sequence.h"
#include "./parallel.h"

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

TEST(CGmethodTBB, size50) {
    auto size = 50;
    auto b = generateVector(size);
    auto matr = generateMatrix(size);

    auto t1 = tbb::tick_count::now();
    auto x = solveParallel(matr, b);
    auto t2 = tbb::tick_count::now();
    auto par = (t2 - t1).seconds();
    std::cout << "parallel: " << par << " s \n";

    t1 = tbb::tick_count::now();
    auto x_ref = solve(matr, b);
    t2 = tbb::tick_count::now();
    auto seq = (t2 - t1).seconds();
    std::cout << "sequence: " << seq << " s \n";

    std::cout << "seq/par: " << seq / par << " \n";
    print_info(matr, x, b);
    ASSERT_TRUE(checkSolution(matr, x, b));
}

TEST(CGmethodTBB, size100) {
    auto size = 100;
    auto b = generateVector(size);
    auto matr = generateMatrix(size);

    auto t1 = tbb::tick_count::now();
    auto x = solveParallel(matr, b);
    auto t2 = tbb::tick_count::now();
    auto par = (t2 - t1).seconds();
    std::cout << "parallel: " << par << " s \n";

    t1 = tbb::tick_count::now();
    auto x_ref = solve(matr, b);
    t2 = tbb::tick_count::now();
    auto seq = (t2 - t1).seconds();
    std::cout << "sequence: " << seq << " s \n";

    std::cout << "seq/par: " << seq / par << " \n";
    ASSERT_TRUE(checkSolution(matr, x, b));
}

TEST(CGmethodTBB, size250) {
    auto size = 250;
    auto b = generateVector(size);
    auto matr = generateMatrix(size);

    auto t1 = tbb::tick_count::now();
    auto x = solveParallel(matr, b);
    auto t2 = tbb::tick_count::now();
    auto par = (t2 - t1).seconds();
    std::cout << "parallel: " << par << " s \n";

    t1 = tbb::tick_count::now();
    auto x_ref = solve(matr, b);
    t2 = tbb::tick_count::now();
    auto seq = (t2 - t1).seconds();
    std::cout << "sequence: " << seq << " s \n";

    std::cout << "seq/par: " << seq / par << " \n";
    print_info(matr, x, b);
    ASSERT_TRUE(checkSolution(matr, x, b));
}

TEST(CGmethodTBB, size350) {
    auto size = 350;
    auto b = generateVector(size);
    auto matr = generateMatrix(size);

    auto t1 = tbb::tick_count::now();
    auto x = solveParallel(matr, b);
    auto t2 = tbb::tick_count::now();
    auto par = (t2 - t1).seconds();
    std::cout << "parallel: " << par << " s \n";

    t1 = tbb::tick_count::now();
    auto x_ref = solve(matr, b);
    t2 = tbb::tick_count::now();
    auto seq = (t2 - t1).seconds();
    std::cout << "sequence: " << seq << " s \n";

    std::cout << "seq/par: " << seq / par << " \n";
    print_info(matr, x, b);
    ASSERT_TRUE(checkSolution(matr, x, b));
}

TEST(CGmethodTBB, size450) {
    auto size = 450;
    auto b = generateVector(size);
    auto matr = generateMatrix(size);

    auto t1 = tbb::tick_count::now();
    auto x = solveParallel(matr, b);
    auto t2 = tbb::tick_count::now();
    auto par = (t2 - t1).seconds();
    std::cout << "parallel: " << par << " s \n";

    t1 = tbb::tick_count::now();
    auto x_ref = solve(matr, b);
    t2 = tbb::tick_count::now();
    auto seq = (t2 - t1).seconds();
    std::cout << "sequence: " << seq << " s \n";

    std::cout << "seq/par: " << seq / par << " \n";
    print_info(matr, x, b);
    ASSERT_TRUE(checkSolution(matr, x, b));
}

TEST(CGmethodTBB, size550) {
    auto size = 550;
    auto b = generateVector(size);
    auto matr = generateMatrix(size);

    auto t1 = tbb::tick_count::now();
    auto x = solveParallel(matr, b);
    auto t2 = tbb::tick_count::now();
    auto par = (t2 - t1).seconds();
    std::cout << "parallel: " << par << " s \n";

    t1 = tbb::tick_count::now();
    auto x_ref = solve(matr, b);
    t2 = tbb::tick_count::now();
    auto seq = (t2 - t1).seconds();
    std::cout << "sequence: " << seq << " s \n";

    std::cout << "seq/par: " << seq / par << " \n";
    print_info(matr, x, b);
    ASSERT_TRUE(checkSolution(matr, x, b));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
