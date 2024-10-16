#include <iostream>

struct Planet {

  void test() { std::cout << this << std::endl; }
};

int main() {
  Planet p;
  std::cout << &p << std::endl;
  p.test();
}