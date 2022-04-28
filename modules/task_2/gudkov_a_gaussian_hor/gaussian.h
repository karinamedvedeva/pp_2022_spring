// Copyright 2022 Gudkov Andrey
#ifndef MODULES_TASK_2_GUDKOV_A_GAUSSIAN_HOR_GAUSSIAN_H_
#define MODULES_TASK_2_GUDKOV_A_GAUSSIAN_HOR_GAUSSIAN_H_
#include <cstdint>
#include <cmath>
#include <ctime>
#include <vector>
#include <random>
#include <cinttypes>

int GetIndex(int i, int j, int offset);
std::vector<uint8_t> GetRandMatrix(int offset, int pixelHeight);
std::vector<uint8_t> Filter(std::vector<uint8_t> srcVec, int offset,
    int pixelHeight, double sigma = 1.0);
std::vector<uint8_t> ParFilter(std::vector<uint8_t> srcVec, int offset,
    int pixelHeight, int threads = 2, double sigma = 1.0);

#endif  // MODULES_TASK_2_GUDKOV_A_GAUSSIAN_HOR_GAUSSIAN_H_
