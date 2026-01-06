#include <stdio.h>
#include <string.h>

int main() {
  char str1[6] = "cat",str2[6] = "pig";
  
  strcat(str1, "pig"); 	//错误用法
  printf("%s\n",str1);

  strcpy(str1,"cat");
  strncat(str1, str2, sizeof(str1) -strlen(str1) - 1);
  printf("%s",str1);

  return 0;
}
