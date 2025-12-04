#include <stdio.h>
#include <string.h>

int main() {
  char str1[10],str2[20]="Cheng DuChina";
  
  strncpy(str1, str2, sizeof(str1) - 1);
  str1[sizeof(str1) -1] = '\0';
  printf("%s",str1);

  return 0;
}