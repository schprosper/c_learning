#include <stdio.h>

int main() {
  int a[10]={0}, i;
  
  a[0] = 1;
  
  printf("%d\n", a[5]);

  i=2;
  ++a[i];
 
  return 0;
}