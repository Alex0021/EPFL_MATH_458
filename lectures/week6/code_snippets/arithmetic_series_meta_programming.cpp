#include <iostream>

// template <int i> int arithmetic_template() {
//   return i + arithmetic_template<i - 1>();
// }

// template <> int arithmetic_template<1>() {
//   // ends recursion
//   return 1;
// }

// with constexpr no need for specialization
template <int i> int arithmetic_template() {
  if constexpr (i == 1) {
    return 1;
  } else
    return i + arithmetic_template<i - 1>();
}

int main() {
  std::cout << arithmetic_template<100>();
  std::cout << std::endl;
}
