#include <stdio.h>

void decompose(double x, long *int_part, double *frac_part);
void decompose_without_point(double x, long int_part, double frac_part);

int main() {
  long i;
  double d;

  //decompose_without_point(3.14159, i, d);
  decompose(3.14159, &i, &d);
  
  printf("3.14159的整数部分=%d, 小数部分=%f", i, d);

  return 0;
}

void decompose(double x, long *int_part, double *frac_part)
{
  *int_part = (long) x;
  *frac_part = x - *int_part;
}

void decompose_without_point(double x, long int_part, double frac_part)
{
  int_part = (long) x;
  frac_part = x - int_part;
}