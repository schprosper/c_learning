/* 知识点：
1. 最大公约数（GCD）求解：辗转相除法（欧几里得算法）的递归实现逻辑；
2. C语言函数：函数的声明、定义与递归调用方式；
3. 条件判断：if语句用于交换两数（保证a≥b）、判断余数是否为0；
4. 变量操作：int类型变量的交换；
5. 标准I/O：scanf读取输入整数、printf输出计算结果。
*/
#include<stdio.h>
int chf(int a, int b);
int chf(int a, int b)
{
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    int r=a%b;
    if(r==0) return chf(b,r); 
    return b;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",chf(a,b));
    return 0;
}
//（注：上述代码中阴影区域为需要填空的部分）