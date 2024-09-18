#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>

//////////////////////////////////////////////////////////////////////

void Statement() {}

//////////////////////////////////////////////////////////////////////

void if_syntax() {
  int p, q;
  if (p > q) {
    /*
    Statement1;
    Statement2;
    */
  }
}

//////////////////////////////////////////////////////////////////////

void if_short_syntax() {
  int p, q;
  if (p > q)
    Statement();
}

//////////////////////////////////////////////////////////////////////

void if_example1() {
  double x = -2.0;

  if (x < 0.0) {
    x = 0.0;
  }
}

//////////////////////////////////////////////////////////////////////

void if_else_example() {
  int i;
  double y;

  if (i > 0) {
    y = 2.0;
  } else {
    // When i <= 0
    y = 10.0;
  }
}

//////////////////////////////////////////////////////////////////////

void multiple_if_example() {
  int i;
  double y;

  if (i > 100) {
    y = 2.0;
  } else if (i < 0) {
    y = 10.0;
  } else {
    // When 0 <= i <= 100
    y = 5.0;
  }
}

//////////////////////////////////////////////////////////////////////

void nested_if_example() {
  double x, z, p, q;
  double y;

  if (x > z) {
    if (p > q) {
      // Both conditions have been met
      y = 10.0;
    }
  }
}

//////////////////////////////////////////////////////////////////////

void switch_statement() {
  int i=1;
  switch (i) {
  case 1:
    std::cout << "i = 1\n";
  case 20:
    // The following line is executed also in case i == 1!
    std::cout << "i = 1 or i = 20\n";
    break;
  case 30:
    std::cout << "i = 30\n";
    break;
  default:
    std::cout << "i is not 1, 20 nor 30\n";
  }
}

//////////////////////////////////////////////////////////////////////

void bool_condition() {
  bool flag = true;

  if (flag) {
    std::cout << "This will be printed\n";
  } else {
    // flag is false
    std::cout << "This won't be printed\n";
  }
}

//////////////////////////////////////////////////////////////////////

void and_condition() {
  double x, z, p, q;
  double y;

  if ((x > z) && (p > q)) {
    // Both conditions have been met
    y = 10.0;
  }
}

//////////////////////////////////////////////////////////////////////

void negation_condition() {
  int i;
  bool flag = false;

  if (!flag) {
    // !flag is true when flag is false
    i += 2;
  }
}

//////////////////////////////////////////////////////////////////////

void or_condition() {
  double p, q;
  double i;
  double y;

  if ((y > q) || (i != 1)) {
    // One or both conditions have been met
    y = 10.0;
  } else {
    // Neither condition has been met:
    // y<=q and i==1
    y = -10.0;
  }
}

//////////////////////////////////////////////////////////////////////

void while_statement() {
  double x = 10.0;
  int count = 0;
  while (x > 1.0) {
    // This loop will execute while x > 1, so if the
    // value of x does not decrease then it will not
    // terminate.

    x *= 0.5;
    std::cout << "x = " << x << ", count = " << count << "\n";
    count++;
    std::cout << "Reached bottom of while loop\n";
  }
  // Here we know the guard (x > 1.0) has broken.
  // This means that after the loop, x <= 1.0
  std::cout << "x = " << x << ", count = " << count << "\n";
}

//////////////////////////////////////////////////////////////////////

void do_while() {
  double x = .8;
  int count = 0;

  do {
    x *= 0.5;
    std::cout << "x = " << x << ", count = " << count << "\n";
    count++;
    std::cout << "Reached bottom of while loop\n";
  } while (x > 1.0);

  std::cout << "count = " << count << "\n";
}

//////////////////////////////////////////////////////////////////////

void for_loops() {
  for (int i = 0; i < 5; i++) {
    for (int j = 5; j > i; j--) {
      std::cout << "i = " << i << " j = " << j << "\n";
    }
  }
}

//////////////////////////////////////////////////////////////////////

void scalar_product() {
  double vector1[2], vector2[2];

  // The indices of an array start at 0, not at 1!

  vector1[0] = 0.5;
  vector1[1] = -2.3;
  vector2[0] = 34.2;
  vector2[1] = 0.015;
  double scalar_product = 0.0;

  for (int i = 0; i < 2; i++) {
    scalar_product += vector1[i] * vector2[i];
  }
}

//////////////////////////////////////////////////////////////////////

void tip1() {
  double x = 2.0;
  for (int i = 0; i < 5; i++)
    ;
  {
    x *= 2.0;
    std::cout << "x = " << x << "\n";
  }
}

//////////////////////////////////////////////////////////////////////

void tip2() {
  int x;
  x == 2 + 2;
  // This erroneous line has no effect
  // After testing x against the value 4, the true/false
  // answer is discarded.
  x = 4; // This is correct
}

//////////////////////////////////////////////////////////////////////

void tip3() {
  int x;
  if (x = 4) {
    x = 6;
  }
}

//////////////////////////////////////////////////////////////////////

void tip4() {
  double max = 0.0;
  int count = 0;
  double positive_numbers[4] = {1.0, 5.65, 42.0, 0.01};

  while (count < 4) {
    if (positive_numbers[count] > max) {
      max = positive_numbers[count];
    }
  }
}

//////////////////////////////////////////////////////////////////////

void tip5() {
  double p, q;
  double tolerance = 1.0e-8;
  int k;

  if (std::fabs(p - q) < tolerance) {
    k = 0;
  }
}

//////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
  Statement();
  if_syntax();
  if_short_syntax();
  if_example1();
  if_else_example();
  multiple_if_example();
  nested_if_example();
  switch_statement();
  bool_condition();
  and_condition();
  negation_condition();
  or_condition();
  while_statement();
  do_while();
  for_loops();
  scalar_product();
  tip1();
  tip2();
  tip3();
  tip4();
  tip5();
}