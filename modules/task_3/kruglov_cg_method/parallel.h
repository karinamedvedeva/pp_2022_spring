// Copyright 2022 Kruglov Aleksei
#ifndef MODULES_TASK_3_KRUGLOV_CG_METHOD_PARALLEL_H_
#define MODULES_TASK_3_KRUGLOV_CG_METHOD_PARALLEL_H_
#include <vector>

double vectorScalarMultiplyParallel(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> solveParallel(const std::vector<std::vector<double>>& matr, const std::vector<double>& b);

#endif  // MODULES_TASK_3_KRUGLOV_CG_METHOD_PARALLEL_H_
