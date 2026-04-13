#ifndef CHAPTER6_
#define CHAPTER6_
#include <iostream>

namespace chapter6
{
    void hello_world();
    int iterative_array_sum(const int a[], int n);
    int recursive_array_sum(const int a[], int n);
    int gauss_array_sum(const int a[], int n);
    int recursive_array_sum_positive(const int a[], int n);
    bool parity_is_odd_iterative(const bool b[], unsigned int n);
    bool parity_is_odd_recursive(const bool b[], unsigned int n);
    int count_integer_iterative(const int integers[], int length, int target);
    int count_integer_recursive(const int integers[], int length, int target);
}

#endif