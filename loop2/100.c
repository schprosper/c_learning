#include <stdio.h>
int main()
{
    long long x;
    //scanf ("%d",&x);
    int cont = 0 ;
    for (x=2 ; cont <10 ; x++){
        int i;
        int isPrime = 1 ;
        for ( i = 2;i<x ;i++){
            if (x%i == 0)
            {
                isPrime = 0;//??
                break ;
            }
        }
        if (isPrime == 1 ){printf ("%d||",x);cont++;} 
    }


    printf("\n");  // 打印完所有素数后换行
    return 0;
}