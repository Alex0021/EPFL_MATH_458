#include <iostream>
/* -------------------------------------------------------------------------- */
using namespace std; 
/* -------------------------------------------------------------------------- */



/* prime-number finding program

   will (after bugs are fixed) report a list of all primes which are
   less than or equal to the user-supplied upper bound

   riddled with errors! */




void CheckPrime(int N);
int Prime[10];  /* Prime[I] will be 1 if I is prime, 0 otherwi */

/* -------------------------------------------------------------------------- */

void getUserEntry(int Upperbound){
  cout << "enter upper bound" << endl;
  cin >> Upperbound;
}

/* -------------------------------------------------------------------------- */



int main(int argc, char ** argv)

{ 
  int N = 0; // loop index
 
  int UpperBound = 0;  /* we will check all number up through this one for
		      primeness */


  // get user entry
  getUserEntry(UpperBound);
  
  // initialize the prime number array
  Prime[2] = 1;

  //get all the prime numbers between 3 and upperbound
  for (N = 3; N <= UpperBound; N += 2)
    CheckPrime(N);
    if (Prime[N]) cout << N << " is a prime" << endl;

}
