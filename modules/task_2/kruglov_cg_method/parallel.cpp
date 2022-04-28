// Copyright 2022 Kruglov Aleksei
#include <omp.h>
#include <algorithm>
#include <numeric>
#include <cmath>
#include "../../../modules/task_2/kruglov_cg_method/parallel.h"
#include "../../../modules/task_2/kruglov_cg_method/sequence.h"

double vectorScalarMultiplyParallel(const std::vector<double>& a, const std::vector<double>& b) {
    double res = 0.0;
    auto n = static_cast<int>(a.size());
    #pragma omp parallel for reduction(+: res)
    for (int i = 0; i < n; i++) {
        res = res + (a[i] * b[i]);
    }
    return res;
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
        #pragma omp parallel for
        for (int i = 0; i < size; i++) {
            curG[i] = vectorScalarMultiply(matr[i], prevX) - b[i];
        }
        double up = vectorScalarMultiplyParallel(curG, curG);
        double down = vectorScalarMultiplyParallel(prevG, prevG);

        #pragma omp parallel for
        for (int i = 0; i < size; i++) {
            curD[i] = -curG[i] + prevD[i] * up / down;
        }
        up = vectorScalarMultiplyParallel(curD, curG);
        down = 0.0;
        #pragma omp parallel for reduction(+:down)
        for (int i = 0; i < size; i++) {
            double value = vectorScalarMultiply(matr[i], curD);
            down += curD[i] * value;
        }
        double s = -up / down;
        #pragma omp parallel for
        for (int i = 0; i < size; i++) {
            curX[i] = prevX[i] + s * curD[i];
        }
        curEps = std::numeric_limits<double>::min();
        for (int i = 0; i < size; i++) {
            curEps = std::max(curEps, fabs(curX[i] - prevX[i]));
        }
        std::swap(curX, prevX);
        std::swap(curG, prevG);
        std::swap(curD, prevD);
    } while (curEps > eps);
    return prevX;
}
