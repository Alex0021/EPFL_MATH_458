#include <cassert>
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
  double a;

  std::cout << "Enter a non-negative number\n";
  std::cin >> a;
  assert(a >= 0.0);
  std::cout << "The square root of " << a;
  std::cout << " is " << sqrt(a) << "\n";

  return 0;
}