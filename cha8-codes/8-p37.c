#include <stdio.h>

int main() {
  int a[10];
  
  *a = 7; //为a[0]赋值7 
  *(a+1) = 12; //为a[1]赋值12 

  printf("a[0]值=%d\n", a[0]);
  printf("a[1]值=%d\n", a[1]);

  return 0;
}