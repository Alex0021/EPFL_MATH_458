#include <iostream>
#include <tuple>

std::tuple<int, int, double> foo() {
  // return a tuple with 3 entries
  return std::make_tuple(2, 3, 3.14);
}

int main() {
  // magical auto keyword
  auto [a, b, c] = foo();
}