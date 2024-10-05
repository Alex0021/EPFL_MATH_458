#include <cassert>
#include <iostream>

double &getValue(double *A, int ncols, int nrows, //
                 int i, int j) {
  assert(i < nrows);
  assert(j < ncols);
  return A[i * ncols + j];
}

void foo_ref(const double &ref) {
  std::cout << ref;
  // ref = 2; // can do ?
}
void foo_val(double val) {
  std::cout << val;
  // val = 2; // can do ?
}

void foo_ptr(const double *ptr) {
  std::cout << ptr;
  // *ptr = 2; // can do ?
}

int main() {

  int ncols = 10, nrows = 10;
  double A[ncols * nrows];
  getValue(A, ncols, nrows, 2, 2) = 10;
}