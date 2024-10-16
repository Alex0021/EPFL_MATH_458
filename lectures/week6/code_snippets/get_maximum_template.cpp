template<typename T>
T getMaximum(const T & a, const T & b) {
  if (a > b)
    return a;
  return b;
}

int main(){
  double a,b;
  double res_d = getMaximum(a,b);
  int c,d;
  int res_i = getMaximum(c,d);
}