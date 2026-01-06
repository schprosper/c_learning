#include <stdio.h>

int main() {
  int i, sum, n;
  
  i = 1;
  sum = 0;
  n = 1000;
  while (i <= n) {
    sum += i++;
    /*
    sum += i;
    i++;
    */
  }

  return 0;
}