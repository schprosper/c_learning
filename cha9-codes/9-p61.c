#include <stdio.h>

int *find_middle(int a[], int n);

int main() {
  int a[6]={1,2,3,4,5,6},n=6,*p;

  p=find_middle(a, n);
  printf("{1,2,3,4,5,6}的中间元素为%d",*p);

  return 0;
}

int *find_middle(int a[], int n) 
{
	return &a[n/2];
}
