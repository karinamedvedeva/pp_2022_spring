// Copyright 2022 Elanskiy Alexander
#include "../../modules/task_2/elanskiy_a_rectangle_method/rectangle_method.h"

double rec_seq(std::vector<std::vector<int>> integrals, int step, const std::function<double(const double&)>& f) {
    int size_integ = integrals.size();
    std::vector<double> h;
    std::vector<double> res;
    for (int i = 0; i < size_integ; i++) {
        float tmp = integrals[i][1] - integrals[i][0];
        tmp = tmp / step;
        h.push_back(tmp);
        double sum = 0.0;
        for (int j = 0; j < step; j++) {
            sum += f(integrals[i][0] + j * h[i]) * h[i];
        }
        res.push_back(sum);
    }
    double result = 1;
    for (int i = 0; i < size_integ; i++) {
        result *= res[i];
    }
    result = round(result * 10000) / 10000;
    return result;
}

double rec_par(std::vector<std::vector<int>> integrals, int step, const std::function<double(const double&)>& f) {
    int size_integ = integrals.size();
    //  omp_set_num_threads(1);
    std::vector<double> h;
    std::vector<double> res;
    for (int i = 0; i < size_integ; i++) {
        float tmp = integrals[i][1] - integrals[i][0];
        tmp = tmp / step;
        h.push_back(tmp);
        double sum = 0.0;
#pragma omp parallel for reduction(+:sum)
        for (int j = 0; j < step; j++) {
            sum += f(integrals[i][0] + j * h[i]) * h[i];
        }
        res.push_back(sum);
    }
    double result = 1;
#pragma omp parallel for reduction(*:result)
    for (int i = 0; i < size_integ; i++) {
        result *= res[i];
    }
    result = round(result * 10000) / 10000;
    return result;
}
