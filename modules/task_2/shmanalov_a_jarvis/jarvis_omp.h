// Copyright 2022 Shmanalov Alexander
#ifndef MODULES_TASK_2_SHMANALOV_A_JARVIS_JARVIS_OMP_H_
#define MODULES_TASK_2_SHMANALOV_A_JARVIS_JARVIS_OMP_H_

#include <omp.h>
#include <vector>
#include <utility>

using Point = std::pair<int, int>;

std::vector<Point> getRandomCombinationPoints(int size);
Point searchStartPoint(const std::vector<Point>& points);
int getDir(const Point& cur, const Point& next, const Point& tmp);
bool checkDistance(const Point& cur, const Point& next, const Point& tmp);
std::vector<Point> sequentinalJarvis(const std::vector<Point>& points);
std::vector<Point> openmpJarvis(const std::vector<Point>& points);

#endif  // MODULES_TASK_2_SHMANALOV_A_JARVIS_JARVIS_OMP_H_
