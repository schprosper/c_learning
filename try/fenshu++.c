/*  a/b + c/d = (ad+cb)/bd */
#include <stdio.h>

int  main(){
    int a,b,c,d;
    printf ("分别输入两个分数，并用空格分开:");
    scanf ("%d/%d %d/%d",&a,&b,&c,&d);

    printf("和为：%d/%d" ,a*d + c*b , b*d);

    return 0 ;
}