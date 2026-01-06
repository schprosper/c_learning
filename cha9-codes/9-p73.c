#include <stdio.h>
int find_largest(int a[], int n);

int main() {
  int b[10]={1,2,3,4,5,6,7,8,9,10},largest;

  largest = find_largest(&b[5], 2);
  printf("{1,2,3,4,5,6,7,8,9,10}中第5个元素的后面2个元素最大值=%d",largest);

  return 0;
}

int find_largest(int a[], int n)
{
  int i, max;
  
  max = a[0];

  for (i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  
  return max;	
}
