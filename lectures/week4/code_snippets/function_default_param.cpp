#include <iostream>

double doIt(double a, double b = 0.) { return a + b; }

int main() {
  std::cout << doIt(10., 5.) << std::endl;
  std::cout << doIt(10.) << std::endl;
}