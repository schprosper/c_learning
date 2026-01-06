#include <stdio.h>
#define N 10

int main() {
  int a[N]={1,2,3,4,5,6,7,8,9,10}, i, sum = 0;

  int *p;
  p = a;//表明数组名可作为指针
  for (p = &a[0]; p < &a[N]; p++)
    //sum += *p;
    sum += p[i];//也可以

/*
  int *p = a; //等价于：int *p; p = a;这两句
  //int *p;
  //(unsigned long)*p = a;//错误！
  for (i = 0; i < N; i++)
	sum += p[i]; //表明指针可作为数组名
 */
  printf("数组{1,2,3,4,5,6,7,8,9,10}元素值和=%d",sum);

  return 0;
}