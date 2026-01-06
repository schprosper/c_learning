#include <stdio.h>
#define N 20
int main() {
  int a[N],i=1,j=1;
  
  a[i+j*10] = 0;

  i = 0;
  while (i < N)
	a[i++] = 0;  //数组下标表达式甚至可能会有副作用

  return 0;
}