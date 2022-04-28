// Copyright 2022 Olenin Sergey

#ifndef MODULES_TASK_2_OLENIN_S_SOBEL_DETECTION_EDGE_SOBEL_DETECTION_EDGE_H_
#define MODULES_TASK_2_OLENIN_S_SOBEL_DETECTION_EDGE_SOBEL_DETECTION_EDGE_H_
#include <random>
#include <vector>

/*
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
*/



struct Image {
 private:
  char* data;
  int size;

 public:
  explicit Image(int size) {
    this->size = size;
    this->data = new char[this->size * this->size];
    for (int i = 0; i < this->size * this->size; i++) {
      this->data[i] = 0;
    }
  }
  /*
    static Image fromFile(const char* path) {
    cv::Mat img = cv::imread(path, cv::IMREAD_GRAYSCALE);
    Image image(img.size[0]);
    cv::Mat buffer = cv::Mat();
    img.convertTo(buffer, CV_8U, 1, 0);

    for (int x = 1; x < img.size[0]; ++x) {
      for (int y = 1; y < img.size[0]; ++y) {
        char pixel = buffer.at<unsigned char>(y, x);
        image.Set(x, y, pixel);
      }
    }
    return image;
  }
  */


  char Get(int x, int y) { return this->data[x * this->size + y]; }
  void Set(int x, int y, const char& value) {
    this->data[x * this->size + y] = value;
  }
  Image(const Image& img) {
    this->size = img.size;
    this->data = new char[img.size * img.size];
    for (int i = 0; i < img.size * img.size; i++) {
      this->data[i] = img.data[i];
    }
  }
  Image operator=(const Image& img) {
    this->size = img.size;
    this->data = new char[img.size * img.size];
    for (int i = 0; i < img.size * img.size; i++) {
      this->data[i] = img.data[i];
    }
    return *this;
  }
  ~Image() {
    if (this->data) {
      delete[] this->data;
    }
  }

  int GetSize() { return this->size; }

  static Image GenerateRandomImage(int size) {
    Image img(size);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 255);

    for (int i = 0; i < size * size; ++i) {
      img.data[i] = dist(rng);
    }
    return img;
  }
};
Image ApplySobel(Image img);
Image ApplySobelomp(Image img);
// void show(Image image);

#endif  //  MODULES_TASK_2_OLENIN_S_SOBEL_DETECTION_EDGE_SOBEL_DETECTION_EDGE_H_
