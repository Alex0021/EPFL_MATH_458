#include <iostream>

template <int i> int arithmetic_template() {
  return i + arithmetic_template<i - 1>();
}

template <> int arithmetic_template<1>() {
  // ends recursion
  return 1;
}

int main() {
  std::cout << arithmetic_template<5>();
  std::cout << std::endl;
}