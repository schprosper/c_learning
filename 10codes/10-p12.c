#include <stdio.h>

int main() {
  //char subject[5]; 
  //subject = "math";//错误：数组名是指针，不可以修改
  //subject[5]="math";//错误：assignment to 'char' from 'char *' makes integer from pointer without a cast [-Wint-conversion]gcc
  
  char subject[5]="math";//正确：字符数组的声明和初始化不可以分开
  char *p;
  p = "math";
  //p = subject;//也可

  /*复习一般数组声明和初始化*/
  //int a[10] = {1, 2, 3, 4, 5, 6}; //正确
  int a[10];
  //a = {1, 2, 3, 4, 5, 6};//错误
  //a[10] = {1, 2, 3, 4, 5, 6};//错误

  return 0;
}
