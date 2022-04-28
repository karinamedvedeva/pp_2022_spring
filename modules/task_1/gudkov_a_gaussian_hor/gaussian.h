// Copyright 2022 Gudkov Andrey
#ifndef MODULES_TASK_1_GUDKOV_A_GAUSSIAN_HOR_GAUSSIAN_H_
#define MODULES_TASK_1_GUDKOV_A_GAUSSIAN_HOR_GAUSSIAN_H_

#include <cmath>
#include <ctime>
#include <vector>
#include <random>
#include <cinttypes>

int GetIndex(int i, int j, int offset);
std::vector<uint8_t> GetRandMatrix(int offset, int pixelHeight);
std::vector<uint8_t> Filter(std::vector<uint8_t> srcVec, int offset,
    int pixelHeight, double sigma = 1.0);

#endif  // MODULES_TASK_1_GUDKOV_A_GAUSSIAN_HOR_GAUSSIAN_H_
