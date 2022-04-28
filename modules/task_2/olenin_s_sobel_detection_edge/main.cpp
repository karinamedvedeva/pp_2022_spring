// Copyright 2022 Olenin Sergey


#include <omp.h>
#include "../../../modules/task_2/olenin_s_sobel_detection_edge/sobel_detection_edge.h"
#include "gtest/gtest.h"
const int SIZE_1 = 2;
const int SIZE_2 = 3;
const int SIZE_3 = 4;
const int SIZE_4 = 5;
const int SIZE_5 = 6;

TEST(seqSobelFilter, SobelTest1) {
  Image image = Image::GenerateRandomImage(SIZE_1);
  /*
  double startseq = omp_get_wtime();
  Image resseq = ApplySobel(image);
  double endseq = omp_get_wtime();
  double timeseq = endseq - startseq;

  double startomp = omp_get_wtime();
  Image resomp = ApplySobelomp(image);
  double endomp = omp_get_wtime();
  double timeomp = endomp - startomp;

  std::cout << "sequential_runtime = " << timeseq << std::endl;
  std::cout << "parallel_omp_runtime = " << timeomp
    << std::endl;
  */
  ASSERT_NO_FATAL_FAILURE(ApplySobelomp(image));
}
TEST(seqSobelFilter, SobelTest2) {
  Image image = Image::GenerateRandomImage(SIZE_2);
  /*
  double startseq = omp_get_wtime();
  Image resseq = ApplySobel(image);
  double endseq = omp_get_wtime();
  double timeseq = endseq - startseq;

  double startomp = omp_get_wtime();
  Image resomp = ApplySobelomp(image);
  double endomp = omp_get_wtime();
  double timeomp = endomp - startomp;

  std::cout << "sequential_runtime = " << timeseq << std::endl;
  std::cout << "parallel_omp_runtime = " << timeomp
    << std::endl;
  */

  ASSERT_NO_FATAL_FAILURE(ApplySobelomp(image));
}
TEST(seqSobelFilter, SobelTest3) {
  Image image = Image::GenerateRandomImage(SIZE_3);
  /*
 double startseq = omp_get_wtime();
 Image resseq = ApplySobel(image);
 double endseq = omp_get_wtime();
 double timeseq = endseq - startseq;

 double startomp = omp_get_wtime();
 Image resomp = ApplySobelomp(image);
 double endomp = omp_get_wtime();
 double timeomp = endomp - startomp;

 std::cout << "sequential_runtime = " << timeseq << std::endl;
 std::cout << "parallel_omp_runtime = " << timeomp
   << std::endl;
 */

  ASSERT_NO_FATAL_FAILURE(ApplySobelomp(image));
}
TEST(seqSobelFilter, SobelTest4) {
  Image image = Image::GenerateRandomImage(SIZE_4);
  /*
  double startseq = omp_get_wtime();
  Image resseq = ApplySobel(image);
  double endseq = omp_get_wtime();
  double timeseq = endseq - startseq;

  double startomp = omp_get_wtime();
  Image resomp = ApplySobelomp(image);
  double endomp = omp_get_wtime();
  double timeomp = endomp - startomp;

  std::cout << "sequential_runtime = " << timeseq << std::endl;
  std::cout << "parallel_omp_runtime = " << timeomp
    << std::endl;
  */

  ASSERT_NO_FATAL_FAILURE(ApplySobelomp(image));
}
TEST(seqSobelFilter, SobelTest5) {
  Image image = Image::GenerateRandomImage(SIZE_5);
  /*
  double startseq = omp_get_wtime();
  Image resseq = ApplySobel(image);
  double endseq = omp_get_wtime();
  double timeseq = endseq - startseq;

  double startomp = omp_get_wtime();
  Image resomp = ApplySobelomp(image);
  double endomp = omp_get_wtime();
  double timeomp = endomp - startomp;

  std::cout << "sequential_runtime = " << timeseq << std::endl;
  std::cout << "parallel_omp_runtime = " << timeomp
    << std::endl;
  */

  ASSERT_NO_FATAL_FAILURE(ApplySobelomp(image));
}


int main(int argc, char **argv) {
    // auto image = Image::fromFile("C:\\Users\\HOME\\Desktop\\sobel.png");
    // show(ApplySobelomp(image));
    ::testing::InitGoogleTest(&argc, argv);
    omp_set_num_threads(2);
    return RUN_ALL_TESTS();
}
