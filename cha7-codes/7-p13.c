#include <stdio.h>

int main() {
  int a[10], i;	

  for (i = 1; i <= 10; i++) //错误：n个元素数组的索引是从0n
	a[i] = 0;

  return 0;
}