// Copyright 2018 Nesterov Alexander
#include <gtest/gtest.h>
#include <vector>
#include "./kulemin_p_discharge_double_sort_omp.h"

TEST(Parallel_Operations_OpenMP, Test_No_Throw) {
    vector* vb;
    vb = create_random_vector(10);
    ASSERT_NO_THROW(discharge_sort(vb));
}

TEST(Parallel_Operations_OpenMP, Test_10) {
    int count = 10;
    vector* vb = create_random_vector(count);
    vector* sd = new vector(count);
    copy_vectors(vb->ptr, sd->ptr, count);
    std::sort(vb->ptr, vb->ptr + count);
    discharge_sort(sd);
    bool res = check_vectors(vb->ptr, sd->ptr, count);
    ASSERT_EQ(true, res);
}


TEST(Parallel_Operations_OpenMP, Test_100) {
    int count = 100;
    vector* vb = create_random_vector(count);
    vector* sd = new vector(count);
    copy_vectors(vb->ptr, sd->ptr, count);
    std::sort(vb->ptr, vb->ptr + count);
    discharge_sort(sd);
    bool res = check_vectors(vb->ptr, sd->ptr, count);
    ASSERT_EQ(true, res);
}
TEST(Parallel_Operations_OpenMP, Test_150) {
    int count = 150;
    vector* vb = create_random_vector(count);
    vector* sd = new vector(count);
    copy_vectors(vb->ptr, sd->ptr, count);
    std::sort(vb->ptr, vb->ptr + count);
    discharge_sort(sd);
    bool res = check_vectors(vb->ptr, sd->ptr, count);
    ASSERT_EQ(true, res);
}
TEST(Parallel_Operations_OpenMP, Test_200) {
    int count = 200;
    vector* vb = create_random_vector(count);
    vector* sd = new vector(count);
    copy_vectors(vb->ptr, sd->ptr, count);
    std::sort(vb->ptr, vb->ptr + count);
    discharge_sort(sd);
    bool res = check_vectors(vb->ptr, sd->ptr, count);
    ASSERT_EQ(true, res);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
