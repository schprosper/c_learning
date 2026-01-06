#include <stdio.h>
void f(const int *p);

int main() {
  int i=1,*p=&i;

  f(p);

  return 0;
}

void f(const int *p)
{
  //*p = 0;   // WRONG，编译器会提示错误
}