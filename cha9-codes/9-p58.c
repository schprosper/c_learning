#include <stdio.h>

int main() {
  int i;
  int *p;
  p = &i;
  
  printf("输入i:");
  scanf("%d", &i);
  //scanf("%d", i);//WRONG，读入的数被存入i中整数指向的地址，危险
  printf("i值=%d\n",i);

  printf("再输入i:");
  scanf("%d", p);
  //scanf("%d", &p);//WRONG，读入的数被存在p中而不是i中，危险
  printf("i值=%d",i);

  return 0;
}
