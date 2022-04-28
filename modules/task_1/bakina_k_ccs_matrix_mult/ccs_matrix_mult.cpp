// Copyright 2022 Bakina Kseniia

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

#include "../../../modules/task_1/bakina_k_ccs_matrix_mult/ccs_matrix_mult.h"

std::vector<std::vector<double>> get_random_matrix(int n, int m) {
    if (n < 0 || m < 0) {
        throw("Wrong matrix size for generation");
    }
    std::srand(time(0));
    std::vector<std::vector<double>> matrix(n);
    for (int i = 0; i < n; ++i) {
        matrix[i].resize(m);
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = (std::rand() % 2 == 0) ? 0 :
                static_cast<double>(std::rand()) +
                static_cast<double>(std::rand()) / RAND_MAX;
        }
    }
    return matrix;
}

bool CCS_matrix::operator==(const CCS_matrix& m) {
    return this->row_n == m.row_n && this->col_n == m.col_n
        && this->value == m.value && this->row == m.row
        && this->column_pointer == m.column_pointer;
}

std::vector<std::vector<double>> matrix_transposition(
    const std::vector<std::vector<double>>& B) {
    if (B.empty()) {
        throw("Empty matrix for transposition");
    }
    std::vector<std::vector<double>> BT;
    int m = B[0].size();
    BT.resize(m);
    int Bn = B.size();
    for (int i = 0; i < Bn; ++i) {
        for (int j = 0; j < m; ++j) {
            BT[j].push_back(B[i][j]);
        }
    }
    return BT;
}

std::vector<std::vector<double>> matrix_multplication(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& B) {
    if (B.size() > 0 && A.size() != B[0].size()) {
        throw("Wrong matrix sizes for multiplication");
    }
    std::vector<std::vector<double>> C;
    C.resize(B.size());
    int An = A.size();
    int Cn = C.size();
    for (int i = 0; i < Cn; i++) {
        int m = A[0].size();
        C[i].resize(m);
        for (int j = 0; j < m; j++) {
            C[i][j] = 0;
            for (int k = 0; k < An; k++)
                C[i][j] += A[k][j] * B[i][k];
        }
    }
    return C;
}

CCS_matrix ccs_matrix_transposition(const CCS_matrix& B) {
    CCS_matrix BT;
    BT.col_n = B.row_n;
    BT.row_n = B.col_n;
    std::vector<std::vector<int>> for_row(B.row_n);
    std::vector<std::vector<double>> for_value(B.row_n);
    int itr = 0;
    for (int j = 0; j < B.col_n; ++j) {
        for (int i = itr; i < B.column_pointer[j + 1]; ++i) {
            for_row[B.row[i]].push_back(j);
            for_value[B.row[i]].push_back(B.value[i]);
        }
        itr += B.column_pointer[j + 1] - B.column_pointer[j];
    }
    BT.column_pointer.resize(BT.col_n + 1);
    BT.column_pointer[0] = 0;
    for (int i = 0; i < BT.col_n; ++i) {
        BT.column_pointer[i + 1] = BT.column_pointer[i] + for_value[i].size();
        int n = for_value[i].size();
        for (int j = 0; j < n; ++j) {
            BT.value.push_back(for_value[i][j]);
            BT.row.push_back(for_row[i][j]);
        }
    }
    return BT;
}

CCS_matrix convet_to_ccs(const std::vector<std::vector<double>>& A) {
    if (A.empty()) {
        throw("Empty matrix for transposition");
    }
    CCS_matrix A_ccs;
    A_ccs.row_n = A.size();
    A_ccs.col_n = A[0].size();
    A_ccs.column_pointer.push_back(0);

    for (int i = 0; i < A_ccs.col_n; ++i) {
        for (int j = 0; j < A_ccs.row_n; ++j) {
            if (A[j][i] > 0) {
                A_ccs.value.push_back(A[j][i]);
                A_ccs.row.push_back(j);
            }
        }
        A_ccs.column_pointer.push_back(A_ccs.value.size());
    }
    return A_ccs;
}

CCS_matrix ccs_matrix_multplication(const CCS_matrix& A, const CCS_matrix& B) {
    if (A.row_n != B.col_n) {
        throw("Wrong matrix sizes for multiplication");
    }

    CCS_matrix C;
    // Transpose the matrix B
    CCS_matrix BT(ccs_matrix_transposition(B));

    // Initialization of matrix C
    C.col_n = A.col_n;
    C.row_n = B.row_n;
    C.column_pointer.push_back(0);

    // Multiplication
    for (int i = 0; i < A.col_n; ++i) {
        std::vector<int> x(A.row_n, -1);
        for (int j = A.column_pointer[i]; j < A.column_pointer[i + 1]; ++j) {
            x[A.row[j]] = j;
        }
        for (int k = 0; k < BT.col_n; ++k) {
            double sum = 0;
            for (int j = BT.column_pointer[k];
                j < BT.column_pointer[k + 1]; ++j) {
                if (x[BT.row[j]] > -1) {
                    sum += A.value[x[BT.row[j]]] * BT.value[j];
                }
            }
            if (sum > 0) {
                C.value.push_back(sum);
                C.row.push_back(k);
            }
        }
        C.column_pointer.push_back(C.value.size());
    }
    return C;
}
