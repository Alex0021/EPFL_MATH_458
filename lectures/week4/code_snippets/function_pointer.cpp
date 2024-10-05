#include <functional>

double foo(double a) { return a + 1; }

int main() {

  double (*ptr_foo)(double a) = &foo;
  std::function<double(double a)> ptr_foo_modern = &foo;

  ptr_foo(10);
  ptr_foo_modern(10);
}