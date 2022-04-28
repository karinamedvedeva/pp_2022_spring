// Copyright 2022 Chornyi Yura
#ifndef MODULES_TASK_4_CHORNYI_Y_SHELL_SORT_WITH_BETCHER_SHELL_SORT_H_
#define MODULES_TASK_4_CHORNYI_Y_SHELL_SORT_WITH_BETCHER_SHELL_SORT_H_

#include <vector>

std::vector<int> getRandomVector(const std::vector<int>::size_type size);
void getSequantialShellSort(std::vector<int>* commonVector);
std::vector<int> getParallelShellSort(const std::vector<int>& commonVector);

#endif  // MODULES_TASK_4_CHORNYI_Y_SHELL_SORT_WITH_BETCHER_SHELL_SORT_H_
