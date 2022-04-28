// Copyright 2022 Preobrazhenskaya Yuliya
#include <omp.h>
#include <random>
#include "../../../modules/task_2/preobrazhenskaya_y_histogram_stretching/histogram_stretching.h"

int* getRandomImage(int height, int width) {
    if (height <= 0 || width <= 0) {
        throw - 1;
    }
    std::random_device dev;
    std::mt19937 gen(dev());
    int* image = new int[height * width];
    for (int i = 0; i < height * width; i++) { image[i] = gen() % 256; }
    return image;
}

int getYmax(int* image, int height, int width) {
    if (height <= 0 || width <= 0) {
        throw - 1;
    }
    int y_max = 0;
    for (int i = 0; i < height * width; i++) {
        if (image[i] > y_max) {
            y_max = image[i];
        }
    }
    return y_max;
}

int getYmin(int* image, int height, int width) {
    if (height <= 0 || width <= 0) {
        throw - 1;
    }
    int y_min = 255;
    for (int i = 0; i < height * width; i++) {
        if (image[i] < y_min) {
            y_min = image[i];
        }
    }
    return y_min;
}

int* getSequentialOperations(int* image, int height, int width,
    int y_max, int y_min) {
    if (height <= 0 || width <= 0) {
        throw - 1;
    }
    int* result_image = new int[height * width];
    for (int i = 0; i < height * width; i++) {
        result_image[i] = (image[i] - y_min) * ((255 - 0) / (y_max - y_min));
        if (result_image[i] < 0) {
            result_image[i] = 0;
        }
        if (result_image[i] > 255) {
            result_image[i] = 255;
        }
    }
    return result_image;
}

int* getParallelOperationsOMP(int* image, int height, int width,
    int y_max, int y_min) {
    if (height <= 0 || width <= 0) {
        throw - 1;
    }
    int* result_image = new int[height * width];

#pragma omp parallel for
    for (int i = 0; i < height * width; i++) {
        result_image[i] =
            (image[i] - y_min) * ((255 - 0) / (y_max - y_min));
        if (result_image[i] < 0) {
            result_image[i] = 0;
        }
        if (result_image[i] > 255) {
            result_image[i] = 255;
        }
    }
    return result_image;
}
