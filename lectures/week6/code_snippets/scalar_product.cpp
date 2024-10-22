#include "myvector_template_dim.hh"
#include <iostream>

// function to make the scalar product between to vectors
template <typename T, int dim>
T scalarProduct(const MyVector<T, dim> &v1, // vector1
                const MyVector<T, dim> &v2  // vector2
) {

  T res;
  for (int d = 0; d < dim; ++d)
    res += v1[d] * v2[d];
  return res;
}

int main() {
  // using it
  MyVector<double> vector1_3d;
  MyVector<double> vector2_3d;

  double res = scalarProduct(vector1_3d, vector2_3d);
  std::cout << res << std::endl;
}

/////////////////
// another possibility as shown in class :
// introduction to type traits
// => embeds accissible information(type, dim) in struct
///////////////7/

// specialization for vectors
template <typename T1, typename T2>
typename T1::value_type scalarProduct2(const T1 &v1, const T2 &v2) {

  typename T1::value_type res;
  for (int d = 0; d < T1::_dim; ++d)
    res += v1[d] * v2[d];
  return res;
}

template <typename T = double, int dim = 3> struct MyVector2 {

  T operator[](int i) const { return values[i]; }
  using value_type = T;
  static const int _dim = dim;

  T values[dim];
};

void foo() {
  MyVector2 v1;
  MyVector2 v2;
  auto ret = scalarProduct2(v1, v2);
}
