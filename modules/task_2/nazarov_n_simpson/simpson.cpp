// Copyright 2022 Nazarov Nikita
#include "../../../modules/task_2/nazarov_n_simpson/simpson.h"

int x;
#pragma omp threadprivate(x)

double simpson(double (*func)(const std::vector<double>&),
               const std::vector<std::pair<double, double>>& borders,
               const std::vector<int>& steps) {
  int iteration = 1;
  int dimensions = steps.size();
  double integral_simpson = 0;
  std::vector<double> h(dimensions);
  int i;
  int a = pow(6, dimensions);
  int j;
  for (int i = 0; i < dimensions; i++) {
    h[i] = (borders[i].second - borders[i].first) / steps[i];
    iteration *= steps[i];
  }

  std::vector<std::vector<double>> parameters(dimensions,
                                              std::vector<double>(6));
  std::vector<double> argument(dimensions);
  // omp_set_num_threads(12);

#pragma omp parallel shared(dimensions, iteration, h, borders, steps, a) private(i, j) \
  firstprivate(parameters, argument) reduction(+ : integral_simpson)  // num_threads(12)
#pragma omp for schedule(dynamic)
  for (i = 0; i < iteration; i++) {
    x = i;
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

    for (j = 0; j < a; j++) {
      x = j;
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
