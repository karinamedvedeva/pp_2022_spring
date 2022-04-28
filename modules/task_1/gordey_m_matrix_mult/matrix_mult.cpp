// Copyright 2022 Gordey Maria
#include "../../../modules/task_1/gordey_m_matrix_mult/matrix_mult.h"
double* create_random_matrix(int size_n) {
    std::random_device dev;
    std::mt19937 gen(dev());
    double* in = new double[size_n];
    for (int i = 0; i < size_n; ++i) {
        in[i] = static_cast<double>(gen()) / gen();
        if (i % 3 == 0) in[i] = 0;
    }
    return in;
}
SparseM operator *(const SparseM& A, const SparseM& B) {
    SparseM C(A);
    std::vector<int> row;
    std::vector<double>value;
    std::vector<int>col_idx;
    transport(&C);
    int ci = 0;
    bool flag = true;
    for (int i = 0; i < B.cols; i++) {
        for (int j = 0; j < C.cols; j++) {
            double res = 0;
            int ls = B.col_idx[i];
            int lf = B.col_idx[i + 1] - 1;
            int ks = C.col_idx[j];
            int kf = C.col_idx[j + 1] - 1;
            while ((ks <= kf) && (ls <= lf)) {
                if (C.row[ks] == B.row[ls]) {
                    res += C.value[ks] * B.value[ls];
                    ks++;
                    ls++;
                } else {
                    if (C.row[ks] < B.row[ls]) {
                        ks++;
                    } else {
                        ls++;
                    }
                }
            }
            if (res != 0) {
                if (flag) {
                    col_idx.push_back(ci);
                    flag = false;
                }
                value.push_back(res);
                row.push_back(j);
                ci++;
            }
        }
        if (flag)  col_idx.push_back(ci);
        flag = true;
    }
    col_idx.push_back(ci);
    C.row = std::move(row);
    C.value = std::move(value);
    C.col_idx = std::move(col_idx);
    return C;
}
void transport(SparseM* ptr) {
    std::vector<std::queue<int>> A(ptr->rows);
    std::vector<std::queue<double>> B(ptr->rows);
    std::vector<int>col_idx(ptr->cols);
    int k = 0;
    bool flag = true;
    for (int i = 0; i < ptr->cols; i++) {
        for (int j = ptr->col_idx[i]; j <= ptr->col_idx[i + 1] - 1; j++) {
            A[ptr->row[j]].push(i);
            B[ptr->row[j]].push(ptr->value[j]);
        }
    }
    ptr->value.resize(0);
    ptr->row.resize(0);
    for (int i = 0; i < ptr->rows; i++) {
        while (!B[i].empty()) {
            if (flag) {
                col_idx[i] = k;
                flag = false;
            }
            ptr->value.push_back(B[i].front());
            B[i].pop();
            ptr->row.push_back(A[i].front());
            A[i].pop();
            k++;
        }
        flag = true;
    }
    col_idx.push_back(k);
    ptr->col_idx = std::move(col_idx);
}
