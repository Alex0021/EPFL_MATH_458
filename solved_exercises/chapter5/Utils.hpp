#include <iostream>
#include <fstream>
#include <cassert>
#include <math.h>
#include "stdio.h"

#define DEBUG_OUTPUT

#ifdef DEBUG_OUTPUT
    #define PRINTD(...) printf(__VA_ARGS__); std::cout.flush();
#else
    #define PRINTD(...) ;
#endif

/**
 * @brief Load a vector from the specified file
 * @param filepath The relative filepath
 * @param a A pointer to the new dynamicaly allocated space containing the vector
 * @param N The number of elements
 */
void loadFromFile(const char *filepath, double *&a, unsigned int &N);

/**
 * @brief Load a matrix from the specified file
 * @param filepath The relative filepath
 * @param a A pointer to the new dynamicaly allocated space containing the matrix
 * @param N The number of rows
 * @param M The number of columns
 */
void loadFromFile(const char *filepath, double **&A, unsigned int &N, unsigned int &M);

/**
 * @brief Allocate heap memory for an array of size N
 * @param a A pointer for the allocated memory
 * @param N Number of elements
 */
void allocate(double *&a, const unsigned int N);

/**
 * @brief Allocate heap memory for an array of arrays of size NxM
 * @param A The pointer to the allocated memory
 * @param N Number of rows
 * @param M Number of columns
 */
void allocate(double **&A, const unsigned int N, const unsigned int M);

void deallocate(double *a);

void deallocate(double **A, const unsigned int &N);

void mean_std(const double *const values, const unsigned int &size, double &mean, double &std);

double **multiply2(double **A, const unsigned int &nrows_a, const unsigned int &ncols_a, 
                    double **B, const unsigned int &nrows_b, const unsigned int &ncols_b);

double *multiply2(double **A, const unsigned int &N, const unsigned int &M,
                    double *b, const unsigned int &k);

double *multiply2(double *b, const unsigned int &k, double **A,
                    const unsigned int &N , const unsigned int &M);

double **multiply2(double **A, const unsigned int &N , const unsigned int &M, double k);

void printMatrix(double **A, const unsigned int &N, const unsigned int &M);

void printVector(double *a, unsigned int &k);
