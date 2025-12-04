#include <stdio.h>

int main() {
  char ch = 'R';

  putchar(ch);
  putchar('\n');
  printf("%c\n", ch);

  char name[ ] = "Geoffrey Hinton";
  for(int i = 0; i < 15; i ++){      
    putchar(name[i]);
  }
   putchar('\n');

  return 0;
}
