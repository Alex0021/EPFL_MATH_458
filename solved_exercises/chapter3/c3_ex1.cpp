#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char* argv[]) {
    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0};

    std::fstream file;
    file.open("x_and_y.dat", std::ios_base::in);
    if (file.is_open()) {
        int choice;
        std::cerr << "Warning: file x_and_y.dat already exists. Append to it?" << std::endl << "Yes(1)/No(0): ";
        std::cin >> choice;
        int flags = std::ios::out;
        file.close();
        if (choice == 1) {
            file.open("x_and_y.dat", std::ios::out | std::ios::app);
        } else {
            file.open("x_and_y.dat", std::ios::out);
        }
    } else {
        file.open("x_and_y.dat", std::ios::out);
    }

    file.setf(std::ios::scientific);
    file.setf(std::ios::showpos);
    file.precision(13);

    for (int i = 0; i < 4; i++) {
        file << x[i] << " ";
    }
    file << std::endl;
    file.flush();
    for (int i = 0; i < 4; i++) {
        file << y[i] << " ";
    }
    file << std::endl;
    file.flush();

    file.close();
    return 0;
}