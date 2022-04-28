// Copyright 2022 Vershinin Daniil
#ifndef MODULES_TASK_1_VERSHININ_D_LINEAR_FILTER_HORIZONTAL_LINEAR_FILTER_HORIZONTAL_H_
#define MODULES_TASK_1_VERSHININ_D_LINEAR_FILTER_HORIZONTAL_LINEAR_FILTER_HORIZONTAL_H_

#include <vector>

std::vector<float> getGaussKernel(int radius, float sigma);
float calcNewPixColor(const int x, const int y, const int width,
                      const int height, const std::vector<float>& kernel,
                      int radius, const std::vector<float>& img);
std::vector<float> getSequentialOperations(const int width, const int height,
                                           const std::vector<float>& kernel,
                                           const std::vector<float>& img);

#endif  // MODULES_TASK_1_VERSHININ_D_LINEAR_FILTER_HORIZONTAL_LINEAR_FILTER_HORIZONTAL_H_
