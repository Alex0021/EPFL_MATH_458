#include <iostream>

class Animal {
public:
  virtual void scream() { std::cout << name << ": AAAAA\n"; }

protected:
  std::string name;
};

class Dog : public Animal {
public:
  void scream() override {
    Animal::scream();
    std::cout << name << ": OUAFF\n";
  }
};