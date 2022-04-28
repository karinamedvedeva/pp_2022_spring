// Copyright 2022 Chornyi Yura
#include "../../../modules/task_3/chornyi_y_shell_sort_with_bather/shell_sort.h"

#include <tbb/tbb.h>

#include <random>
#include <vector>
#include <iostream>

using std::vector;
typedef vector<int>::size_type vec_size_t;

vector<int> getRandomVector(const vec_size_t size) {
  std::random_device dev;
  std::mt19937 gen(dev());
  vector<int> resultVector(size);

  for (vec_size_t i = 0; i < size; ++i) {
    resultVector[i] = gen() % 100;
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

vector<int> getParallelShellSort(const vector<int>& commonVector) {
  vector<vector<int>> vecOfVec;

  tbb::mutex pushMutex;
  tbb::parallel_for(tbb::blocked_range<vector<int>::const_iterator>(
                        commonVector.begin(), commonVector.end(), 10),
                    [&](tbb::blocked_range<vector<int>::const_iterator> r) {
                      vector<int> local = {r.begin(), r.end()};
                      getSequantialShellSort(&local);

                      pushMutex.lock();
                      vecOfVec.push_back(std::move(local));
                      pushMutex.unlock();
                    });

  vector<int> resultVector = vecOfVec[0];
  for (vec_size_t i = 1; i < vecOfVec.size(); ++i) {
    resultVector = merge(resultVector, vecOfVec[i]);
  }

  return resultVector;
}
