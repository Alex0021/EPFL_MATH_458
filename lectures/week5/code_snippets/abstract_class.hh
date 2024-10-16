#include <iostream>
class Animal {

public:
  Animal(std::string name) { this->name = name; }
  virtual void scream() = 0;

protected:
  std::string name;
};

class Cat : public Animal {

public:
  Cat(const std::string &name) : Animal(name){};
  void scream() override { std::cout << name << ": MIAOU\n"; }
};

void makeItScream(Animal &a) { a.scream(); }

int main() {
  // this will lead to compilation error
  Animal a("kitty");

  // Instanciation of Daughter classes
  Cat c("kitty"); // ok

  // Can manipulate with daugther class reference
  Animal *ptr = &c; // ok
  Animal &ref = c;  // ok

  makeItScream(c); // polymorphism
}