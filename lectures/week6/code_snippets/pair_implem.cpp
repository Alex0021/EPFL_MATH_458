#include <iostream>
#include <utility>

template <typename T1, typename T2> struct pair {
  T1 obj1;
  T2 obj2;
};

pair<int, int> foo() {
  // return two integers together
  return pair<int, int>{2, 3};
}

int main() {
  pair<int, int> p = foo();
  // fetching the integers
  int a = p.obj1;
  int b = p.obj2;
}