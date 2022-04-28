// Copyright 2022 Kruglov Aleksei
#include <random>
#include <algorithm>
#include <numeric>
#include <cmath>
#include "../../../modules/task_1/kruglov_cg_method/sequence.h"

std::vector<double> generateVector(std::size_t size) {
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_real_distribution<double> distribution(100, 200);
    std::vector<double> vec(size);
    for (std::size_t i = 0; i < size; i++) {
        vec[i] = distribution(engine);
    }
    return vec;
}

std::vector<std::vector<double>> generateMatrix(std::size_t size) {
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_real_distribution<double> distribution(0, 10);
    std::vector<std::vector<double>> res(size, std::vector<double>(size));
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j <=i ; j++) {
            res[i][j] = distribution(engine);
        }
    }
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = i + 1; j < size; j++) {
            res[i][j] = res[j][i];
        }
    }
    return res;
}

double vectorScalarMultiply(const std::vector<double>& a, const std::vector<double>& b) {
    double res = 0.0;
    for (std::size_t i = 0; i < a.size(); i++) {
        res += (a[i] * b[i]);
    }
    return res;
}

std::vector<double> solve(const std::vector<std::vector<double>>& matr, const std::vector<double>& b) {
    auto size = b.size();
    std::vector<double> curX(size, 0.0);
    std::vector<double> prevX(size, 0.0);
    std::vector<double> curG(size, 0.0);
    std::vector<double> prevG(size, 0.0);
    std::vector<double> curD(size, 0.0);
    std::vector<double> prevD(size, 0.0);
    for (std::size_t i = 0; i < size; i++) {
        prevG[i] = -b[i];
    }
    double eps = 0.0001;
    double curEps = 0.0;

    do {
        for (std::size_t i = 0; i < size; i++) {
            curG[i] = vectorScalarMultiply(matr[i], prevX) - b[i];
        }
        double up = vectorScalarMultiply(curG, curG);
        double down = vectorScalarMultiply(prevG, prevG);

        for (std::size_t i = 0; i < size; i++) {
            curD[i] = -curG[i] + prevD[i] * up / down;
        }
        up = vectorScalarMultiply(curD, curG);
        down = 0.0;
        for (std::size_t i = 0; i < size; i++) {
            double value = vectorScalarMultiply(matr[i], curD);
            down += curD[i] * value;
        }
        double s = -up / down;
        for (std::size_t i = 0; i < size; i++) {
            curX[i] = prevX[i] + s * curD[i];
        }
        curEps = std::numeric_limits<double>::min();
        for (std::size_t i = 0; i < size; i++) {
            curEps = std::max(curEps, std::fabs(curX[i] - prevX[i]));
        }
        std::swap(curX, prevX);
        std::swap(curG, prevG);
        std::swap(curD, prevD);
    } while (curEps > eps);

    return prevX;
}

bool checkSolution(const std::vector<std::vector<double>>& matr,
                   const std::vector<double>& x, const std::vector<double>& b) {
    auto size = x.size();
    double eps = std::numeric_limits<double>::min();
    for (std::size_t i = 0; i < size; i++) {
        eps = std::max(eps, fabs(b[i] - vectorScalarMultiply(matr[i], x)));
    }
    return eps <= 0.5;
}
