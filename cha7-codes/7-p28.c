#include <stdio.h>
#define SIZE ((int) (sizeof(a) / sizeof(a[0])))

int main() {
  int a[10], i;

  for (i = 0; i < (int) (sizeof(a) / sizeof(a[0])); i++)
	a[i] = 0;
  
  for (i = 0; i < SIZE; i++)
	a[i] = 0;

  return 0;
}