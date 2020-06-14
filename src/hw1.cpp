#include <iostream>
#include <omp.h>
#include <cmath>
#include "hw1.h"

double euclidean_length(std::vector<double> vector)
{
  // Your code goes here.

  // non-parallel version
  // http://polaris.s.kanazawa-u.ac.jp/~npozar/basic-cpp-for-numerics-vectors.html
  double accum = 0.;
  for (int i = 0; i < vector.size(); ++i)
  {
    accum += vector[i] * vector[i];
  }
  return sqrt(accum);
}

std::vector<int64_t> discard_duplicates(std::vector<int64_t> sorted_vector)
{
  // Your code goes here
  return std::vector<int64_t>();
}
