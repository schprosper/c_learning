#include <stdio.h>

int main() {
  int i = 100; 
  
  do 
    printf("T minus %d and counting\n", i--);
  while (i > 0);

  return 0;
}