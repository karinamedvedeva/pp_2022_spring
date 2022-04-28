// Copyright 2022 Barysheva Maria
#ifndef MODULES_TASK_2_BARYSHEVA_M_FOX_ALGORITHM_OPMP_FOX_ALGORITHM_OPMP_H_
#define MODULES_TASK_2_BARYSHEVA_M_FOX_ALGORITHM_OPMP_FOX_ALGORITHM_OPMP_H_

#include <cmath>
#include <vector>

std::vector<std::vector<double>> GetRandomMatrix(const int& n);
std::vector<std::vector<double>> SimpleMultiplication(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& B);
std::vector<std::vector<double>> BlockMultiplication(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& B);

std::vector<std::vector<double>> FoxParallel(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& B, const unsigned& thread);

bool CompareMatrix(const std::vector<std::vector<double>>& A,
                   const std::vector<std::vector<double>>& B);

#endif  // MODULES_TASK_2_BARYSHEVA_M_FOX_ALGORITHM_OPMP_FOX_ALGORITHM_OPMP_H_
