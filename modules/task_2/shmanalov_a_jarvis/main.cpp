// Copyright 2022 Shmanalov Alexander
#include <gtest/gtest.h>
#include <iostream>
#include "../../modules/task_2/shmanalov_a_jarvis/jarvis_omp.h"

TEST(Omp_Jarvis, PointsCount_0) {
    std::vector<Point> points(0);
    ASSERT_ANY_THROW(openmpJarvis(points));
}

TEST(Omp_Jarvis, PointsCount_2500) {
    std::vector<Point> points = getRandomCombinationPoints(2500);
    std::vector<Point> resultSeq = sequentinalJarvis(points);
    std::vector<Point> resultOmp = openmpJarvis(points);
    ASSERT_EQ(resultSeq, resultOmp);
}

TEST(Omp_Jarvis, PointsCount_5000) {
    std::vector<Point> points = getRandomCombinationPoints(5000);
    std::vector<Point> resultSeq = sequentinalJarvis(points);
    std::vector<Point> resultOmp = openmpJarvis(points);
    ASSERT_EQ(resultSeq, resultOmp);
}

TEST(Omp_Jarvis, PointsCount_75000) {
    std::vector<Point> points = getRandomCombinationPoints(75000);
    std::vector<Point> resultSeq = sequentinalJarvis(points);
    std::vector<Point> resultOmp = openmpJarvis(points);
    ASSERT_EQ(resultSeq, resultOmp);
}

TEST(Omp_Jarvis, PointsCount_1000000) {
    std::vector<Point> points = getRandomCombinationPoints(1000000);
    // double startSeq = omp_get_wtime();
    std::vector<Point> resultSeq = sequentinalJarvis(points);
    // double endSeq = omp_get_wtime();
    // double timeSeq = endSeq - startSeq;
    // std::cout << "Sequential = " << timeSeq << std::endl;
    // double startOmp = omp_get_wtime();
    std::vector<Point> resultOmp = openmpJarvis(points);
    // double endOmp = omp_get_wtime();
    // double timeOmp = endOmp - startOmp;
    // std::cout << "Parallel [OpenMP] = " << timeOmp << std::endl;
    // std::cout << "Efficiency = " << timeSeq / timeOmp << std::endl;
    ASSERT_EQ(resultSeq, resultOmp);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    // omp_set_num_threads(8);
    return RUN_ALL_TESTS();
}
