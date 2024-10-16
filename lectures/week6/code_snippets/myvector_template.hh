// a generic Vector for any scalar type
template <typename T> class MyVector {
public:
  T &operator[](unsigned int dim) { return value[dim]; }

private:
  T value[3];
};

MyVector<double> real_vector;
MyVector<int> integer_vector;