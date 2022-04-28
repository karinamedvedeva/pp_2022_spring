// Copyright 2018 Nesterov Alexander
#include <omp.h>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <list>
#include "../../task_2/kulemin_p_discharge_double_sort_omp/kulemin_p_discharge_double_sort_omp.h"

vector* create_random_vector(int size_n) {
    std::random_device dev;
    std::mt19937 gen(dev());
    vector* in = new vector(size_n);
    for (int i = 0; i < size_n; ++i) {
        in->ptr[i] = static_cast<double>(gen()) / gen();
    }
    return in;
}
void union_from_lists(std::list<double> *lists, vector* v) {
    int j = v->last_el;
    while (!lists->empty()) {
        v->ptr[j] = ((*lists).front());
        (*lists).pop_front();
        j++;
    }
    v->last_el = j;
}

void discharge_sort(vector* v) {
    std::vector< std::vector<std::list<double >>> lists(omp_get_max_threads());
    for (size_t j = 0; j < sizeof(double); j++) {
        #pragma omp parallel
        {
            lists[omp_get_thread_num()].resize(256);
            #pragma omp for
            for (int i = 0; i < v->size; i++) {
                unsigned char* pt = (unsigned char*)(v->ptr + i);
                lists[omp_get_thread_num()][*(pt + j)].push_back(v->ptr[i]);
            }
            #pragma omp single
            {
                for (int t = 0; t < 256; t++) {
                    for (int k = 0; k < omp_get_num_threads(); k++) {
                        union_from_lists(&lists[k][t], v);
                    }
                }
                v->last_el = 0;
            }
        }
    }
}

bool check_vectors(double* st, double* sd, int size) {
    bool res = true;
    for (int i = 0; i < size; i++) {
        if (st[i] != sd[i]) {
            res = false;
            break;
        }
    }
    return res;
}
void copy_vectors(double* st, double* sd, int size) {
    for (int i = 0; i < size; i++) {
        sd[i] = st[i];
    }
}
