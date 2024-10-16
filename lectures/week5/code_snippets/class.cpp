struct Planet {
  void move(double delta[3]);
  double coords[3];
};

void move_c_style(Planet &p, double delta[3]);

int main() {
  double delta[3];

  Planet p;
  p.move(delta);

  move_c_style(p, delta);
}

void Planet::move(double *delta) {
  // ...
}