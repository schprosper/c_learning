#include <stdio.h>
char *my_strcat_ver1(char *s1, const char *s2);
char *my_strcat_ver2(char *s1, const char *s2);

int main() {
  char s1[]="Cheng Du", s2[]=" Si Chuan";
  
  my_strcat_ver1(s1, s2);
  puts(s1);

  char s3[]="Cheng Du";
  my_strcat_ver2(s3, s2);
  puts(s3);

  return 0;
}

char *my_strcat_ver1(char *s1, const char *s2)
{
    char *p = s1;
    
    while(*p != '\0')
        p ++;
    
    while(*s2 != '\0'){
        *p = *s2;
        p ++;
        s2 ++;
    }
    
    *p = '\0';
    
    return s1;  
}

char *my_strcat_ver2(char *s1, const char *s2)
{
    char *p = s1;
    while(*p)
        p ++;
    while(*p++ = *s2++)
        ;
    return s1;
}
