#include <iostream>

int main() {
  int pin;
  std::cout << "Enter your PIN, then hit RETURN\n";
  std::cin >> pin;

  // Read multiple variables at one:

  int account_number;
  std::cout << "Enter your account number\n";
  std::cout << "and then your PIN, each followed by RETURN\n";
  std::cin >> account_number >> pin;
}