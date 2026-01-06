#include <stdio.h>
#define LEN 100
//#define LEN 2

int sum_array(int a[static 3], int n);

int main() {
  int b[LEN]={1,2,3,4,5};
  //int b[LEN]={1,2};  
  
  int total = sum_array(b, LEN);  //b<LEN时,警告
  
  printf("b[LEN]={1,2,3,4,5}元素和=%d",total);
  //printf("b[LEN]={1,2}元素和=%d",total);

  return 0;
}

int sum_array(int a[static 3], int n)
{
  int i, sum = 0;
  
  for (i = 0; i < n; i++)
	sum += a[i];
  
  return sum;
}
