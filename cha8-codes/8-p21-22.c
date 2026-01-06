#include <stdio.h>

int main() {
  int a[10]={1,2,3,4,5,6,7,8,9,10}, *p, *q, i;
  
  p = &a[2];
  printf("p=%d\n",p);
  q = p + 3;
  printf("q=p+3=%d\n",q);
  printf("q-p=%d个int距离,每个int地址为4个字节=3*4=12个字节=q表示地址-p表示地址\n",q-p);
  p += 6;
/*
  q = &a[2];
  printf("q+q=%d\n",p+q);
*/

 /* 
  p +=10;
  printf("p=%d\n",p);
*/
  printf("a[2]=%d; a[5]=%d; a[8]=%d\n", a[2], *q, *p); 

  return 0;
}