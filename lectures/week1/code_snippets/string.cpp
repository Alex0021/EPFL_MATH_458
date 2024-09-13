#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string city; // note the std::
  city = "Oxford";  // note the double quotation marks

  std::cout << "String length = " << city.length() << "\n";
  std::cout << "Third character = " << city.at(2) << "\n";
  std::cout << "Third character = " << city[2] << "\n";
  // Prints the string in city
  std::cout << city << "\n";
  // Also prints city
  std::cout << city.c_str() << "\n";

  return 0;
}