#include <stdio.h>

int main() {
  int a[10]={1,2,3,4,5,6,7,8,9,10}, *p, *q;

  p = &a[5];
  q = &a[1];

  printf("p<=q的值为%d\n", p <= q); 
  printf("p>=q的值为%d\n", p >= q);

  return 0;
}