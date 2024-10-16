#include "myvector_template_dim.hh"

template <typename T> T getMaximum(const T &a, const T &b) {
  if (a > b)
    return a;
  return b;
}

// specialization for vectors
template <>
MyVector<double, 3>
getMaximum<MyVector<double, 3>>(const MyVector<double, 3> &v1,
                                const MyVector<double, 3> &v2) {

  MyVector<double, 3> max;
  for (int i = 0; i < 3; ++i) {
    max[i] = getMaximum(v1[i], v2[i]);
  }
  return max;
}

// overloading
template <typename T, int dim>
MyVector<T, dim> getMaximum(const MyVector<T, dim> &v1,
                            const MyVector<T, dim> &v2) {

  MyVector<T, dim> max;
  for (int i = 0; i < dim; ++i) {
    max[i] = getMaximum(v1[i], v2[i]);
  }
  return max;
}

int main() {
  MyVector<double> v1, v2;
  MyVector<double> res = getMaximum(v1, v2);
}