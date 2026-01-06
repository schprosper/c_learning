#include <stdio.h>

int main() { 
  int i, sum;
  sum = 0;
/*
  for(i = 1; i <= 100;i++){     
     sum += i;
  }
*/
  i = 1;
  sum = 0;
  for(; i <= 100; i++){     
    sum += i;
  }

  printf("1到100整数求和为%d\n",sum);

  return 0;
}