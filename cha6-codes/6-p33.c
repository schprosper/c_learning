#include <stdio.h>

int main() {
  int i, sum; 
  
  i = 1;
  sum = 0;
  for( ; i <= 100; ){     
    sum += i;
    i++;
  }

  printf("1到100整数求和为%d\n",sum);
  
  return 0;
}