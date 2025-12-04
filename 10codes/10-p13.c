#include <stdio.h>
char digit_to_hex(int digit);

int main() {
  char ch;
  ch = "subject"[1];
  printf("%c\n",ch);

  printf("%c\n",digit_to_hex(6));
  printf("%c\n",digit_to_hex(15));

  return 0;
}

char digit_to_hex(int digit)
{
  return "0123456789ABCDEF"[digit]; 
}

