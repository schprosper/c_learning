#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int hello = 0 ;


int main(int argc, char const *argv[])
{
    char s[] = "hello";
    char *p = strchr(s, 'l');//s 会存储所有的之后的东西
    char c = *p;
    *p = '\0';
    char *t = (char*)malloc(strlen(s)+1);
    strcpy(t, s);
    printf("%s\n", t);
    free(t);



    printf("\n\n\n---------------");
    char s1[] = "hello";
    char *p1 = strchr(s1,'l');
    printf ("%s",p1);

    return 0;
}