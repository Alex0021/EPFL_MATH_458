#include "myvector_template_dim.hh"
#include <iostream>
#include <ostream>

// function to print in an ostream
template <typename T, int dim>
std::ostream &operator<<(std::ostream &stream, const MyVector<T, dim> &vect) {
  stream << "[";
  for (int d = 0; d < dim; ++d) {
    if (d != 0)
      stream << ", ";
    stream << vect[d];
  }
  stream << "]";
  return stream;
}

int main() {
  // using it
  MyVector<double> vector_3d;

  // template parameters are guessed by the compiler
  std::cout << vector_3d << std::endl;
}