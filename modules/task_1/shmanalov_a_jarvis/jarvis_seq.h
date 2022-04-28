// Copyright 2022 Shmanalov Alexander
#ifndef MODULES_TASK_1_SHMANALOV_A_JARVIS_JARVIS_SEQ_H_
#define MODULES_TASK_1_SHMANALOV_A_JARVIS_JARVIS_SEQ_H_

#include <vector>
#include <utility>

using Point = std::pair<int, int>;

std::vector<Point> getRandomCombinationPoints(int size);
Point searchStartPoint(const std::vector<Point>& points);
int getOrientation(const Point& cur, const Point& next, const Point& tmp);
bool checkDistance(const Point& cur, const Point& next, const Point& tmp);
std::vector<Point> sequentinalJarvis(const std::vector<Point>& points);

#endif  // MODULES_TASK_1_SHMANALOV_A_JARVIS_JARVIS_SEQ_H_
