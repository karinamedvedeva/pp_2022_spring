// Copyright 2022 Preobrazhenskaya Yuliya
#ifndef MODULES_TASK_2_PREOBRAZHENSKAYA_Y_HISTOGRAM_STRETCHING_HISTOGRAM_STRETCHING_H_
#define MODULES_TASK_2_PREOBRAZHENSKAYA_Y_HISTOGRAM_STRETCHING_HISTOGRAM_STRETCHING_H_

#include <iostream>

int* getRandomImage(int height, int width);
int getYmax(int* image, int height, int width);
int getYmin(int* image, int height, int width);
int* getSequentialOperations(int* image, int height, int width,
    int y_max, int y_min);
int* getParallelOperationsOMP(int* image, int height, int width,
    int y_max, int y_min);

#endif  // MODULES_TASK_2_PREOBRAZHENSKAYA_Y_HISTOGRAM_STRETCHING_HISTOGRAM_STRETCHING_H_
