#include "calculate_minimum.hpp"
#include <iostream>

int main(int argc, char *argv[]) {

  double x = 4.0, y = -8.0;
  double minimum_value = CalculateMinimum(x, y);
  std::cout << "min = " << minimum_value << "\n";

  return 0;
}