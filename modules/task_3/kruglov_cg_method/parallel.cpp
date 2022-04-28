// Copyright 2022 Kruglov Aleksei
#include <algorithm>
#include <numeric>
#include <cmath>
#include "tbb/tbb.h"
#include "../../../modules/task_3/kruglov_cg_method/parallel.h"
#include "../../../modules/task_3/kruglov_cg_method/sequence.h"

double vectorScalarMultiplyParallel(const std::vector<double>& a, const std::vector<double>& b) {
    tbb::enumerable_thread_specific<double> res{0.0};
    tbb::parallel_for(tbb::blocked_range<int>(0, static_cast<int>(a.size())),
                      [&](const tbb::blocked_range<int>& range) {
        for (int i = range.begin(); i < range.end(); i++) {
            res.local() += (a[i] * b[i]);
        }
    });
    return res.combine(std::plus<double>());
}

std::vector<double> solveParallel(const std::vector<std::vector<double>>& matr, const std::vector<double>& b) {
    auto size = static_cast<int>(b.size());
    std::vector<double> curX(size, 0.0);
    std::vector<double> prevX(size, 0.0);
    std::vector<double> curG(size, 0.0);
    std::vector<double> prevG(size, 0.0);
    std::vector<double> curD(size, 0.0);
    std::vector<double> prevD(size, 0.0);
    for (int i = 0; i < size; i++) {
        prevG[i] = -b[i];
    }
    double eps = 0.0001;
    double curEps = 0.0;
    do {
        tbb::parallel_for(tbb::blocked_range<int>(0, size),
                      [&](const tbb::blocked_range<int>& range) {
            for (int i = range.begin(); i < range.end(); i++) {
                curG[i] = vectorScalarMultiply(matr[i], prevX) - b[i];
            }
        });
        double up = vectorScalarMultiplyParallel(curG, curG);
        double down = vectorScalarMultiplyParallel(prevG, prevG);

        tbb::parallel_for(tbb::blocked_range<int>(0, size),
                      [&](const tbb::blocked_range<int>& range) {
            for (int i = range.begin(); i < range.end(); i++) {
                curD[i] = -curG[i] + prevD[i] * up / down;
            }
        });
        up = vectorScalarMultiplyParallel(curD, curG);
        tbb::enumerable_thread_specific<double> down_tbb{0.0};
        tbb::parallel_for(tbb::blocked_range<int>(0, size),
                      [&](const tbb::blocked_range<int>& range) {
            for (int i = range.begin(); i < range.end(); i++) {
                double value = vectorScalarMultiply(matr[i], curD);
                down_tbb.local() += curD[i] * value;
            }
        });
        double s = -up / down_tbb.combine(std::plus<double>());
        tbb::parallel_for(tbb::blocked_range<int>(0, size),
                      [&](const tbb::blocked_range<int>& range) {
            for (int i = range.begin(); i < range.end(); i++) {
                curX[i] = prevX[i] + s * curD[i];
            }
        });
        curEps = std::numeric_limits<double>::lowest();
        for (int i = 0; i < size; i++) {
            curEps = std::fmax(curEps, fabs(curX[i] - prevX[i]));
        }
        std::swap(curX, prevX);
        std::swap(curG, prevG);
        std::swap(curD, prevD);
    } while (curEps > eps);
    return prevX;
}
