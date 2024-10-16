// a generic Vector for any scalar type
// template dimension (default: 3)
template <typename T, int dim = 3> class MyVector {

public:
  T &operator[](unsigned int d) { return value[d]; }

  const T &operator[](unsigned int d) const { return value[d]; }

private:
  T value[dim];
};

MyVector<double> vector_3d;
MyVector<double, 2> vector_2d;