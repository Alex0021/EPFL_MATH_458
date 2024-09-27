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

void exercise1()
{
	int i=5;
	int *p_j=&i;
	*p_j=(*p_j*5);
	std::cout << "Value of i after multiplication: " << i << std::endl;

	int *p_k = new int;
	*p_k = i;
	*p_j = 0;

	std::cout << "Final value of i: " << i << std::endl;
	std::cout << "Final value of p_j: " << *p_j << std::endl;
	std::cout << "Final value of p_k: " << *p_k << std::endl;

}

void exercise2()
{
	int i=5;
	int j=10;
	int *p_i=&i;
	int *p_j=&j;

	p_j = &i;
	p_i = &j;

	std::cout << "Value of i: " << *p_i << "  , Value of j: " << *p_j << std::endl;

}

void exercise3()
{
	for (int j=0; j<10000000;j++)
	{
		double *vec1 = new double[3];
		double *vec2 = new double[3];

		for (int i=0;i<3;i++)
		{
			vec1[i] = i+1;
			vec2[i] = i;
		}

		// Dot product
		double result=0;
		for (int i=0;i<3;i++) 
		{
			result += vec1[i]*vec2[i];
		}

		// std::cout << "Result of dot product: " << result << std::endl;

		delete[] vec1;
		delete[] vec2;
	}
	std::cout << "FINISHED!" << std::endl;
}

void print_matrix(double** A, int rows, int cols)
{
	std::cout << "[ ";
	for (int i=0; i<rows;i++)
	{
		for (int j=0;j<cols;j++)
		{
			std::cout << A[i][j] << " ";
		}
		if (i<rows-1) {
			std::cout << std::endl << "  " ;
		}
	}
	std::cout << "]" << std::endl;
}

void exercise4()
{
	int rows=2; int cols=2;
	double **A = new double* [rows];
	double **B = new double* [rows];
	double **C = new double* [rows];
	for (int i=0; i<rows;i++)
	{
		A[i] = new double[cols];
		B[i] = new double[cols];
		C[i] = new double[cols];
		for (int j=0;j<2;j++)
		{
			A[i][j] = i+j+2;
			B[i][j] = i-j;
		}
	}
	std::cout << "A MATRIX" << std::endl;
	print_matrix(A, rows, cols);
	std::cout << "B MATRIX" << std::endl;
	print_matrix(B, rows, cols);
	// Compute C=A+B
	for (int i=0; i<rows;i++)
	{
		for (int j=0;j<cols;j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	//Print values of C
	std::cout << "C MATRIX" << std::endl;
	print_matrix(C, rows, cols);
	// Clear memory
	for (int i=0;i<rows;i++)
	{
		delete[] A[i];
		delete[] B[i];
		delete[] C[i];
	}
	delete[] A;
	delete[] B;
	delete[] C;
}

void exercise5()
{
	std::shared_ptr<int> p_x(new int);
	std::cout << "p_x use count: " << p_x.use_count() << std::endl;
	*p_x = 5;
	std::shared_ptr<int> p_y = p_x;
	std::cout << "p_x use count: " << p_x.use_count() << std::endl;
	p_y.reset();
	std::cout << "p_x use count: " << p_x.use_count() << std::endl;

	std::weak_ptr<int> wp_x = p_x;
	std::cout << "p_x use count: " << p_x.use_count() << std::endl;
	if (!wp_x.expired())
	{
		std::cout << "Value of p_x still acessible: " << *wp_x.lock() << std::endl;
	}
	p_x.reset();
	std::cout << "p_x reset! Use count: " << p_x.use_count() << std::endl;
	std::cout << "Thus, wp_x should be expired: " << wp_x.expired() << std::endl;

}

int main(int argc, char* argv[])
{
	/*
	 * The body of the program goes here
	 */
	//exercise1();
	// exercise2();
	// exercise3();
	// exercise4();
	exercise5();
    return 0;
}

