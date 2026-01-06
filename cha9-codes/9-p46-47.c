#include <stdio.h>
int sum_array(int n, int a[n]);//Version 1 
//int sum_array(int n, int a[*]);  //Version 2a
//int sum_array(int, int [*]);     // Version 2b
//int sum_array(int n, int a[]);  // Version 3a 
//int sum_array(int, int []);     //Version 3b

int main() {
  int a[]={1,2,3,4,5,6}, n=6, sum=0;
  
  sum=sum_array(n, a);
  printf("a[]={1,2,3,4,5,6}元素值和=%d",sum);

  return 0;
}

int sum_array(int n, int a[n])
{
  int i,j,sum=0;

  for (i=0;i<n;i++)
    sum +=a[i];
  
  return sum;
}
