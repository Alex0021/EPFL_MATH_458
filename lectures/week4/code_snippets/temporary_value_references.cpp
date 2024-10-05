#include <iostream>

void print(double &a) { std::cout << a; }

int main() {
  double a = 10;
  print(a);
  print(100);
}