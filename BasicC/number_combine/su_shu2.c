#include<stdio.h>
#define maxNumber 25 //25以内的素数！

//没被滚过去的，说明以前没有因数可以整除他，所以他是素数！！
int main ()
{
    
    int isPrime[maxNumber];
    int i ;//第几个数字
    int x;
    //初始化数组
    for (i=0;i<maxNumber;i++)
    {
        isPrime[i] =1;
    }
    //
    for (x=2;x<maxNumber;x++)
    {
        if (isPrime[x])
        {
            for(i=2;i*x<maxNumber;i++)
            {
                isPrime[i*x] = 0;
            }
        }
    }
    for(i=2;i<maxNumber;i++)
    {
        if(isPrime[i]){
            printf("%d\t",i);
        }
    }
    printf ("\n");
    getchar();  // 按「回车」，控制台才会关闭; // 等待用户按「回车」，控制台才会关闭
}