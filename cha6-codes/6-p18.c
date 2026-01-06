#include <stdio.h>

int main() {
  int i, n;
  
  i = 0;
  n = 100;
  do 
    printf("Hello, world No.%d\n",i++);
   while (i < n);  //注意分号

  return 0;
}