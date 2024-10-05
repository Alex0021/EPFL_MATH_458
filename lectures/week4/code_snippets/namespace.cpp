#include <iostream>

namespace PCSC {

int i = 5; // global variable
}

int main() {
  std::cout << PCSC::i;
  std::cout << std::endl;
}