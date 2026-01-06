#include <stdio.h>

int *max(int *a, int *b);

int main() {
  int *p, i=1, j=10;

  p = max(&i, &j);
  printf("%d,%d两者大值=%d",i,j,*p);

  return 0;
}

int *max(int *a, int *b)
{
  if (*a > *b)
	return a;
  else
	return b;
}

