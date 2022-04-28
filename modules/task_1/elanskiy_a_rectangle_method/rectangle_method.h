// Copyright 2022 Elanskiy Alexander
#ifndef MODULES_TASK_1_ELANSKIY_A_RECTANGLE_METHOD_RECTANGLE_METHOD_H_
#define MODULES_TASK_1_ELANSKIY_A_RECTANGLE_METHOD_RECTANGLE_METHOD_H_

#include <gtest/gtest.h>
#include <math.h>
#include <omp.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

double rec_seq(std::vector<std::vector<int>> integrals, int step, const std::function<double(const double&)>& f);


#endif  // MODULES_TASK_1_ELANSKIY_A_RECTANGLE_METHOD_RECTANGLE_METHOD_H_
