#include <stdio.h>
#define NUM_ROWS 2
#define NUM_COLS 3

int main() {
  int a[NUM_ROWS][NUM_COLS]={{1,2,3},{4,5,6}};
 
  int *p,i=0;
  //p = &a[i][0];
  p = a[i];

  printf("a[2][3]={1 2 3\n         4 5 6}\n");
  printf("当p=a[%d]时，*p=*a[%d]即a[%d][0]=%d",i,i,i,*p); 

  return 0;
}