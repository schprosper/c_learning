#include <stdio.h>
#define N 10

int main() {
  int a[N]={1,2,3,4,5,6,7,8,9,10}, *p;
/*
  while (*a != 0)
	a++; //错误！
*/
  p = a;
  while (*p != 0)
    p++;

  return 0;
}