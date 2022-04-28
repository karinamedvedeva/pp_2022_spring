    // Copyright 2018 Nesterov Alexander
#include <gtest/gtest.h>
#include <vector>
#include "./kulemin_p_discharge_double_sort_tbb.h"

TEST(Parallel_Operations_OpenMP, Test_90000) {
    int count = 90000;
    vector* vb = create_random_vector(count);
    vector* sd = new vector(count);
    vector* tr = new vector(count);
    copy_vectors(vb->ptr, sd->ptr, count);
    discharge_sort_seq(vb);
    discharge_sort(sd, tr);
    bool res = check_vectors(vb->ptr, sd->ptr, count);
    ASSERT_EQ(true, res);
}

TEST(Parallel_Operations_OpenMP, Test_100000) {
    int count = 100000;
    vector* vb = create_random_vector(count);
    vector* sd = new vector(count);
    vector* tr = new vector(count);
    copy_vectors(vb->ptr, sd->ptr, count);
    discharge_sort_seq(vb);
    discharge_sort(sd, tr);
    bool res = check_vectors(vb->ptr, sd->ptr, count);
    ASSERT_EQ(true, res);
}

TEST(Parallel_Operations_OpenMP, Test_150000) {
    int count = 12000;
    vector* vb = create_random_vector(count);
    vector* sd = new vector(count);
    vector* tr = new vector(count);
    copy_vectors(vb->ptr, sd->ptr, count);
    discharge_sort_seq(vb);
    discharge_sort(sd, tr);
    bool res = check_vectors(vb->ptr, sd->ptr, count);
    ASSERT_EQ(true, res);
}
TEST(Parallel_Operations_OpenMP, Test_200000) {
    int count = 14000;
    vector* vb = create_random_vector(count);
    vector* sd = new vector(count);
    vector* tr = new vector(count);
    copy_vectors(vb->ptr, sd->ptr, count);
    discharge_sort_seq(vb);
    discharge_sort(sd, tr);
    bool res = check_vectors(vb->ptr, sd->ptr, count);
    ASSERT_EQ(true, res);
}
TEST(Parallel_Operations_OpenMP, Test_400000) {
    int count = 16000;
    vector* vb = create_random_vector(count);
    vector* sd = new vector(count);
    vector* tr = new vector(count);
    copy_vectors(vb->ptr, sd->ptr, count);
    discharge_sort_seq(vb);
    discharge_sort(sd, tr);
    bool res = check_vectors(vb->ptr, sd->ptr, count);
    ASSERT_EQ(true, res);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
