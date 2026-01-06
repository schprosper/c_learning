
#include <stdio.h>

int main() {
  int i = 11;
  
  //while (i-- >0); //错误
  while (i-- >0)  //正确
    printf("i=%d\n",i);

  //for (i = 10; i>0; i--);//错误
  for (i = 10; i>0; i--)//正确
    printf("(i=%d)\n",i);


  return 0;
}