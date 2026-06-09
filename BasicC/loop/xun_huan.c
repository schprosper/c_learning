#include <stdio.h>
int main ( ){
    int x = 1 ;
    long long n = 0 ;
    scanf ("%d",n);
    do {
        n++;
        x /= 10;
        
        printf ("%lld\n",n);
    }while (x>0);
}