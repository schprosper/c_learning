#include <stdio.h>

int main() { 
  int i, sum;
  sum = 0;
/*
  for(i = 1; i <= 100;i++){     
     sum += i;
  }
*/
for(i = 1; i <= 100; ) {     
  sum += i;
  i++;
 }


  printf("1到100整数求和为%d\n",sum);

  return 0;
}