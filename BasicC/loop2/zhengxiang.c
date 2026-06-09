#include <stdio.h>//正向分解数字
//先逆向后正向，7000不行
//但是7000的0很难处理

//试位数，到直接确定位数
int main ()
{
    int a = 7815 ;
    int b;
    int digit = 1;
    int t=a;

    while(t>9){
        t /= 10;
        digit *=10;
    }
    printf("digit = %d\n",digit);

    while(digit>0)//从a>0到digit>0
    {
        b =a/digit;
        
        printf ("%d",b);
        a = a % digit;//这里必须是digit ,不是%10！
        if(digit > 9){printf(" ");}
        digit /= 10 ;//而且注意需要还原digit！！digit是逐步来的
    
        
        //printf("a=%d,b=%d,digit=%d\n",a,b,digit);
    }
    
}

/*
7000/1 -> 7000
1*10 -> 10
7000

7000 /1000 ->7
7000 %1000 ->a = 0
digit = 100
不应该结束但是a = 0
之后要输出0，这时候，b必然
 
*/