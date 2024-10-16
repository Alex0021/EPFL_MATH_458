#include <iostream>
class Animal {
public:
  void scream() { std::cout << name << ": AAAAA\n"; }

protected:
  std::string name;
};

class Cat : public Animal {
public:
  void scream() { std::cout << name << ": MIAOU\n"; }
};

class Dog : public Animal {
public:
  void scream() { std::cout << name << ": OUAFF\n"; }
};

void casting() {
  Cat c;
  Animal *ptr = &c;
  ptr->scream();
}

void makeItScream(Animal &a) {
  // do not know if 'a'
  //  is Cat or Dog
  a.scream();
}

int main() {
  Cat c;
  makeItScream(c);
}