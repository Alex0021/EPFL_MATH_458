class B;

class A {

private:
  friend B;
  int secret;
};

class B {
  int getSecret(A &a) { return a.secret; }
};

int main() {
  // ...
}