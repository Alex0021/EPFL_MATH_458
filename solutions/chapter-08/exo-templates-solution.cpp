#include <cassert>
#include <iostream>

// I have to declare in advance the daughter class
// This is called "forward" declaration
template <typename T> class BoxTyped;

// The mother class of any TypedBox
class Box {
public:
  Box(){};
  virtual ~Box(){};
  // the type is not known to the mother: needs to be pure virtual
  virtual const std::type_info &type() = 0;
};

template <typename T> class BoxTyped : public Box {
public:
  // Variadic template declaration of the construction arguments of typed box
  // Allows to forward any number and any type for the constructor of 'T'
  // This is generic code to the extreme.
  template <typename... Args> BoxTyped(Args... args) {
    this->ptr = new T(args...);
  };
  // do not forget to delete memory
  ~BoxTyped() { delete ptr; };

  // The operator '=' can receive a parameter of type T
  // to assign the value to the one stored by the box
  T &operator=(const T &a) {
    assert(ptr != nullptr);
    *ptr = a;
    return *ptr;
  };
  // can access the value pointed by the pointer: de-reference operation
  T &operator*() { return *ptr; };
  // Can return type information thanks to the typeid function
  // unlike for the mother class Box we know have access to T
  const std::type_info &type() override { return typeid(T); }

private:
  // the raw pointer to store our boxed value
  T *ptr;
};

// This is a generic object, which is not templated and which
// will benefit for the mechanisms of the Box.
class Any {
public:
  // Conctructing an 'Any' object can be done with any
  // other type: template constructor
  template <typename T> Any(const T &a) {
    // allocate and construct a BoxTyped<T>
    BoxTyped<T> *ptr = new BoxTyped<T>(a);
    // We have to dereference twice
    // *ptr type is: BoxTyped<T>&
    // **ptr calls the operator '*' of BoxTyped<T> => type is: T&
    **ptr = a;
    // save it as a non templated Box is the member of 'Any'
    this->ptr = ptr;
  }
  // do not forget to clean memory
  ~Any() { delete ptr; }

  // almost the same as the constuctor
  template <typename T> Any &operator=(const T &a) {
    BoxTyped<T> *ptr = new BoxTyped<T>();
    *ptr = a;
    this->ptr = ptr;
    return *this;
  }

  // to attempt to cast an object to the stored type
  template <typename T> T &cast() {
    // if the type 'T' is the the one of the stored object: error!!
    return *(dynamic_cast<BoxTyped<T> &>(*this->ptr));
  }
  // this is just a shortcut to the type info
  const std::type_info &type() { return ptr->type(); }

private:
  // member storing the box
  Box *ptr;
};

////////////////////////////////////////////////////////////////
// dummy classes to test the possibilities of Box and Any
// in the main

class A {};
class B : public A {

public:
  B(int a){};
};

////////////////////////////////////////////////////////////////

int main() {

  // Boxing an int
  BoxTyped<int> box;
  *box = 2;
  // manipulate as a Box to proove it works
  Box &anonymous_box = box;
  std::cout << anonymous_box.type().name() << std::endl;

  // Boxing an object of type B
  BoxTyped<B> box2(B{2});
  // manipulate as a Box to proove it works
  Box &anonymous_box2 = box2;
  std::cout << anonymous_box.type().name() << std::endl;

  // Use completely anonymous objects to store our values
  Any i = 2;
  Any a = A{};
  Any b = B{2};
  std::cerr << "i type: " << i.type().name() << std::endl;
  std::cerr << "a type: " << a.type().name() << std::endl;
  std::cerr << "b type: " << b.type().name() << std::endl;
  std::cerr << "i cast: " << i.cast<int>() << std::endl;
  std::cerr << "a cast: " << &a.cast<A>() << std::endl;
  std::cerr << "b cast: " << &b.cast<int>() << std::endl; // this one will fail
}
