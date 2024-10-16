#include <iostream>
class Animal {

public:
  Animal(const std::string &name) { this->name = name; }
  virtual void scream() { std::cout << name << ": AAAAA" << std::endl; }

protected:
  std::string name;
};

class Dog : public Animal {

public:
  Dog(std::string &name) : Animal(name) {}

  void scream() override {
    Animal::scream();
    std::cout << name << ": OUAFF" << std::endl;
  }
};