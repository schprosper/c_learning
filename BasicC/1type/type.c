//int 表示一个寄存器的大小

#include <stdio.h>

int main()
{
    int a = 0, b = 0;
    while (++a > 0)
        ;//空循环，让a不断增加！！
    printf("int数据类型最大数是:%d\n", a - 1);
    b++;
    while ((a = a / 10) != 0)//其实就是在做判断之前做了次运算。

    {
        b++;
    }
    printf("int数据类型最大的数的数位是:%d", b);
    return 0;
}