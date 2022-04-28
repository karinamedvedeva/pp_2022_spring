// Copyright 2022 Elanskiy Alexander
#include "../../../modules/task_1/elanskiy_a_rectangle_method/rectangle_method.h"

double rec_seq(std::vector<std::vector<int>> integrals, int step, const std::function<double(const double&)>& f) {
    std::vector<double> h;
    int size_vec = integrals.size();
    for (int i = 0; i < size_vec; i++) {
        float tmp = integrals[i][1] - integrals[i][0];
        tmp = tmp / step;
        h.push_back(tmp);
    }
    std::vector<double> count;
    for (int i = 0; i <= step; i++) {
        count.push_back(i);
    }
    std::vector<std::vector<double>> Xi;
    for (int i = 0; i < size_vec; i++) {
        std::vector<double> tmp;
        double tmp1 = integrals[i][0];
        tmp.push_back(tmp1);
        for (int j = 0; j < step; j++) {
            tmp1 += h[i];
            tmp.push_back(tmp1);
        }
        Xi.push_back(tmp);
    }
    std::vector<std::vector<double>> Fx;
    for (int i = 0; i < size_vec; i++) {
        std::vector<double> tmp;
        for (int j = 0; j <= step; j++) {
            double t = f(Xi[i][j]);
            tmp.push_back(t);
        }
        Fx.push_back(tmp);
    }
    std::vector<double> res;
    for (int i = 0; i < size_vec; i++) {
        double half_res = 0;
        for (int j = 0; j < step; j++) {
            half_res += Fx[i][j];
        }
        res.push_back(half_res * h[i]);
    }
    double result = 1;
    for (int i = 0; i < size_vec; i++) {
        result *= res[i];
    }
    result = round(result * 10000) / 10000;
    return result;
}
