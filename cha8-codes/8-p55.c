#include <stdio.h>
#define NUM_ROWS 2
#define NUM_COLS 3

int main() {
  int a[NUM_ROWS][NUM_COLS]={{1,2,3},{4,5,6}}, *p, i=1,j;

  for (p = a[i]; p < a[i] + NUM_COLS; p++)  //p = a[i]等价于p = &a[i][0];
    *p = 0;
  
  for (j=0;j<NUM_COLS;j++)
    printf("a[%d][%d]=%d; ",i,j,a[i][j]);

  return 0;
}