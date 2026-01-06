#include <stdio.h>

int *f(void);

int main() {
  int *p;

  p = f();
  //printf("%d",*p);

  return 0;
}

int *f(void)
{
  int i;   

  return &i; //WRONG:绝对不可以是指向自动局部变量的指针！函数返回时此类变量不复存在！
}