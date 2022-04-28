// Copyright 2022 Shmanalov Alexander
#include <gtest/gtest.h>
#include <vector>
#include "../../modules/task_1/shmanalov_a_jarvis/jarvis_seq.h"

TEST(Sequential_Jarvis, PointsCount_0) {
    std::vector<Point> points(0);
    ASSERT_ANY_THROW(sequentinalJarvis(points));
}

TEST(Sequential_Jarvis, PointsCount_1) {
    std::vector<Point> points = { Point(48, 17) };
    std::vector<Point> result = sequentinalJarvis(points);
    ASSERT_EQ(points, result);
}

TEST(Sequential_Jarvis, LineWithPointsTest) {
    std::vector<Point> points = { Point(5, 5), Point(7, 7),
                                  Point(9, 9), Point(11, 11) };
    std::vector<Point> result = { Point(5, 5), Point(11, 11) };
    std::vector<Point> resultJarvis = sequentinalJarvis(points);
    ASSERT_EQ(result, resultJarvis);
}

TEST(Sequential_Jarvis, SquareWithPointsTest) {
    std::vector<Point> points = { Point(8, 10), Point(7, 8), Point(3, 11),
        Point(11, 3), Point(3, 3), Point(5, 5), Point(9, 6), Point(11, 11) };
    std::vector<Point> result = { Point(3, 3), Point(11, 3),
                                  Point(11, 11), Point(3, 11) };
    std::vector<Point> resultJarvis = sequentinalJarvis(points);
    ASSERT_EQ(result, resultJarvis);
}

TEST(Sequential_Jarvis, TriangleWithPointsTest) {
    std::vector<Point> points = { Point(20, 10), Point(10, 20), Point(15, 15),
                                  Point(10, 12), Point(5, 5), Point(30, 10) };
    std::vector<Point> result = { Point(5, 5), Point(30, 10), Point(10, 20) };
    std::vector<Point> resultJarvis = sequentinalJarvis(points);
    ASSERT_EQ(result, resultJarvis);
}

TEST(Sequential_Jarvis, AllPointsIsHullTest) {
    std::vector<Point> points = { Point(10, 40), Point(25, 50), Point(5, 25),
                                  Point(35, 20), Point(15, 15), Point(35, 40) };
    std::vector<Point> result = { Point(5, 25), Point(15, 15), Point(35, 20),
                                  Point(35, 40), Point(25, 50), Point(10, 40) };
    std::vector<Point> resultJarvis = sequentinalJarvis(points);
    ASSERT_EQ(result, resultJarvis);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
