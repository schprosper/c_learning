#include <stdio.h>
#define LEN 10
int sum_two_dimensional_array(int *p, int row_multiply_col);

int main() {
  int a[2][3]={{1,2,3},{4,5,6}},total;
  int *p=&a[0][0];

  total = sum_two_dimensional_array(p, 2*3);
  printf("sum= %d\n",total);

  return 0;
}

int sum_two_dimensional_array(int *p, int row_multiply_col) //形参不出现多维数组，通过指针定位数组元素
{
  int i, sum = 0;
  
  for (i = 0; i < row_multiply_col; i++){
    sum += *p;
    p++;
  }
	         
  return sum;
}