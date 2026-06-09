#include <stdio.h>
int main ()
{
    int a[10];


    printf("%p\n", &a);
    printf("%p\n", a);
    printf("%p\n", &a[0]);
    printf("%p\n", &a[1]);
    //他们的差值，就差了4，也就是一个int的大小
}