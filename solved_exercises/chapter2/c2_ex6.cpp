#include <iostream>
#include <math.h>
#include <cassert>

#define assertm(exp, msg) assert(((void)msg, exp))

// Function prototypes
double f_x(double x);
double f_prime_x(double x);

int main(int argc, char* argv[]) 
{
    std::cout << "CHAPTER 2 - EXERCISE 4" << std::endl;

    double x0 = 0.0;
    int max_iter = 100;
    double epsilon = 1e-6;

    for (int i = 0; i < max_iter; i++) {
        double x1 = x0 - f_x(x0) / f_prime_x(x0);
        std::cout << "Iteration " << i << std::printf(": x = %.8f",x1) << std::endl;
        assertm(fabs(x1 - x0) >= epsilon, "Convergence criteria met");
        x0 = x1;
    }

    return 0;
}

double f_x(double x) {
    return exp(x) + pow(x, 3) - 5;
}

double f_prime_x(double x) {
    return exp(x) + 3 * pow(x, 2);
}