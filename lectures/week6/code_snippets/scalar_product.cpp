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