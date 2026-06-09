#include <stdio.h>//用素数去除以数字来判断他是不是素数（2就用上了。。。）

#define number 15
//看看挑选出来的那个数字是不是素数
int isprime(int x  ,int knowprimes[],int number0fKnownPrinmes)
{

    int ret = 1;
    int i ;
    for (i =0;i<number0fKnownPrinmes;i++)
    {
        if (x%knowprimes[i]==0)
        {
            ret = 0;
            break;
        }
    }
    return ret;
}


int main (void)
{
    
    int prime[number] = {2};
    int count = 1;
    int i = 3;
    while (count <number)
    {
        if (isprime(i,prime,count))
        {
            prime[count ++] = i; //1传导2进位，前人经验
        }
        //调试一下
            {
                printf("i=%d, \tcnt = %d\t",i,count);
                int i;
                for (i=0;i<number;i++){printf("%d\t",prime[i]);}
                printf("\n");
                
            }
        i++; 
    }
    //遍历数组，输出！
    for (i=0;i<number;i++)
    {
        printf("%d ",prime[i]);
        if ((i+1)%5){printf ("\t");}
        else {printf("\n");}
    }  
    getchar();
    return 0;
}