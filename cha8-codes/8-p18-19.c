#include <stdio.h>

int main() {
  int a[10], *p;
  
  p = &a[0];
  *p = 5;

  printf("a[0]=%d\n", *p); 

  return 0;
}