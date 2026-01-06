#include <stdio.h>
#define NUM_ROWS 2
#define NUM_COLS 4

int main() {
  int a[NUM_ROWS][NUM_COLS]={{1,2,3,4},{11,12,13,14}},(*p)[NUM_COLS], i=1;
  
  for (p = &a[0]; p < &a[NUM_ROWS]; p++)
    (*p)[i] = 0;
  
  for (p = a; p < a + NUM_ROWS; p++)
    (*p)[i] = 0;

  return 0;
}