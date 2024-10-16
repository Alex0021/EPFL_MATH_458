#include "planet3.hh"

Planet::Planet(const Planet &p) {

  // copy pointer ?
  coords = p.coords;

  // or copy the content ?
  coords = new double[3];
  for (int i = 0; i < 3; ++i) {
    coords[i] = p.coords[i];
  }
}

int main() {
  // ...
}