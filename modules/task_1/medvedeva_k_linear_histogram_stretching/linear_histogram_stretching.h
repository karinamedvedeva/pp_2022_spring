// Copyright 2022 Medvedeva Karina
#ifndef MODULES_TASK_1_MEDVEDEVA_K_LINEAR_HISTOGRAM_STRETCHING_H
#define MODULES_TASK_1_MEDVEDEVA_K_LINEAR_HISTOGRAM_STRETCHING_H

#include <vector>

std::vector<int> getRandomMatrix(std::vector<int>::size_type row_count, 
    std::vector<int>::size_type column_count);
std::vector<int> getSequentialOperations(const std::vector<int>& matrix,
    std::vector<int>::size_type row_count,
    std::vector<int>::size_type column_count);

#endif  // MODULES_TASK_1_MEDVEDEVA_K_LINEAR_HISTOGRAM_STRETCHING_H
