#include <stdio.h>

int main() {
  int a[10]={1,2,3,4,5,6,7,8,9,10}, *p, *q, i;
  
  p = &a[5];
  q = &a[1];
  
  i = p - q;   // i is 4
  //i = p + q;  //错误提示：expression must have integral type,why?
  printf("i=%d\n", i); 
  
  i = q - p;   // i is -4 
  printf("i=%d\n", i); 

  return 0;
}