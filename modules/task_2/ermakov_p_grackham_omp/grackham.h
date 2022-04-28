// Copyright 2022 Ermakov Pavel
#ifndef MODULES_TASK_2_ERMAKOV_P_GRACKHAM_OMP_GRACKHAM_H_
#define MODULES_TASK_2_ERMAKOV_P_GRACKHAM_OMP_GRACKHAM_H_

#include <omp.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

int rotation(const std::pair<double, double>& dot1,
    const std::pair<double, double>& dot2, const std::pair<double, double>& dot3);
double distance(const std::pair<double, double>& dot1,
    const std::pair<double, double>& dot2);
std::vector<std::pair<double, double>> gen_dots(int vectorSize);
std::vector<std::pair<double, double>> grackham_seq(
    std::vector<std::pair<double, double>>::iterator beg,
    std::vector<std::pair<double, double>>::iterator end);
std::vector<std::pair<double, double>> grackham_omp(
    std::vector<std::pair<double, double>>::iterator beg,
    std::vector<std::pair<double, double>>::iterator end,
    std::size_t n_threads);

#endif  // MODULES_TASK_2_ERMAKOV_P_GRACKHAM_OMP_GRACKHAM_H_
