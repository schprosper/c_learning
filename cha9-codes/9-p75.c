#include <stdio.h>
#define NUM_COLS 4
int find_largest(int a[], int n);

int main() {
  int a[2][4]={{1,2,3,4},{5,6,7,8}},i=1,largest;

  largest = find_largest(a[i], NUM_COLS);
  printf("{{1,2,3,4},{5,6,7,8}}的第%d行元素最大值=%d",i+1,largest);
  
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
