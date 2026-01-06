#include <stdio.h>
size_t my_strlen_ver1(const char *s);
size_t  my_strlen_ver2(const char *s);
size_t  my_strlen_ver3(const char *s);
size_t  my_strlen_ver4(const char *s);
size_t  my_strlen_ver5(const char *s);
size_t my_strlen_ver6(const char *s);

int main() {
  printf("\"Cheng Du\"字符串长度=%d\n",my_strlen_ver1("Cheng Du"));
  printf("\"Cheng Du\"字符串长度=%d\n",my_strlen_ver2("Cheng Du"));
  printf("\"Cheng Du\"字符串长度=%d\n",my_strlen_ver3("Cheng Du"));
  printf("\"Cheng Du\"字符串长度=%d\n",my_strlen_ver4("Cheng Du"));
  printf("\"Cheng Du\"字符串长度=%d\n",my_strlen_ver5("Cheng Du"));
  printf("\"Cheng Du\"字符串长度=%d\n",my_strlen_ver6("Cheng Du"));

  return 0;
}

size_t my_strlen_ver1(const char *s)
{
    int n ;
    for(n = 0; *s != '\0'; n ++)
       s ++;
    return n;
}

size_t  my_strlen_ver2(const char *s)
{
    int n =0;
    for(; *s != '\0'; s ++)
        n ++;
    return n;
}

size_t  my_strlen_ver3(const char *s)
{
   int n =0;
   for(; *s; s ++)
     n ++;
   return n;
}

size_t  my_strlen_ver4(const char *s)
{
    size_t n = 0;
    for(; *s++;)
        n ++;
    return n;
}

size_t  my_strlen_ver5(const char *s)
{
    size_t n= 0;
    while(*s++)
        n ++;
    return n;
}

size_t my_strlen_ver6(const char *s)
{
    const char *p = s;  
    while(*s)
        s++;
    return s - p;	
}



