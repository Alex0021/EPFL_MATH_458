#include <iostream>

int arithmetic(int i) {
  if (i == 1)
    return 1;
  return i + arithmetic(i - 1);
}

int main() {
  int a = 5;
  std::cout << arithmetic(a);
  std::cout << std::endl;
}