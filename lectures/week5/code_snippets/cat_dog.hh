#include <iostream>

class Cat {
public:
  void scream() { std::cout << name << ": MIAOU\n"; }

private:
  std::string name;
};

class Dog {
public:
  void scream() { std::cout << name << ": OUAFF\n"; }

private:
  std::string name;
};

int cannot_write() {
  Cat list[2];
  Cat c;
  Dog d;
  list[0] = c;
  list[1] = d;
}