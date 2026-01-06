#include <stdio.h>
#include <stdlib.h>

void print_pun(void);
void print_int(int i);

int main() {
  int status=-1, n=1;
  print_pun();

  return 0;
  //return status;
  //return n >= 0 ? n : 0;
  //exit(0);   /* 正常终止 */
  //exit(EXIT_SUCCESS); /* EXIT_SUCCESS是0的同意符号 */
  //exit(EXIT_FAILURE); /* 异常终止 */
}

void print_pun(void)
{
  printf("To C, or not to C: that is the question.\n");
  print_int(2);

  return;   // OK, but not needed
}

void print_int(int i)
{
  if (i < 0) return;
  if (i > 1000) return;
  //if (i < 0 || i > 1000) return;

  printf("%d", i);
}