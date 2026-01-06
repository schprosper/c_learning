#include <stdio.h>

int main() {
  int a[10], i;

  printf("整型数组字节数为%d\n",sizeof(a));

  printf("整型数组数组元素的字节数为%d\n",sizeof(a[0]));
  printf("整型数组数组元素的字节数为%d\n",sizeof(i));

  printf("整型数组数长度为%d\n",sizeof(a)/sizeof(a[0]));


  return 0;
}