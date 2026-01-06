#include <stdio.h>
#define LEN 100

int sum_array(int a[], int n);
//int sum_array(int [], int);

int main() {
  int b[LEN]={1,2,3,4,5}, total;
  total = sum_array(b, LEN);
  //total = sum_array(b[], LEN);   // WRONG:b[]
  //total = sum_array(b, 5);
  //total = sum_array(b, 150);    // WRONG:150>N

  printf("b[LEN]={1,2,3,4,5}元素和=%d",total);

  return 0;
}

int sum_array(int a[], int n)
{
  int i, sum = 0;
  for (i = 0; i < n; i++)
	sum += a[i];
  return sum;
}
