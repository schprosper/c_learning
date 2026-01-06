#include <stdio.h>

int main() {
  int i=3, j=1;
  
  if (i > j) {
	// swap values of i and j
	int temp = i;
	i = j;
	j = temp;
  }

  return 0;
}
