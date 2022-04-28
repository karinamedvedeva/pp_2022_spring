// Copyright 2022 Nazarov Nikita
#ifndef MODULES_TASK_3_NAZAROV_N_SIMPSON_SIMPSON_H_
#define MODULES_TASK_3_NAZAROV_N_SIMPSON_SIMPSON_H_

#include <omp.h>
#include <stdio.h>
#include <tbb/blocked_range.h>
#include <tbb/parallel_reduce.h>
#include <tbb/task_scheduler_init.h>
#include <tbb/tbb.h>

#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <vector>

double simpson(double (*func)(const std::vector<double>&),
               const std::vector<std::pair<double, double>>& borders,
               const std::vector<int>& steps, int process);

#endif  // MODULES_TASK_3_NAZAROV_N_SIMPSON_SIMPSON_H_
