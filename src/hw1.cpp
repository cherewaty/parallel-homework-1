#include <iostream>
#include <math.h>
#include <omp.h>
#include "hw1.h"

double euclidean_length(std::vector<double> vector)
{
  int i=0;
  omp_set_num_threads(vector.size());

#pragma omp parallel for\
  private(i)

  for(i = 0; i<vector.size(); i++){
    vector[i] = vector[i]*vector[i];
  }
  #pragma omp barrier

  double sum = 0.0;
  #pragma omp parallel for reduction (+:sum)
  for(int i=0; i<(vector.size()); i++){
      sum = sum + vector[i];
  }
  	
  return sqrt(sum);
}
std::vector<int64_t> discard_duplicates(std::vector<int64_t> sorted_vector)
{
  //in parallel
  int i;
  std::vector<int64_t>B;
  
#pragma omp parallel for ordered  private(i) 
  for (i = 0; i < sorted_vector.size(); i++){
    if(i == 0 || sorted_vector[i] >  sorted_vector[i-1] ){
#pragma omp ordered
      B.push_back(sorted_vector[i]);
    }
  }
  
  if(sorted_vector[sorted_vector.size()-1] != sorted_vector[sorted_vector.size()-1]){
    B.push_back(sorted_vector[sorted_vector.size()-1]);
  }
  // Your code goes here
    //  return std::vector<int64_t>(B);
    return B;
}
