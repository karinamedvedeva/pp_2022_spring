// Copyright 2022 George Amberson
#ifndef MODULES_TASK_4_KULEMIN_P_DISCHARGE_DOUBLE_SORT_STD_KULEMIN_P_DISCHARGE_DOUBLE_SORT_STD_H_
#define MODULES_TASK_4_KULEMIN_P_DISCHARGE_DOUBLE_SORT_STD_KULEMIN_P_DISCHARGE_DOUBLE_SORT_STD_H_
#include <vector>
#include <list>
struct vector {
    double* ptr;
    int last_el;
    int size;
    vector() {
        ptr = nullptr;
        last_el = 0;
        size = 0;
    }
    explicit vector(int _size) {
        ptr = new double[_size];
        size = _size;
        last_el = 0;
    }
    vector(const vector& in) {
        this->ptr = new double[in.size];
        this->size = in.size;
        this->last_el = in.last_el;
        for (int i = 0; i < in.size; i++)this->ptr[i] = in.ptr[i];
    }
    ~vector() {
        delete[] ptr;
    }
    vector& operator= (const vector& in) {
        if (this != &in) {
            this->ptr = new double[in.size];
            this->size = in.size;
            this->last_el = in.last_el;
            for (int i = 0; i < in.size; i++)this->ptr[i] = in.ptr[i];
        }
        return (*this);
    }
};
vector* create_random_vector(int size_n);
void union_from_lists(std::list<double>* lists, vector* v);
void discharge_sort(vector* v);
bool check_vectors(double* st, double* sd, int size);
void copy_vectors(double* st, double* sd, int size);
#endif  // MODULES_TASK_4_KULEMIN_P_DISCHARGE_DOUBLE_SORT_STD_KULEMIN_P_DISCHARGE_DOUBLE_SORT_STD_H_
