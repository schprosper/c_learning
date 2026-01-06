#include <stdio.h>

void store_zeros(int a[], int n);

int main() {
  int b[100]={1,2};

  store_zeros(b, 100);
    
  printf("b[0]=%d,b[1]=%d",b[0],b[1]);

  return 0;
}

void store_zeros(int a[], int n)
{
  int i;
  
  for (i = 0; i < n; i++) 
	a[i] = 0;
}
