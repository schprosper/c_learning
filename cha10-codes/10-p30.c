#include <stdio.h>
#include <stdlib.h>

int main() {
  char lines[80];
  gets(lines);
  printf("%s \n", lines);

  return 0;
}