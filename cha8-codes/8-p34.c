#include <stdio.h>
#define N 10

int main() {
  int a[N]={1,2,3,4,5,6,7,8,9,10},sum=0, *p;

  for (p = &a[0]; p < &a[N]; p++)
  sum += *p;

  p = &a[0];
  while (p < &a[N])
    sum += *p++;

  return 0;
}