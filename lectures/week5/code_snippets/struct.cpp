#include <iostream>

struct NameType {
  double a;
  int b;
};

struct Planet {
  double coords[3];
  std::string name;
};

int main() {
  Planet p;
  p.coords[0] = 10;
  std::cout << sizeof(Planet) << std::endl;

  return EXIT_SUCCESS;
}