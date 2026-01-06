#include <stdio.h>

int main() {
  int a[10]={1,2,3,4,5,6,7,8,9,10}, *p, *q, i;
  
  p = &a[8];
  q = p - 3;
  p -= 6;

  printf("a[8]=%d; a[5]=%d; a[2]=%d\n", a[8], *q, *p); 

  return 0;
}