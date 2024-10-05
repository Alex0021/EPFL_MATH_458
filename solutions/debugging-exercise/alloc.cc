#include <iostream>
//#include <cstdlib>
#include <vector>

#define NB_ELEMENT 10

int main(int argc, char *argv[])
{
  
  std::vector<int> array(NB_ELEMENT);

  /* some code here */

  for(int i = 1; i <= NB_ELEMENT; ++i)
    array[i] = 0;

  /* some other code here */

  return 0;
}
