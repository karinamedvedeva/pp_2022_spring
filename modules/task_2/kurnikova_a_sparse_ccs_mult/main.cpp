// Copyright 2022 Kurnikova Anastasia
#include <gtest/gtest.h>
#include <omp.h>
#include "./sparse_ccs_mult.h"

TEST(sparse_ccs_mult, test1) {
    ASSERT_NO_THROW(mymat a(4, 4, 4));
}

TEST(sparse_ccs_mult, test2) {
    ASSERT_NO_THROW(mymat a(2, 2, 2));
}

TEST(sparse_ccs_mult, test3) {
    mymat a(1, 1, 0);
    mymat b(1, 1, 0);
    EXPECT_EQ(a, b);
}

TEST(sparse_ccs_mult, test4) {
    mymat a(5, 1, 2);
    ASSERT_NO_THROW(t(&a));
}

TEST(sparse_ccs_mult, test5) {
    mymat a(1, 1, 0);
    mymat b(5, 4, 1);
    bool q = true;
    if (a == b)
        q = true;
    else
        q = false;
    EXPECT_EQ(false, q);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
