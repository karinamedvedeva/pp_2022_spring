// Copyright 2022 Chornyi Yura
#include "../../../modules/task_4/chornyi_y_shell_sort_with_betcher/shell_sort.h"

#include <random>
#include <vector>

#include "../../../3rdparty/unapproved/unapproved.h"

using std::vector;
typedef vector<int>::size_type vec_size_t;

vector<int> getRandomVector(const vec_size_t size) {
  std::random_device dev;
  std::mt19937 gen(dev());
  vector<int> resultVector(size);

  for (vec_size_t i = 0; i < size; ++i) {
    resultVector[i] = gen() % 10000;
  }

  return resultVector;
}

vector<int> sedgwickOrder(const vec_size_t sizeOfVector) {
  vector<int> result;
  int firstCommonMultiple = 1, secondEvenMultiple = 1, secondOddMultiple = 1;
  int counter = 0;

  do {
    if (counter++ % 2 == 0) {
      result.push_back(9 * firstCommonMultiple - 9 * secondEvenMultiple + 1);
      secondEvenMultiple *= 2;
    } else {
      secondOddMultiple *= 2;
      result.push_back(8 * firstCommonMultiple - 6 * secondOddMultiple + 1);
    }
    firstCommonMultiple *= 2;
  } while (static_cast<vec_size_t>(3 * result[result.size() - 1]) <
           sizeOfVector);

  return result;
}

vector<int> merge(const vector<int>& firstVector,
                  const vector<int>& secondVector) {
  vector<int> resultVector(firstVector.size() + secondVector.size());

  size_t firstIt, secondIt, resutIt;
  firstIt = secondIt = resutIt = 0;

  while (firstIt < firstVector.size() && secondIt < secondVector.size()) {
    if (firstVector[firstIt] < secondVector[secondIt]) {
      resultVector[resutIt++] = firstVector[firstIt++];
    } else {
      resultVector[resutIt++] = secondVector[secondIt++];
    }
  }

  while (firstIt < firstVector.size()) {
    resultVector[resutIt++] = firstVector[firstIt++];
  }
  while (secondIt < secondVector.size()) {
    resultVector[resutIt++] = secondVector[secondIt++];
  }

  return resultVector;
}

void getSequantialShellSort(vector<int>* commonVector) {
  vector<int> vectorOfGap = sedgwickOrder(commonVector->size());

  for (int counter = vectorOfGap.size() - 1; counter >= 0; --counter) {
    size_t currentGap = vectorOfGap[counter];

    for (vec_size_t i = currentGap; i < commonVector->size(); ++i) {
      for (int j = i - currentGap;
           (j >= 0) && (commonVector->at(j) > commonVector->at(j + currentGap));
           j -= currentGap) {
        std::swap(commonVector->at(j), commonVector->at(j + currentGap));
      }
    }
  }
}

void threadShellSort(vector<int>* commonVector,
                     std::promise<vector<int>>&& pr) {
  getSequantialShellSort(commonVector);
  pr.set_value(std::move(*commonVector));
}

vector<int> getParallelShellSort(const vector<int>& commonVector) {
  int numberOfThread = std::thread::hardware_concurrency();
  int dataPortion = commonVector.size() / numberOfThread;

  vector<vector<int>> vecOfVec(numberOfThread);

  std::promise<vector<int>>* promises =
      new std::promise<vector<int>>[numberOfThread];
  std::future<vector<int>>* futures =
      new std::future<vector<int>>[numberOfThread];
  std::thread* threads = new std::thread[numberOfThread];

  for (int i = 0; i < numberOfThread; ++i) {
    futures[i] = promises[i].get_future();
    vector<int> local;

    if (i != numberOfThread - 1) {
      local = {commonVector.begin() + i * dataPortion,
               commonVector.begin() + (i + 1) * dataPortion};
    } else {
      local = {commonVector.begin() + i * dataPortion, commonVector.end()};
    }

    threads[i] = std::thread(threadShellSort, &local, std::move(promises[i]));
    threads[i].join();
    vecOfVec[i] = futures[i].get();
  }

  vector<int> resultVector = vecOfVec[0];
  for (int i = 1; i < numberOfThread; ++i) {
    resultVector = merge(resultVector, vecOfVec[i]);
  }

  delete[] promises;
  delete[] futures;
  delete[] threads;

  return resultVector;
}
