#include <iostream>
int main() {
  int x = 1.;
  int y = 0.;

  if (y == 0) {

    std::cerr << "Error - division by zero\n";

  } else {

    std::cout << x / y << "\n";
    std::cout.flush();
  }
}