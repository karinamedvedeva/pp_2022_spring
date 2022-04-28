// Copyright 2022 Olenin Sergey
#include <tbb/tbb.h>
#include <ctime>
#include <random>
#include <vector>

#include "../../../modules/task_3/olenin_s_sobel_detection_edge/sobel_detection_edge.h"
const char SOBEL_KERNEL_X[] = {1, 0, -1, 2, 0, -2, 1, 0, -1};
const char SOBEL_KERNEL_Y[] = {1, 2, 1, 0, 0, 0, -1, -2, -1};

Image ApplySobel(Image img) {
  Image result(img.GetSize());

  for (int x = 1; x < img.GetSize() - 1; ++x) {
    for (int y = 1; y < img.GetSize() - 1; ++y) {
      int rX = 0, rY = 0;
      int kernelIndex = 0;
      for (int kx = -1; kx <= 1; kx++)
        for (int ky = -1; ky <= 1; ky++) {
          rX += SOBEL_KERNEL_X[kernelIndex] * img.Get(x + kx, y + ky);
          rY += SOBEL_KERNEL_Y[kernelIndex] * img.Get(x + kx, y + ky);
          ++kernelIndex;
        }
      int value = static_cast<int>(sqrt(rX * rX + rY * rY));
      char real = static_cast<char>(value > 255 ? 255 : value);
      result.Set(x, y, real);
    }
  }
  return result;
}
Image ApplySobeltbb(Image img) {
  Image result(img.GetSize());

  tbb::parallel_for(tbb::blocked_range<int>(1, img.GetSize() - 1),
                    [&](const tbb::blocked_range<int>& range) {
          for (int x = range.begin(); x < range.end(); ++x) {
          for (int y = 1; y < img.GetSize() - 1; ++y) {
            int rX = 0, rY = 0;
            int kernelIndex = 0;
            for (int kx = -1; kx <= 1; kx++)
              for (int ky = -1; ky <= 1; ky++) {
                rX += SOBEL_KERNEL_X[kernelIndex] * img.Get(x + kx, y + ky);
                rY += SOBEL_KERNEL_Y[kernelIndex] * img.Get(x + kx, y + ky);
                ++kernelIndex;
              }
            int value = static_cast<int>(sqrt(rX * rX + rY * rY));
            char real = static_cast<char>(value > 255 ? 255 : value);
            result.Set(x, y, real);
          }
                      }
    });

  /*
  for (int x = 1; x < img.GetSize() - 1; ++x) {
    for (int y = 1; y < img.GetSize() - 1; ++y) {
      int rX = 0, rY = 0;
      int kernelIndex = 0;
      for (int kx = -1; kx <= 1; kx++)
        for (int ky = -1; ky <= 1; ky++) {
          rX += SOBEL_KERNEL_X[kernelIndex] * img.Get(x + kx, y + ky);
          rY += SOBEL_KERNEL_Y[kernelIndex] * img.Get(x + kx, y + ky);
          ++kernelIndex;
        }
      int value = static_cast<int>(sqrt(rX * rX + rY * rY));
      char real = static_cast<char>(value > 255 ? 255 : value);
      result.Set(x, y, real);
    }
  }
  */
  return result;
}
/*
void show(Image image) {
  cv::Mat img = cv::Mat(image.GetSize(), image.GetSize(), CV_8U);

  for (int x = 0; x < image.GetSize(); x++) {
    for (int y = 0; y < image.GetSize(); y++) {
      unsigned char& color = img.at<unsigned char>(y, x);
        color = image.Get(x, y);
    }
  }
  cv::imshow("Display window", img);

  cv::waitKey();
}
*/


