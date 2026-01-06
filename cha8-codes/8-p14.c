#include <stdio.h>

int main() {
  int i=1, j, *p, *q;
  
  p = &i;   
  q = p;
  
  printf("i=%d\n", *p);
  printf("j=%d\n", *q);
  
  return 0;
}