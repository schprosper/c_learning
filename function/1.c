#include <stdio.h>//改进代码
int isPrime(int i)//定义了我们自己的函数！！
{
    int k;
    int ret = 1;
    for (k=2;k<i;k++)
    {
        if (i%k==0)
        {
            ret = 0;
            break;
        }
    }
    return ret;//单一出口
}
int main (){
    int m=2,n=10 ;
    int sum = 0 ;
    int cnt = 0 ;
    int i ;

    //scanf ()

    if (m==1){m=2;}
    for(i=m;i<n;i++)
    {
        //调用i是不是素数
        if (isPrime(i)){
        sum += i;
        cnt++;
        }
    }
    printf ("%d,%d",cnt,sum);
}