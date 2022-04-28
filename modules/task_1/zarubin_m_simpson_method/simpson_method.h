// Copyright 2022 Zarubin Mikhail

#ifndef MODULES_TASK_1_ZARUBIN_M_SIMPSON_METHOD_SIMPSON_METHOD_H_
#define MODULES_TASK_1_ZARUBIN_M_SIMPSON_METHOD_SIMPSON_METHOD_H_

#include<functional>
#include<vector>

const double ERROR = 0.001;

using sizeType = std::vector<double>::size_type;


double simpsonMethod(sizeType dimension,
    std::vector<double> leftBorders, std::vector<double> rightBorders,
    std::function<double(std::vector<double>)> function, std::vector<sizeType> countParts);

#endif  // MODULES_TASK_1_ZARUBIN_M_SIMPSON_METHOD_SIMPSON_METHOD_H_
