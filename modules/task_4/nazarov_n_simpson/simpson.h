// Copyright 2022 Nazarov Nikita
#ifndef MODULES_TASK_4_NAZAROV_N_SIMPSON_SIMPSON_H_
#define MODULES_TASK_4_NAZAROV_N_SIMPSON_SIMPSON_H_

#include <algorithm>
#include <cmath>
#include <ctime>
#include <functional>
#include <utility>
#include <vector>
#include "../../../3rdparty/unapproved/unapproved.h"

double simpson_seq(double (*func)(const std::vector<double>&),
                   const std::vector<std::pair<double, double>>& borders,
                   const std::vector<int>& steps);

double simpson(double (*func)(const std::vector<double>&),
               const std::vector<std::pair<double, double>>& borders,
               const std::vector<int>& steps);
#endif  // MODULES_TASK_4_NAZAROV_N_SIMPSON_SIMPSON_H_
