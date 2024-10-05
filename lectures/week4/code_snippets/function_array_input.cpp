#include <iostream>

double doIt(double array[]) {
  array[1] = 10.;
  return array[1];
}

int main() {
  double u[10];
  std::cout << doIt(u) << std::endl;
  double *u2 = new double[10];
  std::cout << doIt(u2) << std::endl;
}