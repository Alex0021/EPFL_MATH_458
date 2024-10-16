#include <iostream>
#include <utility>

std::pair<int, int> foo() {
  // return two integers together
  return std::make_pair(2, 3);
}

int main() {
  std::pair<int, int> p = foo();
  // fetching the integers
  int a = std::get<0>(p);
  int b = std::get<1>(p);
}