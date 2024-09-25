#include <iostream>

void print_vector(double* v, int n, const char* name);
void print_matrix(double** A, int n, int m, const char* name);

int main(int argc, char* argv[]) 
{
    std::cout << "CHAPTER 2 - EXERCISE 4" << std::endl;

    double u[3] = {1.0, 2.0, 3.0};
    double v[3] = {6.0, 5.0, 4.0};
    double A[3][3] = {{1.0, 5.0, 0.0},
                    {7.0, 1.0, 2.0},
                    {0.0, 0.0, 1.0}};
    double B[3][3] = {{-2.0, 0.0, 1.0},
                    {1.0, 0.0, 0.0},
                    {4.0, 1.0, 0.0}};

    double w[3];
    for (int i=0; i<3; i++)
    {
        w[i] = u[i] - 3.0*v[i];
    }

    double x[3];
    for (int i=0; i<3; i++)
    {
        x[i] = u[i] - v[i];
    }
    
    print_vector(x, 3, "x");

    return 0;
}

void print_vector(double* v, int n, const char* name)
{
    std::cout << "Vector " << name << " = [ ";
    for (int i=0; i<n; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void print_matrix(double** A, int n, int m, const char* name)
{
    std::cout << "Matrix " << name << " = [ ";
    for (int i=0; i<n; i++)
    {
         std::cout << "[ ";
        for (int j=0; j<m; j++)
        {
            std::cout << A[i*m+j] << " ";
        }
        if (i<n-1)
        {
            std::cout << "]" << std::endl;
        }
        else
        {
            std::cout << "]";
        }
    }
    std::cout << "]" << std::endl;
}