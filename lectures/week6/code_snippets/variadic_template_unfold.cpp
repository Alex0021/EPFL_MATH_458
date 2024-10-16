#include <iostream>

template <typename T, typename... Args> // variadic
T adder(T first, Args... args) {
  T ret = first;
  ((ret += args), ...);
  return ret;
}

int main() {
  std::cout << adder(1, 2, 3, 4);
  std::cout << adder(1., 2, 3., 4);
  std::cout << adder(std::string("a"), std::string("b"));
  std::cout << std::endl;
}