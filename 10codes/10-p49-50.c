#include <stdio.h>
#include <string.h>

int main() {
  char str1[20], str2[20];
  
  strcpy(str1, "abc");
  printf("str1中的字符串:%s\n",str1);

  strcat(str1, "def");   // str1 包含“abcdef” 
  printf("str1中的字符串:%s\n",str1);

  strcpy(str1, "abc");
  printf("str1中的字符串:%s\n",str1);
  strcpy(str2, "def");
  printf("str2中的字符串:%s\n",str2);
  strcat(str1, str2);   //str1 包含 “abcdef” 
  printf("str1中的字符串:%s\n",str1);
  
  strcpy(str1, "abc");
  strcpy(str2, "def");
  strcat(str1, strcat(str2, "ghi"));       // str1 包含“abcdefghi” 
  printf("str1中的字符串:%s\n",str1);

  return 0;
}
