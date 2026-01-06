#include <stdio.h>

void decompose(double x, long int_part,double frac_part)
{
  int_part = (long) x;
  frac_part = x - int_part;
}

int main() {
  int i, d;
  decompose(3.14159, i, d);
 
  return 0;
}