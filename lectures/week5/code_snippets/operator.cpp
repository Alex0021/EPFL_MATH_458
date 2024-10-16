#include <iostream>

class A {
public:
  int operator[](int i) {
    // modifies the behavior
    return values[i] * 2;
  }

private:
  int values[100];
};

int main() {
  A a;
  std::cout << a[2] << std::endl;
}