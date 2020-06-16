#include <iostream>
#include <math.h>
#include <omp.h>
#include "hw1.h"

double euclidean_length(std::vector<double> vector)
{
  int i = 0;
  int d = 0;
	omp_set_num_threads(vector.size());
	#pragma omp parallel\
	  private(i) default(shared)
	i = omp_get_thread_num();
  	vector[i] = vector[i] * vector[i];
	#pragma omp barrier
	//	#pragma omp single
	for (d = 1; d<vector.size(); d = 2*d){
		omp_set_num_threads(vector.size());
		#pragma omp parallel default(shared) private(i)
		i = omp_get_thread_num();
		if (i>0 && i<(vector.size()-1)){
				if(i-d>0){
					vector[i] = vector[i] + vector[i-d];
				}
			}
		#pragma omp barrier
	}
  	//now we have a sum in the vector[i]
  	
  return sqrt(vector[vector.size()-1]);
}
std::vector<int64_t> discard_duplicates(std::vector<int64_t> sorted_vector)
{
  //in parallel 
  // Your code goes here
  return std::vector<int64_t>();
}
