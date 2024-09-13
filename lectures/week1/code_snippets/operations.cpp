#include <cmath>
int main(int argc, char *argv[]) {
  int a = 5, b = 2, c;

  c = a + b; // integer addition
  c = a - b; // integer substraction
  c = a * b; // integer multiplication
  c = a / b; // integer division (careful!)
  c = a % b; // modulo operation

  double x = 1.0, y = 2.0, z;

  z = (double)a / (double)b; // cast integer to a float

  z = x / y;     // floating point division
  z = sqrt(x);   // square root
  z = exp(y);    // exponential function
  z = pow(x, y); // x to the power of y
  z = M_PI;      // z stores the value of pi

  return 0;
}