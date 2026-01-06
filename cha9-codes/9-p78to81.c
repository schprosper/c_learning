#include <stdio.h>
void f(int n);
void f_multi_dimesion_array(int m, int n);

int main() {

  return 0;
}

void f(int n )
{
  int a[n],*p;
  p = a;
}

void f_multi_dimesion_array(int m, int n)
{
  int a[m][n], (*p)[n],i;//只有当m 等于n时结果才是正确的。如果m不等于n，则后续对指针p 的使用都将导致未定义的行为。
  p = a;

  for (p = a; p < a + m; p++)
    (*p)[i] = 0;
}
