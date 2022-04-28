// Copyright 2022 Kruglov Aleksei
#ifndef MODULES_TASK_3_KRUGLOV_CG_METHOD_SEQUENCE_H_
#define MODULES_TASK_3_KRUGLOV_CG_METHOD_SEQUENCE_H_

#include <vector>

std::vector<double> generateVector(std::size_t size);
std::vector<std::vector<double>> generateMatrix(std::size_t size);

double vectorScalarMultiply(const std::vector<double>& a, const std::vector<double>& b);

std::vector<double> solve(const std::vector<std::vector<double>>& matr, const std::vector<double>& b);

bool checkSolution(const std::vector<std::vector<double>>& matr,
                   const std::vector<double>& x, const std::vector<double>& b);

#endif  // MODULES_TASK_3_KRUGLOV_CG_METHOD_SEQUENCE_H_
