#include <stdio.h>
#include <string.h>

int main() {
  char name1[]="John", name2[]="Geoffery";
  
  if (strcmp(name1, name2)==0)
    puts("name1与name2同");
  else puts("name1与name2不同");
  
  strcmp(name1, "John");
  strcmp("John", "Geoffery");
  
  char str1[]="abc", str2[]="bcd";
  if(strcmp(str1, str2) < 0) 
    puts("tr1小于tr2");
  else puts("tr1大于tr2");

  char str3[]="abc", str4[]="abcd";
  if(strcmp(str1, str2) < 0) 
    puts("tr3小于tr4");
  else puts("tr3大于tr4");

  return 0;
}