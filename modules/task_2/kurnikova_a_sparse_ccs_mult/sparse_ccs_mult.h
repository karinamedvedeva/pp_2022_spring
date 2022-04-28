// Copyright 2022 Kurnikova Anastasia
#ifndef MODULES_TASK_2_KURNIKOVA_A_SPARSE_CCS_MULT_SPARSE_CCS_MULT_H_
#define MODULES_TASK_2_KURNIKOVA_A_SPARSE_CCS_MULT_SPARSE_CCS_MULT_H_
#include <vector>

struct mymat {
    int countv, counth, countnz;
    std::vector<int> rows, cols;
    std::vector<double> num;

    mymat(int v, int h, int nz);
};

mymat t(const mymat* a);
double vecmult(const mymat* a, const mymat* at, int i, int j);
mymat result(const mymat* a, const mymat* b);
bool operator==(const mymat& a, const mymat& b);
mymat seqresult(const mymat* a, const mymat* b);

#endif  // MODULES_TASK_2_KURNIKOVA_A_SPARSE_CCS_MULT_SPARSE_CCS_MULT_H_
