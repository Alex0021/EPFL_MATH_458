#include <iostream>

void print(const double &a) { std::cout << a; }

void print2(double &&a) { std::cout << a; }

int main() {
  print(100);
  print2(100);

  // right reference combined with auto
  auto &&a = 100; // resolves as int a = 100;
  auto &&b = a;   // resolves as int &b = a;
}