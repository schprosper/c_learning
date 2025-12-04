#include <stdio.h>

int main() {
  char str = 'a';
  printf("%d \n", str);

  str ='z'- 1;
  printf("%d \n", str);
  
  char ch='C';
  ch >='A' && ch <= 'Z';

  char str1 = '5';	
  int x = str1 - '0';
  printf("%d", x);

  return 0;
}