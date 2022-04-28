// Copyright 2022 Olenin Sergey

#include <iostream>
#include "../../../modules/task_1/olenin_s_sobel_detection_edge/sobel_detection_edge.h"
#include "gtest/gtest.h"
const int SIZE_1 = 20;
const int SIZE_2 = 50;
const int SIZE_3 = 60;
const int SIZE_4 = 80;
const int SIZE_5 = 100;

TEST(seqSobelFilter, SobelTest1) {
  Image image = Image::GenerateRandomImage(SIZE_1);
  ASSERT_NO_FATAL_FAILURE(ApplySobel(image));
}
TEST(seqSobelFilter, SobelTest2) {
  Image image = Image::GenerateRandomImage(SIZE_2);
  ASSERT_NO_FATAL_FAILURE(ApplySobel(image));
}
TEST(seqSobelFilter, SobelTest3) {
  Image image = Image::GenerateRandomImage(SIZE_3);
  ASSERT_NO_FATAL_FAILURE(ApplySobel(image));
}
TEST(seqSobelFilter, SobelTest4) {
  Image image = Image::GenerateRandomImage(SIZE_4);
  ASSERT_NO_FATAL_FAILURE(ApplySobel(image));
}
TEST(seqSobelFilter, SobelTest5) {
  Image image = Image::GenerateRandomImage(SIZE_5);
  ASSERT_NO_FATAL_FAILURE(ApplySobel(image));
}


int main(int argc, char **argv) {
    // auto image = Image::fromFile("C:\\Users\\HOME\\Desktop\\sobel.png");
    // show(ApplySobel(image));
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
