#include <cassert>
#include <fstream>
#include <iostream>

int main() {
  std::ofstream write_output("Output.dat");
  assert(write_output.is_open());

  write_output << "Hello world !" << std::endl;

  write_output.close();
}