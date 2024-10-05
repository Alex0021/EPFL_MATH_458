#include <iostream>

int i = 5; // global variable

int main() {
  int j = 7; // local variable
  std::cout << i << "\n";
  {
    int i = 10, j = 11;
    std::cout << i << "\n";   // local value of i is 10
    std::cout << ::i << "\n"; // global value of i is 5
    std::cout << j << "\n";   // value of j here is 11
  }
  std::cout << j << "\n"; // value of j here is 7
  return 0;
}