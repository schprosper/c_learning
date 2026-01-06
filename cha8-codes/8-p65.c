#include <stdio.h>

int main() {
  int m,n,a[m][n],i=1;
  int (*p)[n];
  
  for (p = a; p < a + m; p++)
    (*p)[i] = 0;

  return 0;
}