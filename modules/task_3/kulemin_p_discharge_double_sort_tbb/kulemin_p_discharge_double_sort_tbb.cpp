// Copyright 2018 Nesterov Alexander
#include <vector>
#include <string>
#include <random>
#include <functional>
#include <numeric>
#include <iostream>
#include "../../../modules/task_3/kulemin_p_discharge_double_sort_tbb/kulemin_p_discharge_double_sort_tbb.h"

vector* create_random_vector(int size_n) {
    std::random_device dev;
    std::mt19937 gen(dev());
    vector* in = new vector(size_n);
    for (int i = 0; i < size_n; ++i) {
        in->ptr[i] = static_cast<double>(gen()) / gen();
    }
    return in;
}
struct DischargeSort {
    vector* arr;
    std::vector<int>* list;
    size_t byte;
    static tbb::mutex m;
    explicit DischargeSort(vector* ta, size_t _b,
    std::vector<int>* _list): arr(ta), list(_list) {
        byte = _b;
    }
    DischargeSort(const DischargeSort&s,
    tbb::split) : arr(s.arr), list(s.list) {
        byte = s.byte;
    }
    void operator()(const tbb::blocked_range<int>& r)const {
        int end = r.end();
        int begin = r.begin();
        for (int i = begin; i < end; i++) {
            unsigned char* pt = (unsigned char*)(arr->ptr + i);
            tbb::mutex::scoped_lock lock;
            lock.acquire(m);
            (*list)[*(pt + byte)]++;
            lock.release();
        }
    }
};
tbb::mutex DischargeSort::m;
void union_from_lists_par(std::vector<int> *list,
vector* v, vector* res, size_t byte) {
    for (int i = 0; i < v->size; i++) {
        unsigned char* pt = (unsigned char*)(v->ptr + i);
        res->ptr[(*list)[*(pt + byte)]] = v->ptr[i];
        (*list)[*(pt + byte)]++;
    }
    double* p = v->ptr;
    v->ptr = res->ptr;
    res->ptr = p;
}
void discharge_sort(vector* v, vector* res) {
    std::vector<int>list(256, 0);
    for (size_t j = 0; j < sizeof(double); j++) {
        v->last_el = 0;
        DischargeSort s(v, j, &list);
        tbb::parallel_for(tbb::blocked_range<int>(0, v->size, v->size / 4), s);
        int count = 0;
        for (int k = 0; k < 256; k++) {
            int tmp = list[k];
            list[k] = count;
            count += tmp;
        }
        union_from_lists_par(&list, v, res, j);
        tbb::parallel_for(tbb::blocked_range<int>(0, list.size()),
        [&list](const tbb::blocked_range<int>& r) {
            int end = r.end();
            int begin = r.begin();
            for (int i = begin; i < end; i++) {
                list[i] = 0;
            }
        });
    }
}

void union_from_lists_seq(std::vector<std::list<double>> *lists, double* in) {
    int j = 0;
    for (size_t i = 0; i < (*lists).size(); i++) {
        while (!(*lists)[i].empty()) {
            in[j] = ((*lists)[i].front());
            (*lists)[i].pop_front();
            j++;
        }
    }
}
void discharge_sort_seq(vector* in) {
    std::vector<std::list<double >> lists(256);
    for (size_t j = 0; j < sizeof(double); j++) {
        for (int i = 0; i < in->size; i++) {
            unsigned char* pt = (unsigned char*)(in->ptr + i);
            lists[*(pt + j)].push_back(in->ptr[i]);
        }
        union_from_lists_seq(&lists, in->ptr);
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
