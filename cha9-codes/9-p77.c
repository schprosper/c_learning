#include <stdio.h>
#define NUM_ROWS 2
#define NUM_COLS 4

int find_largest(int a[], int n);

int main() {
  int a[2][4]={{1,2,3,4},{5,6,7,8}},largest;

  //largest = find_largest(a, NUM_ROWS * NUM_COLS); //WRONG:a的类型是int (*)[NUM_COLS] ，而 find_largest希望接受的参数类型是int *，故而会报错
  largest = find_largest(a[0], NUM_ROWS * NUM_COLS);//a[0] 指向数组的0行0列元素，其类型为int * （经过编译器转换），故可行。

  printf("{{1,2,3,4},{5,6,7,8}}中最大值=%d",largest);

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
