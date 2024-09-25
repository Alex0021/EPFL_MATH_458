#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char* argv[]) {
    std::fstream file;
    file.open("xy.dat", std::ios_base::out);
    file.precision(13);

    int N;
    std::cout << "Enter the number of grid points: ";
    std::cin >> N;
    assert(N > 1);
    double h = 1.0 / (N - 1);
    double y0 = 1.0;
    double x0=0.0;
    
    for(int i=0;i<N;i++) {
        file << x0 << " " << y0 << std::endl;
        x0 += h;
        y0 = y0/(1+h);
    }

    file.close();
    return 0;
}