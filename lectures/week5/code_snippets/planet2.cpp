#include "planet2.hh"

void Planet::move(double delta[3]) {
  // DO SOME CODE
}

Planet::Planet() {
  coords = new double[3];
  coords[0] = 0.;
  coords[1] = 1.;
  coords[2] = 2.;
}

Planet::~Planet() {
  // delete memory
  delete[] coords;
}

int main() {
  // ...
}