#include <iostream>

int main() {
  std::cout << "Hello World!\n";

  // Output multiple variables at the same time:

  int x = 1, y = 2;
  std::cout << "x = " << x << " and y = " << y << "\n";

  // Output is buffered, to force output:

  std::cout << "Hello World\n";
  std::cout.flush();
}