// Copyright 2022 Chornyi Yura
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "./shell_sort.h"

using std::vector;

TEST(Parallel, Shell_Sort_100) {
  vector<int> vec = getRandomVector(100);

  auto result = getParallelShellSort(vec);
  bool isSorted = std::is_sorted(result.begin(), result.end());

  ASSERT_EQ(isSorted, true);
}

TEST(Parallel, Shell_Sort_150) {
  vector<int> vec = getRandomVector(150);

  auto result = getParallelShellSort(vec);
  bool isSorted = std::is_sorted(result.begin(), result.end());

  ASSERT_EQ(isSorted, true);
}

TEST(Parallel, Shell_Sort_200) {
  vector<int> vec = getRandomVector(200);

  auto result = getParallelShellSort(vec);
  bool isSorted = std::is_sorted(result.begin(), result.end());

  ASSERT_EQ(isSorted, true);
}

TEST(Parallel, Shell_Sort_250) {
  vector<int> vec = getRandomVector(250);

  auto result = getParallelShellSort(vec);
  bool isSorted = std::is_sorted(result.begin(), result.end());

  ASSERT_EQ(isSorted, true);
}

TEST(Parallel, Shell_Sort_300) {
  vector<int> vec = getRandomVector(300);

  auto result = getParallelShellSort(vec);
  bool isSorted = std::is_sorted(result.begin(), result.end());

  ASSERT_EQ(isSorted, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
