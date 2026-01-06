#include <stdio.h>

int power(int x, int n)
{
  int result = 1;
  
  while (n-- > 0)
    result = result * x;
  
  return result;
}

void main()
{
    printf("%d\n",power(2,3)) ;
}
