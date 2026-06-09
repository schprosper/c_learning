# include<stdio.h>
#include<stdlib.h>
# include<string.h>
void main()
{
    char s[] = "hello";
    char *p = strchr(s,'l');
    char c= *p;
    *p = '\0';
    char *t = (char*)malloc(strlen(s) +1);
    strcpy(t,s);
    printf("%s\n",t);
    free(t);

    //找字符第一次出现的位置，返回这个位置的地址
    printf("%s\n",p);
}