// Copyright 2022 Ershov Aleksey
#ifndef MODULES_TASK_1_ERSHOV_A_DEICSTRA_ALGORITHM_DEICSTRA_SEQ_H_
#define MODULES_TASK_1_ERSHOV_A_DEICSTRA_ALGORITHM_DEICSTRA_SEQ_H_

#include <string>
#include <vector>

std::vector<std::vector<int>> getRandomVector(const size_t count);

std::vector<int> getSequentialDeicstra(
    const std::vector<std::vector<int>>& graf, const size_t top);

#endif  // MODULES_TASK_1_ERSHOV_A_DEICSTRA_ALGORITHM_DEICSTRA_SEQ_H_
