//统计每一种数字出现的次数：【0,9】的出现次数
//magic_number  复出现10，用const
#include <stdio.h>
void main ()
{
    const int number = 10;
    int x;
    int count[number] ;
    int i ;
    for (i=0;i<number;i++)
    {
        count[i] = 0;
    }
    scanf("%d",&x);

    while(x!=-1)
    {
        if(x>=0 && x<=9){
            count[x] ++;
        }
        else{
            printf("输入范围不对\n");
        }
        scanf ("%d",&x);//这一步必须最先想到
    }
    for (i=0;i<number;i++)
    {
        printf("%d输入了%d\t",i,count[i]);
    }
    




}