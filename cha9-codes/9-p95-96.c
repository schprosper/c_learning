#include <stdio.h>
int power(int x, int n);

int main() {
  int x=4, n=2;

  printf("%d的%d次方=%d",x,n,power(x, n));

  return 0;
}

int power(int x, int n)
{
  if (n == 0)
	return 1;
  else
	return x * power(x, n - 1);

  //return n == 0 ? 1 : x * power(x, n - 1);
}
