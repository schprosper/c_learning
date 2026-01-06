#include <stdio.h>

int sum_array(int a[], int n);

int main() {
  //int b[] = {3, 0, 3, 4, 1};
  int total,i=1,j=2,k=3;
  (int [4]){1, 9, 2, 1};//(int []){1, 9, 2, 1}
  (int [10]){8, 6};
  (const int []){5, 4};
  
  //total = sum_array(b, 5);
  total = sum_array((int []){3, 0, 3, 4, 1}, 5);
  //total = sum_array((int [5]){3, 0, 3, 4, 1}, 5);
  //total = sum_array((int []){2 * i, i + j, j * k},3);

  printf("{3, 0, 3, 4, 1}元素值和=%d",total);
  //printf("{2 * %d, %d + %d, %d * %d}元素值和=%d",i,i,j,j,k,total);
  
  return 0;
}

int sum_array(int a[], int n)
{
  int i, sum = 0;
  
  for (i = 0; i < n; i++)
	sum += a[i];
  
  return sum;
}