#include <stdio.h>
int main()
{
    int a;
    a = 10;

    printf("a++=%d\n", a++);// a++ 此时是a之前的值
    //这时候，虽然在printf里面，但是还是会变化

    printf("a=%d\n", a);// 但是，作为副作用a会变成原本+1

    printf("++a=%d\n", ++a);
    printf("a=%d\n", a);

    return 0;
}