/*
 * exercise-template.cpp <--- The name of the source file goes here
 *
 * <--- Description of the program goes here.
 *
 * Created on: September 02, 2015 <--- Fill in the date here
 * 	   Author: Davide Forti <davide.forti@epfl.ch> <--- Fill in your name (and e-mail) here
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>
#include <memory>
#include "math.h"
#include <cassert>
#include "Utils.hpp"

void swap2(double *p1, double  *p2) 
{
    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
}

void swap2(double &x, double &y)
{
    x = x+y;
    y=x-y;
    x=x-y;
}

void exercise3()
{
    double i=5.0;
    double j=10.1;
    std::cout << "Values before: i=" << i << ", j=" << j << std::endl;
    swap2(&i, &j);
    std::cout << "Values after: i=" << i << ", j=" << j << std::endl;
    swap2(i, j);
    std::cout << "Values after: i=" << i << ", j=" << j << std::endl;
}

void exercise4()
{
    double test[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double mean, std;
    mean_std(test, 5, mean, std);
    std::cout << "Mean: " << mean << ", std: " << std << std::endl;
}

void exercise5()
{
// Define sizes for matrices
    const int rowsA = 2, colsA = 2;
    const int rowsB = 2, colsB = 3;

    // Define matrix A (2x2) dynamically
    double** A;
    allocate(A, rowsA, colsA);

    // Initialize matrix A
    A[0][0] = 1.0; A[0][1] = 2.0;
    A[1][0] = 3.0; A[1][1] = 4.0;

    // Define matrix B (2x3) dynamically
    double** B;
    allocate(B, rowsB, colsB);

    // Initialize matrix B
    B[0][0] = 1.0; B[0][1] = 2.0; B[0][2] = 3.0;
    B[1][0] = 4.0; B[1][1] = 5.0; B[1][2] = 6.0;

    // Print matrix A
    std::cout << "Matrix A:" << std::endl;
    printMatrix(A, rowsA, colsA);

    // Print matrix B
    std::cout << "Matrix B:" << std::endl;
    printMatrix(B, rowsB, colsB);

    double **C = multiply2(A, rowsA, colsA, B, rowsB, colsB);

    // Print matrix B
    std::cout << "Matrix C:" << std::endl;
    printMatrix(C, rowsA, colsB);

    // Free dynamically allocated memory for matrix A
    deallocate(A, rowsA);
    deallocate(B, rowsB);
    deallocate(C, rowsA);

}

void exercise6()
{
    double **A, **O;
    unsigned int N,M,P,Q;
    double *b;
    unsigned int k;
    loadFromFile("data/A.dat", A, N, M);
    loadFromFile("data/M.dat", O, P, Q);
    loadFromFile("data/b.dat", b, k);

    std::cout << "A = " << std::endl;
    printMatrix(A, N, M);

    std::cout << "b= " << std::endl;
    printVector(b, k);

    double *x;
    x = multiply2(b, k, A, N,M);

    printVector(x, M);

    deallocate(A, N);
    deallocate(O, P);
    delete[] b;
    delete[] x;
}



int main(int argc, char* argv[])
{
	/*
	 * The body of the program goes here
	 */

    // exercise3();
    // exercise4();
    // exercise5();
    exercise6();
    return 0;
}