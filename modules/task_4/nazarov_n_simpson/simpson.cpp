// Copyright 2022 Nazarov Nikita
#include "../../../modules/task_4/nazarov_n_simpson/simpson.h"

static const int THREADS_NUMBER = 12;
double global_sum[THREADS_NUMBER];

void thread_simpson(double (*func)(const std::vector<double>&),
                    const std::vector<std::pair<double, double>>& borders,
                    const std::vector<int>& steps, const int rank,
                    const int iteration, const int dimensions,
                    const std::vector<double>& h, const int a) {
  std::vector<std::vector<double>> parameters(dimensions,
                                              std::vector<double>(6));
  std::vector<double> argument(dimensions);
  int step = iteration / THREADS_NUMBER;
  int left;
  int right;
  if (rank + 1 == THREADS_NUMBER) {
    left = step * (THREADS_NUMBER - 1);
    right = iteration;
  } else {
    left = rank * step;
    right = step * (rank + 1);
  }
  for (int i = left, x = i; i < right; i++, x = i) {
    for (int dim = 0; dim < dimensions; dim++) {
      parameters[dim][0] = borders[dim].first + (x % steps[dim]) * h[dim];
      parameters[dim][1] =
          borders[dim].first + (x % steps[dim]) * h[dim] + h[dim] / 2;
      parameters[dim][2] = parameters[dim][1];
      parameters[dim][3] = parameters[dim][1];
      parameters[dim][4] = parameters[dim][1];
      parameters[dim][5] = parameters[dim][0] + h[dim];
      x /= steps[dim];
    }
    for (int i = 0, x = i; i < a; i++, x = i) {
      for (int dim = 0; dim < dimensions; dim++) {
        argument[dim] = parameters[dim][x % 6];
        x /= 6;
      }
      global_sum[rank] += func(argument);
    }
  }
  for (int i = 0; i < dimensions; i++) {
    global_sum[rank] *= h[i] / 6.0;
  }
}

double simpson(double (*func)(const std::vector<double>&),
               const std::vector<std::pair<double, double>>& borders,
               const std::vector<int>& steps) {
  int iteration = 1;
  int dimensions = steps.size();
  double integral_simpson = 0;
  std::vector<double> h(dimensions);
  int a = std::pow(6, dimensions);

  for (int i = 0; i < dimensions; i++) {
    h[i] = (borders[i].second - borders[i].first) / steps[i];
    iteration *= steps[i];
  }

  std::thread threads[THREADS_NUMBER];

  for (int rank = 0; rank < THREADS_NUMBER; rank++)
    threads[rank] = std::thread(thread_simpson, func, borders, steps, rank,
                                iteration, dimensions, h, a);

  for (int i = 0; i < THREADS_NUMBER; i++) {
    threads[i].join();
    integral_simpson += global_sum[i];
    global_sum[i] = 0;
  }
  return integral_simpson;
}

// ----------------------------------------------------------------------

double simpson_seq(double (*func)(const std::vector<double>&),
                   const std::vector<std::pair<double, double>>& borders,
                   const std::vector<int>& steps) {
  int iteration = 1;
  int dimensions = steps.size();
  double integral_simpson = 0;
  std::vector<double> h(dimensions);
  int a = std::pow(6, dimensions);
  std::vector<std::vector<double>> parameters(dimensions,
                                              std::vector<double>(6));
  std::vector<double> argument(dimensions);

  for (int i = 0; i < dimensions; i++) {
    h[i] = (borders[i].second - borders[i].first) / steps[i];
    iteration *= steps[i];
  }

  for (int i = 0, x = i; i < iteration; i++, x = i) {
    for (int dim = 0; dim < dimensions; dim++) {
      parameters[dim][0] = borders[dim].first + (x % steps[dim]) * h[dim];
      parameters[dim][1] =
          borders[dim].first + (x % steps[dim]) * h[dim] + h[dim] / 2;
      parameters[dim][2] = parameters[dim][1];
      parameters[dim][3] = parameters[dim][1];
      parameters[dim][4] = parameters[dim][1];
      parameters[dim][5] = parameters[dim][0] + h[dim];
      x /= steps[dim];
    }
    for (int i = 0, x = i; i < a; i++, x = i) {
      for (int dim = 0; dim < dimensions; dim++) {
        argument[dim] = parameters[dim][x % 6];
        x /= 6;
      }
      integral_simpson += func(argument);
    }
  }

  for (int i = 0; i < dimensions; i++) {
    integral_simpson *= h[i] / 6.0;
  }

  return integral_simpson;
}
