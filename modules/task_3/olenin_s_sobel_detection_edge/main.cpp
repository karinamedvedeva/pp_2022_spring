// Copyright 2022 Olenin Sergey

#include <tbb/tbb.h>
#include "../../../modules/task_3/olenin_s_sobel_detection_edge/sobel_detection_edge.h"
#include "gtest/gtest.h"
const int SIZE_1 = 10;
const int SIZE_2 = 20;
const int SIZE_3 = 30;
const int SIZE_4 = 40;
const int SIZE_5 = 50;

TEST(TbbSobelFilter, SobelTest1) {
  Image image = Image::GenerateRandomImage(SIZE_1);

  tbb::tick_count startseq = tbb::tick_count::now();
  Image resseq = ApplySobel(image);
  tbb::tick_count endseq = tbb::tick_count::now();
  double timeseq = (endseq - startseq).seconds();

  tbb::tick_count startomp = tbb::tick_count::now();
  Image resomp = ApplySobeltbb(image);
  tbb::tick_count endomp = tbb::tick_count::now();
  double timeomp = (endomp - startomp).seconds();

  std::cout << "sequential_runtime = " << timeseq << std::endl;
  std::cout << "parallel_omp_runtime = " << timeomp
    << std::endl;

  ASSERT_NO_FATAL_FAILURE(ApplySobeltbb(image));
}
TEST(TbbSobelFilter, SobelTest2) {
  Image image = Image::GenerateRandomImage(SIZE_2);

    tbb::tick_count startseq = tbb::tick_count::now();
  Image resseq = ApplySobel(image);
  tbb::tick_count endseq = tbb::tick_count::now();
  double timeseq = (endseq - startseq).seconds();

  tbb::tick_count startomp = tbb::tick_count::now();
  Image resomp = ApplySobeltbb(image);
  tbb::tick_count endomp = tbb::tick_count::now();
  double timeomp = (endomp - startomp).seconds();

  std::cout << "sequential_runtime = " << timeseq << std::endl;
  std::cout << "parallel_omp_runtime = " << timeomp << std::endl;

  ASSERT_NO_FATAL_FAILURE(ApplySobeltbb(image));
}
TEST(TbbSobelFilter, SobelTest3) {
  Image image = Image::GenerateRandomImage(SIZE_3);

  tbb::tick_count startseq = tbb::tick_count::now();
  Image resseq = ApplySobel(image);
  tbb::tick_count endseq = tbb::tick_count::now();
  double timeseq = (endseq - startseq).seconds();

  tbb::tick_count startomp = tbb::tick_count::now();
  Image resomp = ApplySobeltbb(image);
  tbb::tick_count endomp = tbb::tick_count::now();
  double timeomp = (endomp - startomp).seconds();

  std::cout << "sequential_runtime = " << timeseq << std::endl;
  std::cout << "parallel_omp_runtime = " << timeomp << std::endl;

  ASSERT_NO_FATAL_FAILURE(ApplySobeltbb(image));
}
TEST(TbbSobelFilter, SobelTest4) {
  Image image = Image::GenerateRandomImage(SIZE_4);

  tbb::tick_count startseq = tbb::tick_count::now();
  Image resseq = ApplySobel(image);
  tbb::tick_count endseq = tbb::tick_count::now();
  double timeseq = (endseq - startseq).seconds();

  tbb::tick_count startomp = tbb::tick_count::now();
  Image resomp = ApplySobeltbb(image);
  tbb::tick_count endomp = tbb::tick_count::now();
  double timeomp = (endomp - startomp).seconds();

  std::cout << "sequential_runtime = " << timeseq << std::endl;
  std::cout << "parallel_omp_runtime = " << timeomp << std::endl;

  ASSERT_NO_FATAL_FAILURE(ApplySobeltbb(image));
}
TEST(TbbSobelFilter, SobelTest5) {
  Image image = Image::GenerateRandomImage(SIZE_5);
  tbb::tick_count startseq = tbb::tick_count::now();
  Image resseq = ApplySobel(image);
  tbb::tick_count endseq = tbb::tick_count::now();
  double timeseq = (endseq - startseq).seconds();

  tbb::tick_count startomp = tbb::tick_count::now();
  Image resomp = ApplySobeltbb(image);
  tbb::tick_count endomp = tbb::tick_count::now();
  double timeomp = (endomp - startomp).seconds();

  std::cout << "sequential_runtime = " << timeseq << std::endl;
  std::cout << "parallel_omp_runtime = " << timeomp << std::endl;

  ASSERT_NO_FATAL_FAILURE(ApplySobeltbb(image));
}


int main(int argc, char **argv) {
    // auto image = Image::fromFile("C:\\Users\\olenin.s\\Desktop\\sobel.png");
    // show(ApplySobeltbb(image));
    ::testing::InitGoogleTest(&argc, argv);
    tbb::task_scheduler_init init(2);
    return RUN_ALL_TESTS();
}
