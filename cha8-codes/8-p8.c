#include <stdio.h>

int main() {
  int i, j, a[10], b[20];
  
  int *p;	// points only to integers 
  double *q;	// points only to doubles 
  char *r;		//points only to characters

  typedef int * point_int;
  point_int  *m;
  
  printf("指向int的指针p的存储大小为%d\n",sizeof(p));
  printf("指向double的指针q的存储大小为%d\n",sizeof(q));
  printf("指向char的指针r的存储大小为%d\n",sizeof(r));
  printf("指向int *的指针r的存储大小为%d\n",sizeof(m));
  printf("而int的存储大小为%d,double的存储大小为%d,char的存储大小为%d\n",sizeof(int),sizeof(double),sizeof(char));

  return 0;
}