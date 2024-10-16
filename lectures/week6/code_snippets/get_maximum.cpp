int getMaximum(const int &a, const int &b) {
  if (a > b)
    return a;
  return b;
}
double getMaximum(const double &a, const double &b) {
  if (a > b)
    return a;
  return b;
}

int main() {
  double a, b;
  double res_d = getMaximum(a, b);
  int c, d;
  int res_i = getMaximum(c, d);
}