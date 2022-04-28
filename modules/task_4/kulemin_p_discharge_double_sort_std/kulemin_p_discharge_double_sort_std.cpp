// Copyright 2018 Nesterov Alexander
#include <vector>
#include <string>
#include <utility>
#include <random>
#include <iostream>
#include <algorithm>
#include "../../modules/task_4/kulemin_p_discharge_double_sort_std/kulemin_p_discharge_double_sort_std.h"
#include "../../../3rdparty/unapproved/unapproved.h"

vector* create_random_vector(int size_n) {
    std::random_device dev;
    std::mt19937 gen(dev());
    vector* in = new vector(size_n);
    for (int i = 0; i < size_n; ++i) {
        in->ptr[i] = static_cast<double>(gen()) / gen();
    }
    return in;
}
void discharge(vector* v, std::vector<std::list<double>>* list,
int begin, int end, size_t byte) {
    for (int i = begin; i < end; i++) {
        unsigned char* pt = (unsigned char*)(v->ptr + i);
        (*list)[*(pt + byte)].push_back(v->ptr[i]);
    }
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
    const int nthreads = std::thread::hardware_concurrency();
    std::thread* threads = new std::thread[nthreads];
    const int delta = (v->size / nthreads) + 1;
    std::vector<std::list<double>>* lists =
    new std::vector<std::list<double>>[nthreads];
    for (int i = 0; i < nthreads; i++)lists[i].resize(256);
    for (size_t j = 0; j < sizeof(double); j++) {
        v->last_el = 0;
        for (int i = 0; i < nthreads; i++) {
            threads[i] = std::thread(discharge, v, &(lists[i]),
            i*delta, std::min((i + 1)*delta, v->size), j);
            threads[i].join();
        }
        for (int t = 0; t < 256; t++) {
            for (int k = 0; k < nthreads; k++) {
                union_from_lists(&lists[k][t], v);
            }
        }
        v->last_el = 0;
    }
    delete[] lists;
    delete[] threads;
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
