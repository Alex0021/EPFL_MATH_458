class A;
int toto(A &a);

class A {

private:
  friend int toto(A &a);
  int secret;
};

int toto(A &a) { return a.secret; }

int main() {
  // ...
}