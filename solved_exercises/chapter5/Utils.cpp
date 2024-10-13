#include "Utils.hpp"

void loadFromFile(const char *filepath, double *&a, unsigned int &N)
{
    std::fstream f(filepath, std::ios::in);
    // Safety check
    assert(f.is_open());
    // First line defines the size
    f >> N;
    PRINTD("Initializing a %d elements vector...\n", N);
    a = new double[N];
    // Iterate through the line
    for (int i=0; i<N; i++)
    {
        f >> a[i];
    }
    PRINTD(" DONE!\n");
    f.close();
}

void loadFromFile(const char *filepath, double **&A, unsigned int &N, unsigned int &M)
{
    std::fstream f(filepath, std::ios::in);
    // Safety check
    assert(f.is_open());
    // First line defines the size
    f >> N >> M;
    PRINTD("Initializing a %dx%d matrix...", N, M);
    allocate(A, N, M);
    // Iterate through the line
    for (int i=0; i<N; i++)
    {
        for (int j=0;j<M;j++)
        {
            f >> A[i][j];
        }
    }
    PRINTD(" DONE!\n");
    f.close();
}

void allocate(double *&a, const unsigned int N)
{
    a = new double[N];
}

void allocate(double **&A, const unsigned int N, const unsigned int M)
{
    A = new double* [N];
    for (int i=0;i<N;i++)
    {
        A[i] = new double[M];
    }
}

void deallocate(double *a)
{
    delete[] a;
}

void deallocate(double **A, const unsigned int &N)
{
    for (int i=0;i<N;i++)
    {
        delete[] A[i];
    }
    delete[] A;
}

void mean_std(const double *const values, const unsigned int &size, double &mean, double &std)
{
    // Compute the mean
    mean = 0;
    for (int i=0;i<size;i++)
    {
        mean += values[i];
    }
    mean /= size;
    // Compute std
    std = 0;
    for (int i=0;i<size;i++)
    {
        std += (values[i] - mean)*(values[i] - mean);
    }
    std = sqrt(std / (size-1));
}

double **multiply2(double ** A, const unsigned int &nrows_a, const unsigned int &ncols_a, 
                    double ** B, const unsigned int &nrows_b, const unsigned int &ncols_b)
{
    // Check matrices sizes for proper multiplication
    assert(ncols_a == nrows_b);

    // Reserve space for C matrix to be returned
    const unsigned int nrows_c = nrows_a;
    const unsigned int ncols_c = ncols_b;
    
    double **C;
    allocate(C, nrows_c, ncols_c);
    // Perform multiplication A*B
    double temp;
    for (int i=0;i<nrows_c;i++)
    {
        for (int j=0;j<ncols_c;j++)
        {
            temp = 0;
            // Perform the (row*col) multiply-add
            for (int k=0;k<ncols_a;k++)
            {
                temp += A[i][k]*B[k][j];
            }
            C[i][j] = temp;
        }
    }
    return C;
}

double *multiply2(double **A, const unsigned int &N, const unsigned int &M,
                    double *b, const unsigned int &k)
{
    // Verify validity of sizes for multiplication
    assert(M == k);
    double *x = new double[N];
    for (int i=0;i<N; i++)
    {
        x[i] = 0;
        for (int j=0;j<M;j++)
        {
            x[i] += A[i][j]*b[j];
        }
    }
    return x;
}

double *multiply2(double *b, const unsigned int &k, double **A,
                    const unsigned int &N , const unsigned int &M)
{
    // Verify validity of sizes for multiplication
    assert(k == N);
    double *x = new double[M];
    for (int i=0;i<M; i++)
    {
        x[i] = 0;
        for (int j=0;j<N;j++)
        {
            x[i] += b[j]*A[j][i];
        }
    }
    return x; 
}

double **multiply2(double **A, const unsigned int &N , const unsigned int &M, double k)
{
    double **B;
    allocate(B, N, M);
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            B[i][j] = k*A[i][j];
        }
    }
    return B;
}

void printMatrix(double **A, const unsigned int &N, const unsigned int &M)
{
    std::cout << "[ ";
	for (int i=0; i<N;i++)
	{
		for (int j=0;j<M;j++)
		{
			std::cout << A[i][j] << " ";
		}
		if (i<N-1) {
			std::cout << std::endl << "  " ;
		}
	}
	std::cout << "]" << std::endl;
}

void printVector(double *a, unsigned int &k)
{
    std::cout << "[ ";
	for (int i=0; i<k;i++)
	{
        std::cout << a[i] << " ";
	}
	std::cout << "]" << std::endl;
}