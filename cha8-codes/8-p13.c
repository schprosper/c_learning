#include <stdio.h>

int main() {
  int *p;
  //printf("%d", *p);   //错误：未初始化的指针变量

  *p = 1;   //错误：未初始化的指针变量p进行赋值

  return 0;
}