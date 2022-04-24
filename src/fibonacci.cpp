#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n < 1) {
      return 0;

    }
    double root_5 = sqrt(5);
    double phi = ((1 + root_5) / 2);
    double a = ((pow(phi, n)) - (pow(-phi, -n))) / root_5;

    return round(a);
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    for (int i = 0; i < n; ++i) {
      int64_t some_fib = fib_prev;
      fib_prev = fib_curr;
      fib_curr = some_fib + fib_curr;
      
    }

    // Напишите здесь свой код ...

    return fib_prev;
  }

  int64_t fib_recursive(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1 or n == 2) {
      return 1;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] == -1) {
      // Напишите здесь свой код ...
      cache[n] = fib_recursive_memoization(n-1, cache) + fib_recursive_memoization(n-2, cache);
    }

    return cache[n];

  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    // Напишите здесь свой код ...

    // Tip: используйте реализованную функцию matrix_pow
    Matrix2x2 some_matrix;
    some_matrix[0][0] = 1;
    some_matrix[0][1] = 1;
    some_matrix[1][0] = 1;
    some_matrix[1][1] = 0;

    some_matrix = matrix_power(some_matrix, n);
    return some_matrix[0][1];
  }

}  // namespace assignment
