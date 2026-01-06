#include <stdio.h>
#define N 5
int find_largest(int a[], int n);

int main() {
  int n=10,max;
  int a[10]={1,2,3,4,5,6,7,8,9,10};//编译器预留10个整形变量的空间
  //int *a;//编译器预留  1个指针变量的空间

  max=find_largest(a, n);
  printf("{1,2,3,4,5,6,7,8,9,10}中最大值=%d\n",max);

  int b[N]={1,2,3,4,5}, largest;
  largest = find_largest(b, N);//该调用把指向“数组b的第1个元素”的指针赋值给形参a,数组b自身并未被复制！
  printf("{1,2,3,4,5}中最大值=%d",largest);
  
  return 0;
}

int find_largest(int a[], int n)//等同于int find_largest(int *a, int n)
{
  int i, max;
  
  max = a[0];

  for (i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  
  return max;	
}
