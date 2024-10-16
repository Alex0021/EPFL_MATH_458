#include <iostream>
#include <tuple>

std::tuple<int, int, double> foo() {
  // return a tuple with 3 entries
  return std::make_tuple(2, 3, 3.14);
}

int main() {
  std::tuple<int, int, double> p = foo();
  // fetching the integers
  int a = std::get<0>(p);
  int b = std::get<1>(p);
  double c = std::get<2>(p);
}