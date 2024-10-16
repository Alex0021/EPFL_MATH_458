int main()

// Block 1
{
  int i = 5; // local to Block 1
  // Block 2
  {
    int j = 10; // local to Block 2
    i = 10;     // inherited from Block 1
  }
  // variable j is destructed
  // j = 5; // so ?
}
// variable i is destructed
