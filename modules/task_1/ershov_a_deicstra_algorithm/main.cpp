// Copyright 2022 Ershov Aleksey
#include <gtest/gtest.h>

#include <vector>

#include "./deicstra_seq.h"

TEST(Sequential_Deicstra, Test_Sequential_Deicstra_With_Static_Data_Any_Throw) {
  const std::vector<std::vector<int>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};

  ASSERT_NO_THROW(getSequentialDeicstra(graf, 0));
}

TEST(Sequential_Deicstra, Test_Sequential_Deicstra_With_Static_Data_No_Throw) {
  const std::vector<std::vector<int>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const int count = graf.size();

  ASSERT_NO_THROW(getSequentialDeicstra(graf, count - 1));
}

TEST(Sequential_Deicstra, Test_Sequential_Deicstra_With_Static_Data_First_Top) {
  const std::vector<std::vector<int>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const std::vector<int> trueResult = {0, 7, 9, 20, 20, 11};
  bool check = true;
  const size_t count = graf.size();

  const std::vector<int> algorithmResult = getSequentialDeicstra(graf, 0);
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Sequential_Deicstra, Test_Sequential_Deicstra_With_Static_Data_Last_Top) {
  const std::vector<std::vector<int>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const std::vector<int> trueResult = {11, 12, 2, 13, 9, 0};
  bool check = true;
  const size_t count = graf.size();

  const std::vector<int> algorithmResult =
      getSequentialDeicstra(graf, count - 1);
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Sequential_Deicstra, Test_Sequential_Deicstra_Top_Two_Times_Static) {
  const std::vector<std::vector<int>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  bool check = true;
  const size_t count = graf.size();

  const std::vector<int> algorithmResultFirst =
      getSequentialDeicstra(graf, count - 1);

  const std::vector<int> algorithmResultSecond =
      getSequentialDeicstra(graf, count - 1);

  for (size_t i = 0; i < count; ++i) {
    if (algorithmResultFirst[i] != algorithmResultSecond[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Sequential_Deicstra, Test_Sequential_Deicstra_Top_Two_Times_Random) {
  const std::vector<std::vector<int>> graf = getRandomVector(10);
  bool check = true;
  const size_t count = graf.size();

  const std::vector<int> algorithmResultFirst =
      getSequentialDeicstra(graf, count - 1);

  const std::vector<int> algorithmResultSecond =
      getSequentialDeicstra(graf, count - 1);

  for (size_t i = 0; i < count; ++i) {
    if (algorithmResultFirst[i] != algorithmResultSecond[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}
