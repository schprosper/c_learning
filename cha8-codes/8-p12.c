#include <stdio.h>

int main() {
  int i=1, j, *p=&i;

  printf("i=%d\n", *p);

  *p=2;
  printf("改变*p=2的值同时也会改变i的值i=%d\n", i);
  
  j = *&i;   // same as j = i
  printf("j=%d\n", j);

  return 0;
}