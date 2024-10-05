int main() {
  int a = 1, b = 2;
  int *ptr = &a;
  ptr = &b;
  int &ref = a;
  // I cannot change ref to point to b
}