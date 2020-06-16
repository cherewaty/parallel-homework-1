#include <iostream>
#include <omp.h>
#include <cmath>
#include "hw1.h"

double euclidean_length(std::vector<double> vector)
{
  // non-parallel reference at
  // http://polaris.s.kanazawa-u.ac.jp/~npozar/basic-cpp-for-numerics-vectors.html

  double sum = 0.0;
  int i;

#pragma omp parallel for reduction(+ \
                                   : sum)
  for (i = 0; i < vector.size(); ++i)
  {
    // std::cout << "Thread number: " + std::to_string(omp_get_thread_num()) + "\n";
    sum += vector[i] * vector[i];
  }
  return sqrt(sum);
}

std::vector<int64_t> discard_duplicates(std::vector<int64_t> sorted_vector)
{
  std::vector<int64_t> unduplicated = {};
  int i;

#pragma omp parallel for
  for (i = 0; i < sorted_vector.size(); ++i)
  {
    // std::cout << "Thread number: " + std::to_string(omp_get_thread_num()) + "\n";
    if (i == 0 || sorted_vector[i] != sorted_vector[i - 1])
    {
#pragma omp critical
      unduplicated.push_back(sorted_vector[i]);
    }
  }

  return unduplicated;
}
