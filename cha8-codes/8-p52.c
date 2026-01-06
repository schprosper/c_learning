#include <stdio.h>
#define NUM_ROWS 2
#define NUM_COLS 3

int main() {
  int a[NUM_ROWS][NUM_COLS];
  //int a[NUM_ROWS][NUM_COLS]={[0][0] = 0};//正确，全部元素值为0
  //a[NUM_ROWS][NUM_COLS]={[0][0] = 0};//错误，why?
  
  int row, col;
  for (row = 0; row < NUM_ROWS; row++)
    for (col = 0; col < NUM_COLS; col++)
      a[row][col] = 0;
  
  int *p,i=0;
  for (p = &a[0][0]; p <= &a[NUM_ROWS-1][NUM_COLS-1]; p++){
    *p = 0;
    i++;
  }

  printf("i=%d",i); 

  return 0;
}