// Copyright 2022 Nazarov Nikita
#include "../../../modules/task_3/nazarov_n_simpson/simpson.h"

class SimpsonFunc {
  double (*func)(const std::vector<double>&);
  const std::vector<std::pair<double, double>>& borders;
  const std::vector<int>& steps;
  int const dimensions;
  const std::vector<double>& h;
  int const a;
  double k;
  double integral_simpson;
  std::vector<std::vector<double>> parameters;
  std::vector<double> argument;

 public:
  SimpsonFunc(double (*_func)(const std::vector<double>&),
              const std::vector<std::pair<double, double>>& _borders,
              const std::vector<int>& _steps, const int _dimensions,
              const std::vector<double>& _h, const int _a, double _k)
      : func(_func),
        borders(_borders),
        steps(_steps),
        dimensions(_dimensions),
        h(_h),
        a(_a),
        k(_k),
        integral_simpson(0.0),
        parameters(std::vector<std::vector<double>>(dimensions,
                                                    std::vector<double>(6))),
        argument(std::vector<double>(dimensions)) {}

  void operator()(const tbb::blocked_range<int>& range) {
    for (int i = range.begin(), x = i; i != range.end(); i++, x = i) {
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
        integral_simpson += k * func(argument);
      }
    }
    /*for (int i = 0; i < dimensions; i++) {
      integral_simpson *= h[i] / 6.0;
    }*/
  }

  SimpsonFunc(const SimpsonFunc& simpson, tbb::split)
      : func(simpson.func),
        borders(simpson.borders),
        steps(simpson.steps),
        dimensions(simpson.dimensions),
        h(simpson.h),
        a(simpson.a),
        k(simpson.k),
        integral_simpson(0.0),
        parameters(std::vector<std::vector<double>>(dimensions,
                                                    std::vector<double>(6))),
        argument(std::vector<double>(dimensions)) {}

  void join(const SimpsonFunc& simpson) {
    integral_simpson += simpson.integral_simpson;
    // printf("%lf\n", integral_simpson);
  }
  double Result() { return integral_simpson; }
};

double simpson(double (*func)(const std::vector<double>&),
               const std::vector<std::pair<double, double>>& borders,
               const std::vector<int>& steps, int process) {
  int iteration = 1;
  int dimensions = steps.size();
  int a = std::pow(6, dimensions);
  double k = 1;
  std::vector<double> h(dimensions);
  std::vector<std::vector<double>> parameters(dimensions,
                                              std::vector<double>(6));
  std::vector<double> argument(dimensions);
  for (int i = 0; i < dimensions; i++) {
    h[i] = (borders[i].second - borders[i].first) / steps[i];
    iteration *= steps[i];
    k *= h[i] / 6.0;
  }
  tbb::task_scheduler_init init(process);

  SimpsonFunc simpson(func, borders, steps, dimensions, h, a, k);

  tbb::parallel_reduce(tbb::blocked_range<int>(0, iteration), simpson,
                       tbb::auto_partitioner());

  return simpson.Result();
}
